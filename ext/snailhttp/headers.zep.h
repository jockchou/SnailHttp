
extern zend_class_entry *snailhttp_headers_ce;

ZEPHIR_INIT_CLASS(SnailHttp_Headers);

PHP_METHOD(SnailHttp_Headers, createFromGlobals);
PHP_METHOD(SnailHttp_Headers, all);
PHP_METHOD(SnailHttp_Headers, set);
PHP_METHOD(SnailHttp_Headers, get);
PHP_METHOD(SnailHttp_Headers, getOriginalKey);
PHP_METHOD(SnailHttp_Headers, add);
PHP_METHOD(SnailHttp_Headers, has);
PHP_METHOD(SnailHttp_Headers, remove);
PHP_METHOD(SnailHttp_Headers, normalizeKey);
void zephir_init_static_properties_SnailHttp_Headers(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_headers_createfromglobals, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, globals, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_headers_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_headers_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, def)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_headers_getoriginalkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, def)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_headers_add, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_headers_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_headers_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_headers_normalizekey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailhttp_headers_method_entry) {
	PHP_ME(SnailHttp_Headers, createFromGlobals, arginfo_snailhttp_headers_createfromglobals, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(SnailHttp_Headers, all, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Headers, set, arginfo_snailhttp_headers_set, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Headers, get, arginfo_snailhttp_headers_get, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Headers, getOriginalKey, arginfo_snailhttp_headers_getoriginalkey, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Headers, add, arginfo_snailhttp_headers_add, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Headers, has, arginfo_snailhttp_headers_has, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Headers, remove, arginfo_snailhttp_headers_remove, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Headers, normalizeKey, arginfo_snailhttp_headers_normalizekey, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
