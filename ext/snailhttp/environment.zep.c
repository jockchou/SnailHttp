
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
#include "kernel/memory.h"
#include "kernel/time.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(SnailHttp_Environment) {

	ZEPHIR_REGISTER_CLASS_EX(SnailHttp, Environment, snailhttp, environment, snailhttp_collection_ce, snailhttp_environment_method_entry, 0);

	return SUCCESS;

}

/**
 * Create mock environment
 *
 * @param  array $userData Array of custom environment keys and values
 *
 * @return array
 */
PHP_METHOD(SnailHttp_Environment, mock) {

	zval *userData_param = NULL, *_1 = NULL;
	zval *userData = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &userData_param);

	if (!userData_param) {
		ZEPHIR_INIT_VAR(userData);
		array_init(userData);
	} else {
		zephir_get_arrval(userData, userData_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 15, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("SERVER_PROTOCOL"), SL("HTTP/1.1"), 1);
	add_assoc_stringl_ex(_0, SS("REQUEST_METHOD"), SL("GET"), 1);
	add_assoc_stringl_ex(_0, SS("SCRIPT_NAME"), SL(""), 1);
	add_assoc_stringl_ex(_0, SS("REQUEST_URI"), SL(""), 1);
	add_assoc_stringl_ex(_0, SS("QUERY_STRING"), SL(""), 1);
	add_assoc_stringl_ex(_0, SS("SERVER_NAME"), SL("localhost"), 1);
	add_assoc_long_ex(_0, SS("SERVER_PORT"), 80);
	add_assoc_stringl_ex(_0, SS("HTTP_HOST"), SL("localhost"), 1);
	add_assoc_stringl_ex(_0, SS("HTTP_ACCEPT"), SL("text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8"), 1);
	add_assoc_stringl_ex(_0, SS("HTTP_ACCEPT_LANGUAGE"), SL("en-US,en;q=0.8"), 1);
	add_assoc_stringl_ex(_0, SS("HTTP_ACCEPT_CHARSET"), SL("ISO-8859-1,utf-8;q=0.7,*;q=0.3"), 1);
	add_assoc_stringl_ex(_0, SS("HTTP_USER_AGENT"), SL("Snail Framework"), 1);
	add_assoc_stringl_ex(_0, SS("REMOTE_ADDR"), SL("127.0.0.1"), 1);
	ZEPHIR_INIT_VAR(_1);
	zephir_time(_1);
	zephir_array_update_string(&_0, SL("REQUEST_TIME"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	zephir_microtime(_1, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	zephir_array_update_string(&_0, SL("REQUEST_TIME_FLOAT"), &_1, PH_COPY | PH_SEPARATE);
	zephir_fast_array_merge(return_value, &(_0), &(userData) TSRMLS_CC);
	RETURN_MM();

}

