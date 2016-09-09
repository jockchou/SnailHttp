
extern zend_class_entry *snailhttp_environment_ce;

ZEPHIR_INIT_CLASS(SnailHttp_Environment);

PHP_METHOD(SnailHttp_Environment, mock);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_environment_mock, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, userData, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailhttp_environment_method_entry) {
	PHP_ME(SnailHttp_Environment, mock, arginfo_snailhttp_environment_mock, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
