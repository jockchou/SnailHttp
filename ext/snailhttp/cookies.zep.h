
extern zend_class_entry *snailhttp_cookies_ce;

ZEPHIR_INIT_CLASS(SnailHttp_Cookies);

PHP_METHOD(SnailHttp_Cookies, __construct);
PHP_METHOD(SnailHttp_Cookies, setDefaults);
PHP_METHOD(SnailHttp_Cookies, get);
PHP_METHOD(SnailHttp_Cookies, set);
PHP_METHOD(SnailHttp_Cookies, toHeaders);
PHP_METHOD(SnailHttp_Cookies, toHeader);
PHP_METHOD(SnailHttp_Cookies, parseHeader);
zend_object_value zephir_init_properties_SnailHttp_Cookies(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_cookies___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, cookies, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_cookies_setdefaults, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, settings, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_cookies_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, def)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_cookies_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_cookies_toheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, properties, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_cookies_parseheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailhttp_cookies_method_entry) {
	PHP_ME(SnailHttp_Cookies, __construct, arginfo_snailhttp_cookies___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(SnailHttp_Cookies, setDefaults, arginfo_snailhttp_cookies_setdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Cookies, get, arginfo_snailhttp_cookies_get, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Cookies, set, arginfo_snailhttp_cookies_set, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Cookies, toHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Cookies, toHeader, arginfo_snailhttp_cookies_toheader, ZEND_ACC_PROTECTED)
	PHP_ME(SnailHttp_Cookies, parseHeader, arginfo_snailhttp_cookies_parseheader, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
