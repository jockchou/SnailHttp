
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(SnailHttp_FactoryDefault) {

	ZEPHIR_REGISTER_CLASS(SnailHttp, FactoryDefault, snailhttp, factorydefault, snailhttp_factorydefault_method_entry, 0);

	zend_declare_property_null(snailhttp_factorydefault_ce, SL("special"), ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_class_constant_long(snailhttp_factorydefault_ce, SL("PHP_URL_SCHEME"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(snailhttp_factorydefault_ce, SL("PHP_URL_HOST"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(snailhttp_factorydefault_ce, SL("PHP_URL_PORT"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(snailhttp_factorydefault_ce, SL("PHP_URL_USER"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(snailhttp_factorydefault_ce, SL("PHP_URL_PASS"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(snailhttp_factorydefault_ce, SL("PHP_URL_PATH"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(snailhttp_factorydefault_ce, SL("PHP_URL_QUERY"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(snailhttp_factorydefault_ce, SL("PHP_URL_FRAGMENT"), 7 TSRMLS_CC);

	zend_class_implements(snailhttp_factorydefault_ce TSRMLS_CC, 1, snailhttp_factoryinterface_ce);
	return SUCCESS;

}

PHP_METHOD(SnailHttp_FactoryDefault, makeRequest) {

	zend_bool _4;
	zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *globals_param = NULL, *_POST, *method = NULL, *uri = NULL, *headers = NULL, *cookies = NULL, *body = NULL, *files = NULL, *request = NULL, *mediaType = NULL, *_1 = NULL, *_2, *_3 = NULL, *_6$$3 = NULL;
	zval *globals = NULL, *_5;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &globals_param);

	zephir_get_arrval(globals, globals_param);


	ZEPHIR_INIT_VAR(files);
	array_init(files);
	ZEPHIR_OBS_VAR(method);
	zephir_array_fetch_string(&method, globals, SL("REQUEST_METHOD"), PH_NOISY, "snailhttp/FactoryDefault.zep", 32 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&uri, this_ptr, "makeuri", NULL, 0, globals);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&headers, this_ptr, "makeheaders", NULL, 0, globals);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "Cookie", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, headers, "get", NULL, 0, _3, _2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&cookies, snailhttp_cookies_ce, "parseheader", &_0, 17, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&body, this_ptr, "makebody", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(request);
	object_init_ex(request, snailhttp_request_ce);
	ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL, 18, method, uri, headers, cookies, globals, body, files);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&mediaType, request, "getmediatype", NULL, 19);
	zephir_check_call_status();
	_4 = ZEPHIR_IS_STRING_IDENTICAL(method, "POST");
	if (_4) {
		ZEPHIR_INIT_VAR(_5);
		zephir_create_array(_5, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "application/x-www-form-urlencoded", 1);
		zephir_array_fast_append(_5, _3);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "multipart/form-data", 1);
		zephir_array_fast_append(_5, _3);
		_4 = zephir_fast_in_array(mediaType, _5 TSRMLS_CC);
	}
	if (_4) {
		ZEPHIR_CALL_METHOD(&_6$$3, request, "withparsedbody", NULL, 20, _POST);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(request, _6$$3);
	}
	RETURN_CCTOR(request);

}

PHP_METHOD(SnailHttp_FactoryDefault, makeUri) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS, port = 0;
	zval *globals_param = NULL, *pos = NULL, *env = NULL, *isSecure = NULL, *scheme = NULL, *username = NULL, *password = NULL, *host = NULL, *matches = NULL, *requestUri = NULL, *queryString = NULL, *fragment = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_6 = NULL, _7, *_17 = NULL, *_18, _19, *_20, *_4$$3, *_5$$4, *_8$$5, *_9$$6, _10$$6, *_11$$6, _12$$7, _13$$8, *_14$$8, _15$$8, *_16$$8 = NULL;
	zval *globals = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &globals_param);

	zephir_get_arrval(globals, globals_param);


	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);
	ZEPHIR_INIT_VAR(env);
	object_init_ex(env, snailhttp_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, env, "__construct", NULL, 21, globals);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HTTPS", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&isSecure, env, "get", NULL, 22, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_1 = ZEPHIR_IS_EMPTY(isSecure);
	if (!(_1)) {
		_1 = ZEPHIR_IS_STRING_IDENTICAL(isSecure, "off");
	}
	if (_1) {
		ZEPHIR_INIT_VAR(scheme);
		ZVAL_STRING(scheme, "http", 1);
	} else {
		ZEPHIR_INIT_NVAR(scheme);
		ZVAL_STRING(scheme, "https", 1);
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "PHP_AUTH_USER", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&username, env, "get", NULL, 22, _0, _2);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "PHP_AUTH_PW", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&password, env, "get", NULL, 22, _0, _2);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "HTTP_HOST", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, env, "has", NULL, 23, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_STRING(_4$$3, "HTTP_HOST", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&host, env, "get", NULL, 22, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_5$$4);
		ZVAL_STRING(_5$$4, "SERVER_NAME", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&host, env, "get", NULL, 22, _5$$4);
		zephir_check_temp_parameter(_5$$4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "SERVER_PORT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 80);
	ZEPHIR_CALL_METHOD(&_6, env, "get", NULL, 22, _0, _2);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	port = zephir_get_intval(_6);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "/^(\\[[a-fA-F0-9:.]+\\])(:\\d+)?\\z/", 0);
	zephir_preg_match(_0, &_7, host, matches, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_OBS_NVAR(host);
		zephir_array_fetch_long(&host, matches, 1, PH_NOISY, "snailhttp/FactoryDefault.zep", 73 TSRMLS_CC);
		zephir_array_fetch_long(&_8$$5, matches, 2, PH_NOISY | PH_READONLY, "snailhttp/FactoryDefault.zep", 75 TSRMLS_CC);
		if (zephir_is_true(_8$$5)) {
			zephir_array_fetch_long(&_9$$6, matches, 2, PH_NOISY | PH_READONLY, "snailhttp/FactoryDefault.zep", 76 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_10$$6);
			ZVAL_LONG(&_10$$6, 1);
			ZEPHIR_INIT_VAR(_11$$6);
			zephir_substr(_11$$6, _9$$6, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			port = zephir_get_intval(_11$$6);
		}
	} else {
		ZEPHIR_SINIT_VAR(_12$$7);
		ZVAL_STRING(&_12$$7, ":", 0);
		ZEPHIR_INIT_VAR(pos);
		zephir_fast_strpos(pos, host, &_12$$7, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(pos)) {
			ZEPHIR_SINIT_VAR(_13$$8);
			ZVAL_LONG(&_13$$8, (zephir_get_numberval(pos) + 1));
			ZEPHIR_INIT_VAR(_14$$8);
			zephir_substr(_14$$8, host, zephir_get_intval(&_13$$8), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			port = zephir_get_intval(_14$$8);
			ZEPHIR_SINIT_VAR(_15$$8);
			ZVAL_STRING(&_15$$8, ":", 0);
			ZEPHIR_CALL_FUNCTION(&_16$$8, "strstr", NULL, 24, host, &_15$$8, ZEPHIR_GLOBAL(global_true));
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(host, _16$$8);
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "REQUEST_URI", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_17, env, "get", NULL, 22, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_18);
	ZEPHIR_CONCAT_SV(_18, "http://example.com", _17);
	ZEPHIR_SINIT_VAR(_19);
	ZVAL_LONG(&_19, 5);
	ZEPHIR_CALL_FUNCTION(&requestUri, "parse_url", NULL, 25, _18, &_19);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "QUERY_STRING", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_20);
	ZVAL_STRING(_20, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&queryString, env, "get", NULL, 22, _2, _20);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_20);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(fragment);
	ZVAL_STRING(fragment, "", 1);
	object_init_ex(return_value, snailhttp_uri_ce);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, port);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 26, scheme, host, _2, requestUri, queryString, fragment, username, password);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SnailHttp_FactoryDefault, makeHeaders) {

	zend_bool _5$$3;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *globals_param = NULL, *key = NULL, *value = NULL, *data = NULL, **_2, *_3$$3 = NULL, *_4$$3, _6$$3 = zval_used_for_init;
	zval *globals = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &globals_param);

	zephir_get_arrval(globals, globals_param);


	ZEPHIR_INIT_VAR(data);
	array_init(data);
	zephir_is_iterable(globals, &_1, &_0, 0, 0, "snailhttp/FactoryDefault.zep", 114);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_INIT_NVAR(_3$$3);
		zephir_fast_strtoupper(_3$$3, key);
		ZEPHIR_CPY_WRT(key, _3$$3);
		_4$$3 = zephir_fetch_static_property_ce(snailhttp_factorydefault_ce, SL("special") TSRMLS_CC);
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
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 21, data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SnailHttp_FactoryDefault, makeBody) {

	zval *stream = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;

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
	object_init_ex(return_value, snailhttp_stream_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 30, stream);
	zephir_check_call_status();
	RETURN_MM();

}

void zephir_init_static_properties_SnailHttp_FactoryDefault(TSRMLS_D) {

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
	zephir_update_static_property_ce(snailhttp_factorydefault_ce, SL("special"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

