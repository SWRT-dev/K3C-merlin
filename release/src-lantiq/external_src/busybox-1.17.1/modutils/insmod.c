/* vi: set sw=4 ts=4: */
/*
 * Mini insmod implementation for busybox
 *
 * Copyright (C) 2008 Timo Teras <timo.teras@iki.fi>
 *
 * Licensed under GPLv2 or later, see file LICENSE in this tarball for details.
 */

#include "libbb.h"
#include "modutils.h"
#include <sys/utsname.h>
#ifndef CONFIG_FEATURE_2_4_MODULES
#include <sys/mman.h>
#include <asm/unistd.h>
#include <sys/syscall.h>
#endif

static char *g_filename = NULL;

static int FAST_FUNC check_module_name_match(const char *filename, struct stat *statbuf,
				   void *userdata, int depth)
{
	char *fullname = (char *) userdata;
	char *tmp;

	if (fullname[0] == '\0')
		return FALSE;

	tmp = bb_get_last_path_component_nostrip(filename);
	if (strcmp(tmp, fullname) == 0) {
		/* Stop searching if we find a match */
		g_filename = xstrdup(filename);
		return FALSE;
	}

	return TRUE;
}

static int find_module(char *filename)
{
	char *module_dir, real_module_dir[FILENAME_MAX];
	int len, slen, ret = ENOENT, k_version;
	struct utsname myuname;
	const char *suffix;
	struct stat st;

	/* check the kernel version */
	if (uname(&myuname) != 0)
		return EINVAL;

	k_version = myuname.release[2] - '0';
#if ENABLE_FEATURE_2_4_MODULES
	if ((myuname.release[0] == '2') && (k_version <= 4))
		suffix = ".o";
	else
#endif
		suffix = ".ko";

	len = strlen(filename);
	slen = strlen(suffix);

	/* check for suffix and absolute path first */
	if ((len < slen + 2) || (strcmp(filename + len - slen, suffix) != 0)) {
		filename = xasprintf("%s%s", filename, suffix);
	} else {
		filename = strdup(filename);
		if ((stat(filename, &st) == 0) && S_ISREG(st.st_mode)) {
			g_filename = filename;
			return 0;
		}
		free(filename);
		return ENOENT;
	}

	/* next: scan /lib/modules/<release> */
	/* Jump through hoops in case /lib/modules/`uname -r`
	* is a symlink.  We do not want recursive_action to
	* follow symlinks, but we do want to follow the
	* /lib/modules/`uname -r` dir, So resolve it ourselves
	* if it is a link... */
	module_dir = concat_path_file(CONFIG_DEFAULT_MODULES_DIR, myuname.release);
	if (realpath(module_dir, real_module_dir) != NULL) {
		free(module_dir);
		module_dir = real_module_dir;
	}

	recursive_action(module_dir, ACTION_RECURSE,
		check_module_name_match, 0, filename, 0);

	/* Check if we have a complete path */
	if (g_filename == NULL)
		goto done;

	if ((stat(g_filename, &st) == 0) && S_ISREG(st.st_mode))
		ret = 0;
	else
		free(g_filename);

done:
	free(filename);

	return ret;
}

/* 2.6 style insmod has no options and required filename
 * (not module name - .ko can't be omitted) */

//usage:#define insmod_trivial_usage
//usage:	IF_FEATURE_2_4_MODULES("[OPTIONS] MODULE ")
//usage:	IF_NOT_FEATURE_2_4_MODULES("FILE ")
//usage:	"[symbol=value]..."
//usage:#define insmod_full_usage "\n\n"
//usage:       "Load the specified kernel modules into the kernel"
//usage:	IF_FEATURE_2_4_MODULES( "\n"
//usage:     "\nOptions:"
//usage:     "\n	-f	Force module to load into the wrong kernel version"
//usage:     "\n	-k	Make module autoclean-able"
//usage:     "\n	-v	Verbose"
//usage:     "\n	-q	Quiet"
//usage:     "\n	-L	Lock: prevent simultaneous loads"
//usage:	IF_FEATURE_INSMOD_LOAD_MAP(
//usage:     "\n	-m	Output load map to stdout"
//usage:	)
//usage:     "\n	-x	Don't export externs"
//usage:	)

int insmod_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
int insmod_main(int argc UNUSED_PARAM, char **argv)
{
	char *filename;
	int rc;

	/* Compat note:
	 * 2.6 style insmod has no options and required filename
	 * (not module name - .ko can't be omitted).
	 * 2.4 style insmod can take module name without .o
	 * and performs module search in default directories
	 * or in $MODPATH.
	 */

	IF_FEATURE_2_4_MODULES(
		getopt32(argv, INSMOD_OPTS INSMOD_ARGS);
		argv += optind - 1;
	);

	filename = *++argv;
	if (!filename)
		bb_show_usage();

	rc = find_module(filename);
	if (rc || (g_filename == NULL))
			goto done;

	rc = bb_init_module(g_filename, parse_cmdline_module_options(argv));
	if (rc)
		bb_error_msg("can't insert '%s': %s", filename, moderror(rc));
	free (g_filename);

done:
	return rc;
}
