
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(snailhttp_1__closure) {

	ZEPHIR_REGISTER_CLASS(snailhttp, 1__closure, snailhttp, 1__closure, snailhttp_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(snailhttp_1__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *match_param = NULL, *_0;
	zval *match = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &match_param);

	if (!match_param) {
		ZEPHIR_INIT_VAR(match);
		array_init(match);
	} else {
		zephir_get_arrval(match, match_param);
	}


	zephir_array_fetch_long(&_0, match, 0, PH_NOISY | PH_READONLY, "snailhttp/Uri.zep", 309 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("rawurlencode", NULL, 21, _0);
	zephir_check_call_status();
	RETURN_MM();

}

