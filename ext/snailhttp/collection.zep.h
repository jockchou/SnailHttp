
extern zend_class_entry *snailhttp_collection_ce;

ZEPHIR_INIT_CLASS(SnailHttp_Collection);

PHP_METHOD(SnailHttp_Collection, __construct);
PHP_METHOD(SnailHttp_Collection, set);
PHP_METHOD(SnailHttp_Collection, get);
PHP_METHOD(SnailHttp_Collection, replace);
PHP_METHOD(SnailHttp_Collection, all);
PHP_METHOD(SnailHttp_Collection, keys);
PHP_METHOD(SnailHttp_Collection, has);
PHP_METHOD(SnailHttp_Collection, remove);
PHP_METHOD(SnailHttp_Collection, clear);
PHP_METHOD(SnailHttp_Collection, offsetExists);
PHP_METHOD(SnailHttp_Collection, offsetGet);
PHP_METHOD(SnailHttp_Collection, offsetSet);
PHP_METHOD(SnailHttp_Collection, offsetUnset);
PHP_METHOD(SnailHttp_Collection, count);
PHP_METHOD(SnailHttp_Collection, getIterator);
zend_object_value zephir_init_properties_SnailHttp_Collection(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_collection___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, items, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_collection_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_collection_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, def)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_collection_replace, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, items, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_collection_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_collection_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_collection_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_collection_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_collection_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_collection_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailhttp_collection_method_entry) {
	PHP_ME(SnailHttp_Collection, __construct, arginfo_snailhttp_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(SnailHttp_Collection, set, arginfo_snailhttp_collection_set, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Collection, get, arginfo_snailhttp_collection_get, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Collection, replace, arginfo_snailhttp_collection_replace, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Collection, all, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Collection, keys, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Collection, has, arginfo_snailhttp_collection_has, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Collection, remove, arginfo_snailhttp_collection_remove, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Collection, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Collection, offsetExists, arginfo_snailhttp_collection_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Collection, offsetGet, arginfo_snailhttp_collection_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Collection, offsetSet, arginfo_snailhttp_collection_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Collection, offsetUnset, arginfo_snailhttp_collection_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Collection, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Collection, getIterator, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
