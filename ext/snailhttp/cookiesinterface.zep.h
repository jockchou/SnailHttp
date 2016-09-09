
extern zend_class_entry *snailhttp_cookiesinterface_ce;

ZEPHIR_INIT_CLASS(SnailHttp_CookiesInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_cookiesinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, def)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_cookiesinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_cookiesinterface_parseheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailhttp_cookiesinterface_method_entry) {
	PHP_ABSTRACT_ME(SnailHttp_CookiesInterface, get, arginfo_snailhttp_cookiesinterface_get)
	PHP_ABSTRACT_ME(SnailHttp_CookiesInterface, set, arginfo_snailhttp_cookiesinterface_set)
	PHP_ABSTRACT_ME(SnailHttp_CookiesInterface, toHeaders, NULL)
	ZEND_FENTRY(parseHeader, NULL, arginfo_snailhttp_cookiesinterface_parseheader, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
