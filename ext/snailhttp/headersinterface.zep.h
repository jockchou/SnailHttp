
extern zend_class_entry *snailhttp_headersinterface_ce;

ZEPHIR_INIT_CLASS(SnailHttp_HeadersInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_headersinterface_add, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_headersinterface_normalizekey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailhttp_headersinterface_method_entry) {
	PHP_ABSTRACT_ME(SnailHttp_HeadersInterface, add, arginfo_snailhttp_headersinterface_add)
	PHP_ABSTRACT_ME(SnailHttp_HeadersInterface, normalizeKey, arginfo_snailhttp_headersinterface_normalizekey)
	PHP_FE_END
};
