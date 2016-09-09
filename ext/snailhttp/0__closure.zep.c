
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(snailhttp_0__closure) {

	ZEPHIR_REGISTER_CLASS(snailhttp, 0__closure, snailhttp, 0__closure, snailhttp_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(snailhttp_0__closure, __invoke) {

	zval *input;

	zephir_fetch_params(0, 1, 0, &input);



	zephir_json_decode(return_value, &(return_value), input, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
	return;

}

