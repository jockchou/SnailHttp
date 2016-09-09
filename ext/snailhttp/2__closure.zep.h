
extern zend_class_entry *snailhttp_2__closure_ce;

ZEPHIR_INIT_CLASS(snailhttp_2__closure);

PHP_METHOD(snailhttp_2__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_2__closure___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailhttp_2__closure_method_entry) {
	PHP_ME(snailhttp_2__closure, __invoke, arginfo_snailhttp_2__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
