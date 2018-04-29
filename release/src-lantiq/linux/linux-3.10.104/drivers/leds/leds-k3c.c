#include <linux/slab.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/of_platform.h>
#include <linux/of_gpio.h>
#include <linux/mutex.h>
#include <linux/gpio.h>
#include <linux/leds.h>
#include <linux/io.h>
#include <linux/clk.h>
#include <linux/err.h>
#include <lantiq_soc.h>
#include <lantiq_timer.h>
#include <linux/of_gpio.h>
#include <linux/klogging.h>

struct gpio_led leds[] = {
    {"lan1", "netdev", 6, 0, 0, 0},
    {"lan2", "netdev", 5, 0, 0, 0},
    {"lan3", "netdev", 9, 0, 0, 0},
    {"wan", "netdev", 14, 0, 0, 0},
};

struct gpio_led_platform_data pdata = {
    .num_leds = ARRAY_SIZE(leds),
    .leds = leds,
};


struct platform_device k3cled = {
    .name = "leds-gpio", 
    .id = -1,
    .dev = {
        .platform_data = &pdata,
    },
};

module_driver(k3cled, platform_device_register, platform_device_unregister);
MODULE_AUTHOR("paldier");
MODULE_DESCRIPTION("K3C LED driver");
MODULE_LICENSE("GPL");
