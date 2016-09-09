
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
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(snailhttp_3__closure) {

	ZEPHIR_REGISTER_CLASS(snailhttp, 3__closure, snailhttp, 3__closure, snailhttp_3__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(snailhttp_3__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *input, *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input);



	ZEPHIR_INIT_VAR(data);
	ZVAL_NULL(data);
	ZEPHIR_MAKE_REF(data);
	ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 26, input, data);
	ZEPHIR_UNREF(data);
	zephir_check_call_status();
	RETURN_CCTOR(data);

}

