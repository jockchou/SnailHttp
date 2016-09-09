
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(SnailHttp_Cookies) {

	ZEPHIR_REGISTER_CLASS(SnailHttp, Cookies, snailhttp, cookies, snailhttp_cookies_method_entry, 0);

	zend_declare_property_null(snailhttp_cookies_ce, SL("requestCookies"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_cookies_ce, SL("responseCookies"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_cookies_ce, SL("defaults"), ZEND_ACC_PROTECTED TSRMLS_CC);

	snailhttp_cookies_ce->create_object = zephir_init_properties_SnailHttp_Cookies;

	zend_class_implements(snailhttp_cookies_ce TSRMLS_CC, 1, snailhttp_cookiesinterface_ce);
	return SUCCESS;

}

PHP_METHOD(SnailHttp_Cookies, __construct) {

	zval *cookies_param = NULL;
	zval *cookies = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &cookies_param);

	if (!cookies_param) {
		ZEPHIR_INIT_VAR(cookies);
		array_init(cookies);
	} else {
		zephir_get_arrval(cookies, cookies_param);
	}


	zephir_update_property_this(this_ptr, SL("requestCookies"), cookies TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Cookies, setDefaults) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *settings_param = NULL, *_0, *_1 = NULL;
	zval *settings = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &settings_param);

	zephir_get_arrval(settings, settings_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("defaults"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_replace", NULL, 11, _0, settings);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("defaults"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Cookies, get) {

	zval *name_param = NULL, *def = NULL, *cookie = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &def);

	zephir_get_strval(name, name_param);
	if (!def) {
		def = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("requestCookies"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&cookie, _0, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(cookie);
	}
	RETVAL_ZVAL(def, 1, 0);
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Cookies, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value = NULL, *_1, *_2 = NULL;
	zval *name = NULL, *_0$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(name, name_param);
	ZEPHIR_SEPARATE_PARAM(value);


	if (!(Z_TYPE_P(value) == IS_ARRAY)) {
		ZEPHIR_INIT_NVAR(value);
		zephir_create_array(value, 1, 0 TSRMLS_CC);
		zephir_get_strval(_0$$3, value);
		zephir_array_update_string(&value, SL("value"), &_0$$3, PH_COPY | PH_SEPARATE);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("defaults"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "array_replace", NULL, 11, _1, value);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("responseCookies"), name, _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Cookies, toHeaders) {

	HashTable *_2;
	HashPosition _1;
	zval *name = NULL, *properties = NULL, *headers = NULL, *_0, **_3, *_4$$3 = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(headers);
	array_init(headers);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("responseCookies"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "snailhttp/Cookies.zep", 57);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(name, _2, _1);
		ZEPHIR_GET_HVALUE(properties, _3);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "toheader", &_5, 0, name, properties);
		zephir_check_call_status();
		zephir_array_append(&headers, _4$$3, PH_SEPARATE, "snailhttp/Cookies.zep", 54);
	}
	RETURN_CCTOR(headers);

}

PHP_METHOD(SnailHttp_Cookies, toHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *properties = NULL;
	zval *name_param = NULL, *properties_param = NULL, *result = NULL, *timestamp = NULL, *domain = NULL, *path = NULL, *expires = NULL, *_0 = NULL, *_2, *_3 = NULL, *_4$$3, *_5$$4, *_6$$5, _7$$9, *_8$$9 = NULL, *_9$$9;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &properties_param);

	zephir_get_strval(name, name_param);
	zephir_get_arrval(properties, properties_param);


	ZEPHIR_INIT_VAR(result);
	ZVAL_STRING(result, "", 1);
	ZEPHIR_INIT_VAR(timestamp);
	ZVAL_LONG(timestamp, 0);
	ZEPHIR_CALL_FUNCTION(&_0, "urlencode", &_1, 12, name);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, properties, SL("value"), PH_NOISY | PH_READONLY, "snailhttp/Cookies.zep", 64 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "urlencode", &_1, 12, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(result);
	ZEPHIR_CONCAT_VSV(result, _0, "=", _3);
	ZEPHIR_OBS_VAR(domain);
	if (zephir_array_isset_string_fetch(&domain, properties, SS("domain"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_CONCAT_SV(_4$$3, "; domain=", domain);
		zephir_concat_self(&result, _4$$3 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(path);
	if (zephir_array_isset_string_fetch(&path, properties, SS("path"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_5$$4);
		ZEPHIR_CONCAT_SV(_5$$4, "; path=", path);
		zephir_concat_self(&result, _5$$4 TSRMLS_CC);
	}
	ZEPHIR_OBS_NVAR(path);
	if (zephir_array_isset_string_fetch(&path, properties, SS("path"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_6$$5);
		ZEPHIR_CONCAT_SV(_6$$5, "; path=", path);
		zephir_concat_self(&result, _6$$5 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(expires);
	if (zephir_array_isset_string_fetch(&expires, properties, SS("expires"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(expires) == IS_STRING) {
			ZEPHIR_CALL_FUNCTION(&timestamp, "strtotime", NULL, 13, expires);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(timestamp);
			ZVAL_LONG(timestamp, zephir_get_intval(expires));
		}
		if (!ZEPHIR_IS_LONG_IDENTICAL(timestamp, 0)) {
			ZEPHIR_SINIT_VAR(_7$$9);
			ZVAL_STRING(&_7$$9, "D, d-M-Y H:i:s e", 0);
			ZEPHIR_CALL_FUNCTION(&_8$$9, "gmdate", NULL, 14, &_7$$9, timestamp);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_9$$9);
			ZEPHIR_CONCAT_SV(_9$$9, "; expires=", _8$$9);
			zephir_concat_self(&result, _9$$9 TSRMLS_CC);
		}
	}
	if (zephir_array_isset_string(properties, SS("secure"))) {
		zephir_concat_self_str(&result, SL("; secure") TSRMLS_CC);
	}
	if (zephir_array_isset_string(properties, SS("httponly"))) {
		zephir_concat_self_str(&result, SL("; HttpOnly") TSRMLS_CC);
	}
	RETURN_CCTOR(result);

}

PHP_METHOD(SnailHttp_Cookies, parseHeader) {

	HashTable *_5;
	HashPosition _4;
	zephir_fcall_cache_entry *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *header = NULL, *key = NULL, *value = NULL, *pieces = NULL, *cookie = NULL, *cookies = NULL, *_1, _2, _3, **_6, *_0$$3 = NULL, *_7$$5 = NULL, *_8$$6, *_10$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header);

	ZEPHIR_SEPARATE_PARAM(header);


	ZEPHIR_INIT_VAR(cookies);
	array_init(cookies);
	if (Z_TYPE_P(header) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0$$3);
		if (zephir_array_isset_long(header, 0)) {
			ZEPHIR_OBS_NVAR(_0$$3);
			zephir_array_fetch_long(&_0$$3, header, 0, PH_NOISY, "snailhttp/Cookies.zep", 107 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_0$$3);
			ZVAL_STRING(_0$$3, "", 1);
		}
		ZEPHIR_CPY_WRT(header, _0$$3);
	}
	if (!(Z_TYPE_P(header) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Cannot parse Cookie data. Header value must be a string.", "snailhttp/Cookies.zep", 111);
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "\r\n", 0);
	zephir_fast_trim(_1, header, &_2, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_CPY_WRT(header, _1);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "@\\s*[;,]\\s*@", 0);
	ZEPHIR_CALL_FUNCTION(&pieces, "preg_split", NULL, 15, &_3, header);
	zephir_check_call_status();
	zephir_is_iterable(pieces, &_5, &_4, 0, 0, "snailhttp/Cookies.zep", 130);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(cookie, _6);
		ZEPHIR_INIT_NVAR(_7$$5);
		zephir_fast_explode_str(_7$$5, SL("="), cookie, 2  TSRMLS_CC);
		ZEPHIR_CPY_WRT(cookie, _7$$5);
		if (zephir_fast_count_int(cookie TSRMLS_CC) == 2) {
			zephir_array_fetch_long(&_8$$6, cookie, 0, PH_NOISY | PH_READONLY, "snailhttp/Cookies.zep", 121 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&key, "urldecode", &_9, 16, _8$$6);
			zephir_check_call_status();
			zephir_array_fetch_long(&_10$$6, cookie, 1, PH_NOISY | PH_READONLY, "snailhttp/Cookies.zep", 122 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&value, "urldecode", &_9, 16, _10$$6);
			zephir_check_call_status();
			if (!(zephir_array_isset(cookies, key))) {
				zephir_array_update_zval(&cookies, key, &value, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(cookies);

}

zend_object_value zephir_init_properties_SnailHttp_Cookies(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3;
	zval *_0, *_2, *_4, *_3$$4, *_5$$5;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("defaults"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 6, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_1$$3, SS("value"), SL(""), 1);
			zephir_array_update_string(&_1$$3, SL("domain"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("path"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("expires"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("secure"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("httponly"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
			zephir_update_property_this(this_ptr, SL("defaults"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("responseCookies"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("responseCookies"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("requestCookies"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(this_ptr, SL("requestCookies"), _5$$5 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

