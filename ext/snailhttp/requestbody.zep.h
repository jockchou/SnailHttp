
extern zend_class_entry *snailhttp_requestbody_ce;

ZEPHIR_INIT_CLASS(SnailHttp_RequestBody);

PHP_METHOD(SnailHttp_RequestBody, __construct);

ZEPHIR_INIT_FUNCS(snailhttp_requestbody_method_entry) {
	PHP_ME(SnailHttp_RequestBody, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
