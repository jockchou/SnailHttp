
extern zend_class_entry *snailhttp_message_ce;

ZEPHIR_INIT_CLASS(SnailHttp_Message);

PHP_METHOD(SnailHttp_Message, getProtocolVersion);
PHP_METHOD(SnailHttp_Message, withProtocolVersion);
PHP_METHOD(SnailHttp_Message, getHeaders);
PHP_METHOD(SnailHttp_Message, hasHeader);
PHP_METHOD(SnailHttp_Message, getHeader);
PHP_METHOD(SnailHttp_Message, getHeaderLine);
PHP_METHOD(SnailHttp_Message, withHeader);
PHP_METHOD(SnailHttp_Message, withAddedHeader);
PHP_METHOD(SnailHttp_Message, withoutHeader);
PHP_METHOD(SnailHttp_Message, getBody);
PHP_METHOD(SnailHttp_Message, withBody);
void zephir_init_static_properties_SnailHttp_Message(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_message_withprotocolversion, 0, 0, 1)
	ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_message_hasheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_message_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_message_getheaderline, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_message_withheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_message_withaddedheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_message_withoutheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_message_withbody, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailhttp_message_method_entry) {
	PHP_ME(SnailHttp_Message, getProtocolVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Message, withProtocolVersion, arginfo_snailhttp_message_withprotocolversion, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Message, getHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Message, hasHeader, arginfo_snailhttp_message_hasheader, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Message, getHeader, arginfo_snailhttp_message_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Message, getHeaderLine, arginfo_snailhttp_message_getheaderline, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Message, withHeader, arginfo_snailhttp_message_withheader, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Message, withAddedHeader, arginfo_snailhttp_message_withaddedheader, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Message, withoutHeader, arginfo_snailhttp_message_withoutheader, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Message, getBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Message, withBody, arginfo_snailhttp_message_withbody, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
