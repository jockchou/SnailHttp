
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
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(SnailHttp_Headers) {

	ZEPHIR_REGISTER_CLASS_EX(SnailHttp, Headers, snailhttp, headers, snailhttp_collection_ce, snailhttp_headers_method_entry, 0);

	zend_declare_property_null(snailhttp_headers_ce, SL("special"), ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(snailhttp_headers_ce TSRMLS_CC, 1, snailhttp_headersinterface_ce);
	return SUCCESS;

}

PHP_METHOD(SnailHttp_Headers, createFromGlobals) {

	zend_bool _5$$3;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *globals_param = NULL, *key = NULL, *value = NULL, *env = NULL, *data = NULL, **_2, *_3$$3 = NULL, *_4$$3, _6$$3 = zval_used_for_init;
	zval *globals = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &globals_param);

	zephir_get_arrval(globals, globals_param);


	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_INIT_VAR(env);
	object_init_ex(env, snailhttp_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, env, "__construct", NULL, 8, globals);
	zephir_check_call_status();
	zephir_is_iterable(env, &_1, &_0, 0, 0, "snailhttp/Headers.zep", 31);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_INIT_NVAR(_3$$3);
		zephir_fast_strtoupper(_3$$3, key);
		ZEPHIR_CPY_WRT(key, _3$$3);
		_4$$3 = zephir_fetch_static_property_ce(snailhttp_headers_ce, SL("special") TSRMLS_CC);
		_5$$3 = zephir_array_isset(_4$$3, key);
		if (!(_5$$3)) {
			ZEPHIR_SINIT_NVAR(_6$$3);
			ZVAL_STRING(&_6$$3, "HTTP_", 0);
			ZEPHIR_INIT_NVAR(_3$$3);
			zephir_fast_strpos(_3$$3, key, &_6$$3, 0 );
			_5$$3 = ZEPHIR_IS_LONG_IDENTICAL(_3$$3, 0);
		}
		if (_5$$3) {
			if (!ZEPHIR_IS_STRING_IDENTICAL(key, "HTTP_CONTENT_LENGTH")) {
				zephir_array_update_zval(&data, key, &value, PH_COPY | PH_SEPARATE);
			}
		}
	}
	object_init_ex(return_value, snailhttp_headers_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 8, data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Headers, all) {

	HashTable *_3;
	HashPosition _2;
	zval *props = NULL, *out = NULL, *all = NULL, *_1 = NULL, **_4, *_5$$3, *_6$$3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(out);
	array_init(out);
	ZEPHIR_CALL_PARENT(&all, snailhttp_headers_ce, this_ptr, "all", &_0, 9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_is_iterable(all, &_3, &_2, 0, 0, "snailhttp/Headers.zep", 44);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(_1, _3, _2);
		ZEPHIR_GET_HVALUE(props, _4);
		zephir_array_fetch_string(&_5$$3, props, SL("value"), PH_NOISY | PH_READONLY, "snailhttp/Headers.zep", 41 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_6$$3);
		zephir_array_fetch_string(&_6$$3, props, SL("originalKey"), PH_NOISY, "snailhttp/Headers.zep", 41 TSRMLS_CC);
		zephir_array_update_zval(&out, _6$$3, &_5$$3, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(out);

}

PHP_METHOD(SnailHttp_Headers, set) {

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *key_param = NULL, *value = NULL, *_1 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);
	ZEPHIR_SEPARATE_PARAM(value);


	if (!(Z_TYPE_P(value) == IS_ARRAY)) {
		ZEPHIR_INIT_NVAR(value);
		zephir_create_array(value, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(value, value);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "normalizekey", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("value"), &value, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("originalKey"), &key, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_PARENT(NULL, snailhttp_headers_ce, this_ptr, "set", &_0, 10, _1, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Headers, get) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *def = NULL, *_0 = NULL, *_1$$3 = NULL, *_3$$3 = NULL, *_4$$3;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &def);

	zephir_get_strval(key, key_param);
	if (!def) {
		def = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, key);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "normalizekey", NULL, 0, key);
		zephir_check_call_status();
		ZEPHIR_CALL_PARENT(&_1$$3, snailhttp_headers_ce, this_ptr, "get", &_2, 11, _3$$3);
		zephir_check_call_status();
		zephir_array_fetch_string(&_4$$3, _1$$3, SL("value"), PH_NOISY | PH_READONLY, "snailhttp/Headers.zep", 64 TSRMLS_CC);
		RETURN_CTOR(_4$$3);
	}
	RETVAL_ZVAL(def, 1, 0);
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Headers, getOriginalKey) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *def = NULL, *_0 = NULL, *_1$$3 = NULL, *_3$$3 = NULL, *_4$$3;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &def);

	zephir_get_strval(key, key_param);
	if (!def) {
		def = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, key);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "normalizekey", NULL, 0, key);
		zephir_check_call_status();
		ZEPHIR_CALL_PARENT(&_1$$3, snailhttp_headers_ce, this_ptr, "get", &_2, 11, _3$$3);
		zephir_check_call_status();
		zephir_array_fetch_string(&_4$$3, _1$$3, SL("originalKey"), PH_NOISY | PH_READONLY, "snailhttp/Headers.zep", 74 TSRMLS_CC);
		RETURN_CTOR(_4$$3);
	}
	RETVAL_ZVAL(def, 1, 0);
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Headers, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *oldValues = NULL, *newValues = NULL, *_0, *_1, *_2 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	ZEPHIR_CALL_METHOD(&oldValues, this_ptr, "get", NULL, 0, key, _0);
	zephir_check_call_status();
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(newValues, value);
	} else {
		ZEPHIR_INIT_NVAR(newValues);
		zephir_create_array(newValues, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(newValues, value);
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CALL_FUNCTION(&_2, "array_values", NULL, 12, newValues);
	zephir_check_call_status();
	zephir_fast_array_merge(_1, &(oldValues), &(_2) TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, key, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Headers, has) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *key_param = NULL, *_1 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&_1, this_ptr, "normalizekey", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_PARENT(snailhttp_headers_ce, this_ptr, "has", &_0, 13, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Headers, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *key_param = NULL, *_1 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&_1, this_ptr, "normalizekey", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, snailhttp_headers_ce, this_ptr, "remove", &_0, 14, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Headers, normalizeKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0, _1 = zval_used_for_init, _2, *_3 = NULL, *_4, _5$$3, *_6$$3;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, key);
	zephir_get_strval(key, _0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "_", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "-", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "strtr", NULL, 15, key, &_1, &_2);
	zephir_check_call_status();
	zephir_get_strval(key, _3);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "http-", 0);
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_strpos(_4, key, &_1, 0 );
	if (ZEPHIR_IS_LONG_IDENTICAL(_4, 0)) {
		ZEPHIR_SINIT_VAR(_5$$3);
		ZVAL_LONG(&_5$$3, 5);
		ZEPHIR_INIT_VAR(_6$$3);
		zephir_substr(_6$$3, key, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_get_strval(key, _6$$3);
	}
	RETURN_CTOR(key);

}

void zephir_init_static_properties_SnailHttp_Headers(TSRMLS_D) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 6, 0 TSRMLS_CC);
	add_assoc_long_ex(_0, SS("CONTENT_TYPE"), 1);
	add_assoc_long_ex(_0, SS("CONTENT_LENGTH"), 1);
	add_assoc_long_ex(_0, SS("PHP_AUTH_USER"), 1);
	add_assoc_long_ex(_0, SS("PHP_AUTH_PW"), 1);
	add_assoc_long_ex(_0, SS("PHP_AUTH_DIGEST"), 1);
	add_assoc_long_ex(_0, SS("AUTH_TYPE"), 1);
	zephir_update_static_property_ce(snailhttp_headers_ce, SL("special"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

