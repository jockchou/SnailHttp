
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


/**
 * Provides a PSR-7 implementation of a reusable raw request body
 */
ZEPHIR_INIT_CLASS(SnailHttp_RequestBody) {

	ZEPHIR_REGISTER_CLASS_EX(SnailHttp, RequestBody, snailhttp, requestbody, snailhttp_body_ce, snailhttp_requestbody_method_entry, 0);

	return SUCCESS;

}

/**
 * Create a new RequestBody.
 */
PHP_METHOD(SnailHttp_RequestBody, __construct) {

	zval *stream = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "php://temp", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "w+", 0);
	ZEPHIR_CALL_FUNCTION(&stream, "fopen", &_2, 27, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "php://input", 0);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "r", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "fopen", &_2, 27, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "stream_copy_to_stream", NULL, 28, _3, stream);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "rewind", NULL, 29, stream);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, snailhttp_requestbody_ce, this_ptr, "__construct", &_4, 30, stream);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

