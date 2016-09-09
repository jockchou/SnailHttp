
extern zend_class_entry *snailhttp_factoryinterface_ce;

ZEPHIR_INIT_CLASS(SnailHttp_FactoryInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_factoryinterface_makerequest, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, globals, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_factoryinterface_makeuri, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, globals, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_factoryinterface_makeheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, globals, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailhttp_factoryinterface_method_entry) {
	PHP_ABSTRACT_ME(SnailHttp_FactoryInterface, makeRequest, arginfo_snailhttp_factoryinterface_makerequest)
	PHP_ABSTRACT_ME(SnailHttp_FactoryInterface, makeUri, arginfo_snailhttp_factoryinterface_makeuri)
	PHP_ABSTRACT_ME(SnailHttp_FactoryInterface, makeHeaders, arginfo_snailhttp_factoryinterface_makeheaders)
	PHP_ABSTRACT_ME(SnailHttp_FactoryInterface, makeBody, NULL)
	PHP_FE_END
};
