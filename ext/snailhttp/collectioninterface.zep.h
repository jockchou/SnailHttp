
extern zend_class_entry *snailhttp_collectioninterface_ce;

ZEPHIR_INIT_CLASS(SnailHttp_CollectionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_collectioninterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_collectioninterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, def)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_collectioninterface_replace, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, items, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_collectioninterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_collectioninterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailhttp_collectioninterface_method_entry) {
	PHP_ABSTRACT_ME(SnailHttp_CollectionInterface, set, arginfo_snailhttp_collectioninterface_set)
	PHP_ABSTRACT_ME(SnailHttp_CollectionInterface, get, arginfo_snailhttp_collectioninterface_get)
	PHP_ABSTRACT_ME(SnailHttp_CollectionInterface, replace, arginfo_snailhttp_collectioninterface_replace)
	PHP_ABSTRACT_ME(SnailHttp_CollectionInterface, all, NULL)
	PHP_ABSTRACT_ME(SnailHttp_CollectionInterface, has, arginfo_snailhttp_collectioninterface_has)
	PHP_ABSTRACT_ME(SnailHttp_CollectionInterface, remove, arginfo_snailhttp_collectioninterface_remove)
	PHP_ABSTRACT_ME(SnailHttp_CollectionInterface, clear, NULL)
	PHP_FE_END
};
