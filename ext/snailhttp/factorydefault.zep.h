
extern zend_class_entry *snailhttp_factorydefault_ce;

ZEPHIR_INIT_CLASS(SnailHttp_FactoryDefault);

PHP_METHOD(SnailHttp_FactoryDefault, makeRequest);
PHP_METHOD(SnailHttp_FactoryDefault, makeUri);
PHP_METHOD(SnailHttp_FactoryDefault, makeHeaders);
PHP_METHOD(SnailHttp_FactoryDefault, makeBody);
void zephir_init_static_properties_SnailHttp_FactoryDefault(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_factorydefault_makerequest, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, globals, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_factorydefault_makeuri, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, globals, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_factorydefault_makeheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, globals, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailhttp_factorydefault_method_entry) {
	PHP_ME(SnailHttp_FactoryDefault, makeRequest, arginfo_snailhttp_factorydefault_makerequest, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_FactoryDefault, makeUri, arginfo_snailhttp_factorydefault_makeuri, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_FactoryDefault, makeHeaders, arginfo_snailhttp_factorydefault_makeheaders, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_FactoryDefault, makeBody, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
