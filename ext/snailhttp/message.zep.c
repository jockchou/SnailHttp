
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(SnailHttp_Message) {

	ZEPHIR_REGISTER_CLASS(SnailHttp, Message, snailhttp, message, snailhttp_message_method_entry, 0);

	zend_declare_property_string(snailhttp_message_ce, SL("protocolVersion"), "1.1", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_message_ce, SL("headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_message_ce, SL("body"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_message_ce, SL("valid"), ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(snailhttp_message_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("psr\\http\\message\\messageinterface") TSRMLS_CC));
	return SUCCESS;

}

PHP_METHOD(SnailHttp_Message, getProtocolVersion) {

	

	RETURN_MEMBER(this_ptr, "protocolVersion");

}

PHP_METHOD(SnailHttp_Message, withProtocolVersion) {

	zval *version_param = NULL, *cloneObj = NULL, *_0;
	zval *version = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &version_param);

	zephir_get_strval(version, version_param);


	_0 = zephir_fetch_static_property_ce(snailhttp_message_ce, SL("valid") TSRMLS_CC);
	if (!(zephir_array_isset(_0, version))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid HTTP version. Must be one of: 1.0, 1.1, 2.0", "snailhttp/Message.zep", 30);
		return;
	}
	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(cloneObj, SL("protocolVersion"), version TSRMLS_CC);
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Message, getHeaders) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "all", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Message, hasHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "has", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Message, getHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, name, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Message, getHeaderLine) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0, *_1 = NULL, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	ZEPHIR_CALL_METHOD(&_1, _0, "get", NULL, 0, name, _2);
	zephir_check_call_status();
	zephir_fast_join_str(return_value, SL(","), _1 TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Message, withHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, *cloneObj = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(name, name_param);


	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, cloneObj, SL("headers"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "set", NULL, 0, name, value);
	zephir_check_call_status();
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Message, withAddedHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, *cloneObj = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(name, name_param);


	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, cloneObj, SL("headers"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "add", NULL, 0, name, value);
	zephir_check_call_status();
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Message, withoutHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *cloneObj = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, cloneObj, SL("headers"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "remove", NULL, 0, name);
	zephir_check_call_status();
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Message, getBody) {

	

	RETURN_MEMBER(this_ptr, "body");

}

PHP_METHOD(SnailHttp_Message, withBody) {

	zval *body, *cloneObj = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &body);



	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(cloneObj, SL("body"), body TSRMLS_CC);
	RETURN_CCTOR(cloneObj);

}

void zephir_init_static_properties_SnailHttp_Message(TSRMLS_D) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("1.0"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("1.1"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("2.0"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_update_static_property_ce(snailhttp_message_ce, SL("valid"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

