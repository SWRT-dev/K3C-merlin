struct qmi_uim_get_supported_messages_response {
	struct {
	} set;
	struct {
		unsigned int list_n;
		uint8_t *list;
	} data;
};

struct qmi_uim_read_transparent_request {
	struct {
		unsigned int session_information : 1;
		unsigned int file : 1;
		unsigned int read_information : 1;
		unsigned int response_in_indication_token : 1;
		unsigned int encrypt_data : 1;
	} set;
	struct {
		struct {
			QmiUimSessionType session_type;
			char *application_identifier;
		} session_information;
		struct {
			uint16_t file_id;
			unsigned int file_path_n;
			uint8_t *file_path;
		} file;
		struct {
			uint16_t offset;
			uint16_t length;
		} read_information;
		uint32_t response_in_indication_token;
		bool encrypt_data;
	} data;
};

struct qmi_uim_read_transparent_response {
	struct {
		unsigned int card_result : 1;
		unsigned int response_in_indication_token : 1;
		unsigned int encrypted_data : 1;
	} set;
	struct {
		struct {
			uint8_t sw1;
			uint8_t sw2;
		} card_result;
		unsigned int read_result_n;
		uint8_t *read_result;
		uint32_t response_in_indication_token;
		bool encrypted_data;
	} data;
};

struct qmi_uim_read_record_request {
	struct {
		unsigned int session_information : 1;
		unsigned int file : 1;
		unsigned int record : 1;
		unsigned int last_record : 1;
		unsigned int response_in_indication_token : 1;
	} set;
	struct {
		struct {
			QmiUimSessionType session_type;
			char *application_identifier;
		} session_information;
		struct {
			uint16_t file_id;
			unsigned int file_path_n;
			uint8_t *file_path;
		} file;
		struct {
			uint16_t record_number;
			uint16_t record_length;
		} record;
		uint16_t last_record;
		uint32_t response_in_indication_token;
	} data;
};

struct qmi_uim_read_record_response {
	struct {
		unsigned int card_result : 1;
		unsigned int response_in_indication_token : 1;
	} set;
	struct {
		struct {
			uint8_t sw1;
			uint8_t sw2;
		} card_result;
		unsigned int read_result_n;
		uint8_t *read_result;
		unsigned int additional_read_result_n;
		uint8_t *additional_read_result;
		uint32_t response_in_indication_token;
	} data;
};

struct qmi_uim_get_file_attributes_request {
	struct {
		unsigned int session_information : 1;
		unsigned int file : 1;
		unsigned int response_in_indication_token : 1;
	} set;
	struct {
		struct {
			QmiUimSessionType session_type;
			char *application_identifier;
		} session_information;
		struct {
			uint16_t file_id;
			unsigned int file_path_n;
			uint8_t *file_path;
		} file;
		uint32_t response_in_indication_token;
	} data;
};

struct qmi_uim_get_file_attributes_response {
	struct {
		unsigned int card_result : 1;
		unsigned int file_attributes : 1;
		unsigned int response_in_indication_token : 1;
	} set;
	struct {
		struct {
			uint8_t sw1;
			uint8_t sw2;
		} card_result;
		struct {
			uint16_t file_size;
			uint16_t file_id;
			QmiUimFileType file_type;
			uint16_t record_size;
			uint16_t record_count;
			QmiUimSecurityAttributeLogic read_security_attributes_logic;
			QmiUimSecurityAttribute read_security_attributes;
			QmiUimSecurityAttributeLogic write_security_attributes_logic;
			QmiUimSecurityAttribute write_security_attributes;
			QmiUimSecurityAttributeLogic increase_security_attributes_logic;
			QmiUimSecurityAttribute increase_security_attributes;
			QmiUimSecurityAttributeLogic deactivate_security_attributes_logic;
			QmiUimSecurityAttribute deactivate_security_attributes;
			QmiUimSecurityAttributeLogic activate_security_attributes_logic;
			QmiUimSecurityAttribute activate_security_attributes;
			unsigned int raw_data_n;
			uint8_t *raw_data;
		} file_attributes;
		uint32_t response_in_indication_token;
	} data;
};

struct qmi_uim_set_pin_protection_request {
	struct {
		unsigned int session_information : 1;
		unsigned int info : 1;
		unsigned int response_in_indication_token : 1;
	} set;
	struct {
		struct {
			QmiUimSessionType session_type;
			char *application_identifier;
		} session_information;
		struct {
			QmiUimPinId pin_id;
			bool pin_enabled;
			char *pin_value;
		} info;
		uint32_t response_in_indication_token;
	} data;
};

struct qmi_uim_set_pin_protection_response {
	struct {
		unsigned int retries_remaining : 1;
		unsigned int response_in_indication_token : 1;
	} set;
	struct {
		struct {
			uint8_t verify_retries_left;
			uint8_t unblock_retries_left;
		} retries_remaining;
		uint32_t response_in_indication_token;
	} data;
};

struct qmi_uim_verify_pin_request {
	struct {
		unsigned int session_information : 1;
		unsigned int info : 1;
		unsigned int response_in_indication_token : 1;
	} set;
	struct {
		struct {
			QmiUimSessionType session_type;
			char *application_identifier;
		} session_information;
		struct {
			QmiUimPinId pin_id;
			char *pin_value;
		} info;
		uint32_t response_in_indication_token;
	} data;
};

struct qmi_uim_verify_pin_response {
	struct {
		unsigned int retries_remaining : 1;
		unsigned int response_in_indication_token : 1;
		unsigned int card_result : 1;
	} set;
	struct {
		struct {
			uint8_t verify_retries_left;
			uint8_t unblock_retries_left;
		} retries_remaining;
		uint32_t response_in_indication_token;
		struct {
			uint8_t sw1;
			uint8_t sw2;
		} card_result;
	} data;
};

struct qmi_uim_unblock_pin_request {
	struct {
		unsigned int session_information : 1;
		unsigned int info : 1;
		unsigned int response_in_indication_token : 1;
	} set;
	struct {
		struct {
			QmiUimSessionType session_type;
			char *application_identifier;
		} session_information;
		struct {
			QmiUimPinId pin_id;
			char *puk;
			char *new_pin;
		} info;
		uint32_t response_in_indication_token;
	} data;
};

struct qmi_uim_unblock_pin_response {
	struct {
		unsigned int retries_remaining : 1;
		unsigned int response_in_indication_token : 1;
		unsigned int card_result : 1;
	} set;
	struct {
		struct {
			uint8_t verify_retries_left;
			uint8_t unblock_retries_left;
		} retries_remaining;
		uint32_t response_in_indication_token;
		struct {
			uint8_t sw1;
			uint8_t sw2;
		} card_result;
	} data;
};

struct qmi_uim_change_pin_request {
	struct {
		unsigned int session_information : 1;
		unsigned int info : 1;
		unsigned int response_in_indication_token : 1;
	} set;
	struct {
		struct {
			QmiUimSessionType session_type;
			char *application_identifier;
		} session_information;
		struct {
			QmiUimPinId pin_id;
			char *old_pin;
			char *new_pin;
		} info;
		uint32_t response_in_indication_token;
	} data;
};

struct qmi_uim_change_pin_response {
	struct {
		unsigned int retries_remaining : 1;
		unsigned int response_in_indication_token : 1;
		unsigned int card_result : 1;
	} set;
	struct {
		struct {
			uint8_t verify_retries_left;
			uint8_t unblock_retries_left;
		} retries_remaining;
		uint32_t response_in_indication_token;
		struct {
			uint8_t sw1;
			uint8_t sw2;
		} card_result;
	} data;
};

struct qmi_uim_get_card_status_response {
	struct {
		unsigned int card_status : 1;
	} set;
	struct {
		struct {
			uint16_t index_gw_primary;
			uint16_t index_1x_primary;
			uint16_t index_gw_secondary_;
			uint16_t index_1x_secondary;
			unsigned int cards_n;
			struct {
				QmiUimCardState card_state;
				QmiUimPinState upin_state;
				uint8_t upin_retries;
				uint8_t upuk_retries;
				QmiUimCardError error_code;
				unsigned int applications_n;
				struct {
					QmiUimCardApplicationType type;
					QmiUimCardApplicationState state;
					QmiUimCardApplicationPersonalizationState personalization_state;
					QmiUimCardApplicationPersonalizationFeature personalization_feature;
					uint8_t personalization_retries;
					uint8_t personalization_unblock_retries;
					unsigned int application_identifier_value_n;
					uint8_t *application_identifier_value;
					bool upin_replaces_pin1;
					QmiUimPinState pin1_state;
					uint8_t pin1_retries;
					uint8_t puk1_retries;
					QmiUimPinState pin2_state;
					uint8_t pin2_retries;
					uint8_t puk2_retries;
				} *applications;
			} *cards;
		} card_status;
	} data;
};

int qmi_set_uim_reset_request(struct qmi_msg *msg);
int qmi_parse_uim_reset_response(struct qmi_msg *msg);

int qmi_set_uim_get_supported_messages_request(struct qmi_msg *msg);
int qmi_parse_uim_get_supported_messages_response(struct qmi_msg *msg, struct qmi_uim_get_supported_messages_response *res);

int qmi_set_uim_read_transparent_request(struct qmi_msg *msg, struct qmi_uim_read_transparent_request *req);
int qmi_parse_uim_read_transparent_response(struct qmi_msg *msg, struct qmi_uim_read_transparent_response *res);

int qmi_set_uim_read_record_request(struct qmi_msg *msg, struct qmi_uim_read_record_request *req);
int qmi_parse_uim_read_record_response(struct qmi_msg *msg, struct qmi_uim_read_record_response *res);

int qmi_set_uim_get_file_attributes_request(struct qmi_msg *msg, struct qmi_uim_get_file_attributes_request *req);
int qmi_parse_uim_get_file_attributes_response(struct qmi_msg *msg, struct qmi_uim_get_file_attributes_response *res);

int qmi_set_uim_set_pin_protection_request(struct qmi_msg *msg, struct qmi_uim_set_pin_protection_request *req);
int qmi_parse_uim_set_pin_protection_response(struct qmi_msg *msg, struct qmi_uim_set_pin_protection_response *res);

int qmi_set_uim_verify_pin_request(struct qmi_msg *msg, struct qmi_uim_verify_pin_request *req);
int qmi_parse_uim_verify_pin_response(struct qmi_msg *msg, struct qmi_uim_verify_pin_response *res);

int qmi_set_uim_unblock_pin_request(struct qmi_msg *msg, struct qmi_uim_unblock_pin_request *req);
int qmi_parse_uim_unblock_pin_response(struct qmi_msg *msg, struct qmi_uim_unblock_pin_response *res);

int qmi_set_uim_change_pin_request(struct qmi_msg *msg, struct qmi_uim_change_pin_request *req);
int qmi_parse_uim_change_pin_response(struct qmi_msg *msg, struct qmi_uim_change_pin_response *res);

int qmi_set_uim_get_card_status_request(struct qmi_msg *msg);
int qmi_parse_uim_get_card_status_response(struct qmi_msg *msg, struct qmi_uim_get_card_status_response *res);

