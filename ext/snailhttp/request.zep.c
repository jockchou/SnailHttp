
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(SnailHttp_Request) {

	ZEPHIR_REGISTER_CLASS_EX(SnailHttp, Request, snailhttp, request, snailhttp_message_ce, snailhttp_request_method_entry, 0);

	zend_declare_property_null(snailhttp_request_ce, SL("method"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_request_ce, SL("uri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_request_ce, SL("requestTarget"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_request_ce, SL("queryParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_request_ce, SL("cookies"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_request_ce, SL("serverParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_request_ce, SL("attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_request_ce, SL("bodyParsed"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_request_ce, SL("bodyParsers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_request_ce, SL("uploadedFiles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_request_ce, SL("validMethods"), ZEND_ACC_STATIC TSRMLS_CC);

	snailhttp_request_ce->create_object = zephir_init_properties_SnailHttp_Request;

	zend_class_implements(snailhttp_request_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("psr\\http\\message\\serverrequestinterface") TSRMLS_CC));
	return SUCCESS;

}

PHP_METHOD(SnailHttp_Request, __construct) {

	zend_bool _8;
	zephir_fcall_cache_entry *_16 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *cookies = NULL, *serverParams = NULL, *uploadedFiles = NULL;
	zval *method_param = NULL, *uri, *headers, *cookies_param = NULL, *serverParams_param = NULL, *body, *uploadedFiles_param = NULL, *protocol = NULL, *_0 = NULL, *_1, *_5, *_6 = NULL, *_7 = NULL, *_9, *_10 = NULL, *_15 = NULL, *_17 = NULL, *_18 = NULL, *_19, *_2$$3, _3$$3, _4$$3, *_11$$4, *_12$$4, *_13$$4 = NULL, *_14$$4;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 1, &method_param, &uri, &headers, &cookies_param, &serverParams_param, &body, &uploadedFiles_param);

	zephir_get_strval(method, method_param);
	zephir_get_arrval(cookies, cookies_param);
	zephir_get_arrval(serverParams, serverParams_param);
	if (!uploadedFiles_param) {
		ZEPHIR_INIT_VAR(uploadedFiles);
		array_init(uploadedFiles);
	} else {
		zephir_get_arrval(uploadedFiles, uploadedFiles_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filtermethod", NULL, 0, method);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("method"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("uri"), uri TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("headers"), headers TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("cookies"), cookies TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("serverParams"), serverParams TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, snailhttp_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 17);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("attributes"), _1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("body"), body TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("uploadedFiles"), uploadedFiles TSRMLS_CC);
	ZEPHIR_OBS_VAR(protocol);
	if (zephir_array_isset_string_fetch(&protocol, serverParams, SS("SERVER_PROTOCOL"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_STRING(&_3$$3, "HTTP/", 0);
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_STRING(&_4$$3, "", 0);
		zephir_fast_str_replace(&_2$$3, &_3$$3, &_4$$3, protocol TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("protocolVersion"), _2$$3 TSRMLS_CC);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "Host", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_6, _5, "has", NULL, 0, _7);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	_8 = !zephir_is_true(_6);
	if (!(_8)) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_10, _9, "gethost", NULL, 0);
		zephir_check_call_status();
		_8 = !ZEPHIR_IS_STRING_IDENTICAL(_10, "");
	}
	if (_8) {
		_11$$4 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
		_12$$4 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_13$$4, _12$$4, "gethost", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_14$$4);
		ZVAL_STRING(_14$$4, "Host", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _11$$4, "set", NULL, 0, _14$$4, _13$$4);
		zephir_check_temp_parameter(_14$$4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_7);
	ZEPHIR_INIT_NVAR(_7);
	zephir_create_closure_ex(_7, NULL, snailhttp_0__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_15);
	ZVAL_STRING(_15, "application/json", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registermediatypeparser", &_16, 0, _15, _7);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_15);
	ZEPHIR_INIT_NVAR(_15);
	zephir_create_closure_ex(_15, NULL, snailhttp_1__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_17);
	ZVAL_STRING(_17, "application/xml", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registermediatypeparser", &_16, 0, _17, _15);
	zephir_check_temp_parameter(_17);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_17);
	ZEPHIR_INIT_NVAR(_17);
	zephir_create_closure_ex(_17, NULL, snailhttp_2__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_18);
	ZVAL_STRING(_18, "text/xml", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registermediatypeparser", &_16, 0, _18, _17);
	zephir_check_temp_parameter(_18);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_18);
	ZEPHIR_INIT_NVAR(_18);
	zephir_create_closure_ex(_18, NULL, snailhttp_3__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_19);
	ZVAL_STRING(_19, "application/x-www-form-urlencoded", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registermediatypeparser", &_16, 0, _19, _18);
	zephir_check_temp_parameter(_19);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Request, __clone) {

	zval *_0, *_1, *_2, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	if (zephir_clone(_1, _0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_this(this_ptr, SL("headers"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("attributes"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	if (zephir_clone(_3, _2 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_this(this_ptr, SL("attributes"), _3 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("body"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	if (zephir_clone(_5, _4 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_this(this_ptr, SL("body"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Request, getMethod) {

	

	RETURN_MEMBER(this_ptr, "method");

}

PHP_METHOD(SnailHttp_Request, withMethod) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *cloneObj = NULL, *_0 = NULL;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);

	zephir_get_strval(method, method_param);


	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filtermethod", NULL, 0, method);
	zephir_check_call_status();
	zephir_update_property_zval(cloneObj, SL("method"), _0 TSRMLS_CC);
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Request, filterMethod) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *method = NULL, *_0$$4, *_1$$4 = NULL, _2$$4, *_3$$4 = NULL, *_5, *_6, *_7$$5, _8$$5, *_9$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method);

	ZEPHIR_SEPARATE_PARAM(method);


	if (Z_TYPE_P(method) == IS_NULL) {
		RETVAL_ZVAL(method, 1, 0);
		RETURN_MM();
	}
	if (!(Z_TYPE_P(method) == IS_STRING)) {
		ZEPHIR_INIT_VAR(_0$$4);
		object_init_ex(_0$$4, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(_1$$4);
		if (Z_TYPE_P(method) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_1$$4);
			zephir_get_class(_1$$4, method, 0 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_1$$4);
			zephir_gettype(_1$$4, method TSRMLS_CC);
		}
		ZEPHIR_SINIT_VAR(_2$$4);
		ZVAL_STRING(&_2$$4, "Unsupported HTTP method; must be a string, received %s", 0);
		ZEPHIR_CALL_FUNCTION(&_3$$4, "sprintf", &_4, 8, &_2$$4, _1$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0$$4, "__construct", NULL, 25, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$4, "snailhttp/Request.zep", 126 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_strtoupper(_5, method);
	ZEPHIR_CPY_WRT(method, _5);
	_6 = zephir_fetch_static_property_ce(snailhttp_request_ce, SL("validMethods") TSRMLS_CC);
	if (!(zephir_array_isset(_6, method))) {
		ZEPHIR_INIT_VAR(_7$$5);
		object_init_ex(_7$$5, spl_ce_InvalidArgumentException);
		ZEPHIR_SINIT_VAR(_8$$5);
		ZVAL_STRING(&_8$$5, "Unsupported HTTP method \"%s\" provided", 0);
		ZEPHIR_CALL_FUNCTION(&_9$$5, "sprintf", &_4, 8, &_8$$5, method);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _7$$5, "__construct", NULL, 25, _9$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_7$$5, "snailhttp/Request.zep", 134 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(method, 1, 0);
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Request, getRequestTarget) {

	zval *path = NULL, *query = NULL, *_0, *_1, *_2, *_3, *_4 = NULL, _5, *_6, *_7$$5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("requestTarget"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		RETURN_MM_MEMBER(this_ptr, "requestTarget");
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	if (Z_TYPE_P(_1) == IS_NULL) {
		RETURN_MM_STRING("/", 1);
	}
	ZEPHIR_INIT_VAR(_2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_4, _3, "getpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "/", 0);
	zephir_fast_trim(_2, _4, &_5, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	ZEPHIR_INIT_VAR(path);
	ZEPHIR_CONCAT_SV(path, "/", _2);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&query, _6, "getquery", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(query)) {
		ZEPHIR_INIT_VAR(_7$$5);
		ZEPHIR_CONCAT_SV(_7$$5, "?", query);
		zephir_concat_self(&path, _7$$5 TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("requestTarget"), path TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "requestTarget");

}

PHP_METHOD(SnailHttp_Request, withRequestTarget) {

	zval *requestTarget, *cloneObj = NULL, *_0, *_1, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &requestTarget);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "#\\s#", 0);
	zephir_preg_match(_1, &_2, requestTarget, _0, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid request target provided; must be a string and cannot contain whitespace", "snailhttp/Request.zep", 170);
		return;
	}
	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(cloneObj, SL("requestTarget"), requestTarget TSRMLS_CC);
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Request, getUri) {

	

	RETURN_MEMBER(this_ptr, "uri");

}

PHP_METHOD(SnailHttp_Request, withUri) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool preserveHost, _6$$5, _9$$5;
	zval *uri, *preserveHost_param = NULL, *cloneObj = NULL, *_0$$3 = NULL, *_1$$4, *_2$$4 = NULL, *_3$$4, *_4$$5, *_5$$5 = NULL, *_7$$5 = NULL, *_8$$5 = NULL, *_10$$5 = NULL, *_11$$6, *_12$$6 = NULL, *_13$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &uri, &preserveHost_param);

	if (!preserveHost_param) {
		preserveHost = 0;
	} else {
		preserveHost = zephir_get_boolval(preserveHost_param);
	}


	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(cloneObj, SL("uri"), uri TSRMLS_CC);
	if (!(preserveHost)) {
		ZEPHIR_CALL_METHOD(&_0$$3, uri, "gethost", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_STRING_IDENTICAL(_0$$3, "")) {
			ZEPHIR_OBS_VAR(_1$$4);
			zephir_read_property(&_1$$4, cloneObj, SL("headers"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_2$$4, uri, "gethost", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_3$$4);
			ZVAL_STRING(_3$$4, "Host", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _1$$4, "set", NULL, 0, _3$$4, _2$$4);
			zephir_check_temp_parameter(_3$$4);
			zephir_check_call_status();
		}
	} else {
		_4$$5 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5$$5, _4$$5, "gethost", NULL, 0);
		zephir_check_call_status();
		_6$$5 = !ZEPHIR_IS_STRING_IDENTICAL(_5$$5, "");
		if (_6$$5) {
			ZEPHIR_INIT_VAR(_8$$5);
			ZVAL_STRING(_8$$5, "Host", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_7$$5, this_ptr, "hasheader", NULL, 0, _8$$5);
			zephir_check_temp_parameter(_8$$5);
			zephir_check_call_status();
			_9$$5 = !zephir_is_true(_7$$5);
			if (!(_9$$5)) {
				ZEPHIR_INIT_NVAR(_8$$5);
				ZVAL_STRING(_8$$5, "Host", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_10$$5, this_ptr, "getheader", NULL, 0, _8$$5);
				zephir_check_temp_parameter(_8$$5);
				zephir_check_call_status();
				_9$$5 = Z_TYPE_P(_10$$5) == IS_NULL;
			}
			_6$$5 = _9$$5;
		}
		if (_6$$5) {
			ZEPHIR_OBS_VAR(_11$$6);
			zephir_read_property(&_11$$6, cloneObj, SL("headers"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_12$$6, uri, "gethost", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_13$$6);
			ZVAL_STRING(_13$$6, "Host", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _11$$6, "set", NULL, 0, _13$$6, _12$$6);
			zephir_check_temp_parameter(_13$$6);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Request, getCookieParams) {

	

	RETURN_MEMBER(this_ptr, "cookies");

}

PHP_METHOD(SnailHttp_Request, withCookieParams) {

	zval *cookies_param = NULL, *cloneObj = NULL;
	zval *cookies = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cookies_param);

	zephir_get_arrval(cookies, cookies_param);


	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(cloneObj, SL("cookies"), cookies TSRMLS_CC);
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Request, getQueryParams) {

	zval *_0, *_1, *_2, *_3 = NULL, *_4;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("queryParams"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		RETURN_MM_MEMBER(this_ptr, "queryParams");
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	if (Z_TYPE_P(_1) == IS_NULL) {
		array_init(return_value);
		RETURN_MM();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_3, _2, "getquery", NULL, 0);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("queryParams"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_4);
	ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 26, _3, _4);
	ZEPHIR_UNREF(_4);
	zephir_check_call_status();
	RETURN_MM_MEMBER(this_ptr, "queryParams");

}

PHP_METHOD(SnailHttp_Request, withQueryParams) {

	zval *query_param = NULL, *cloneObj = NULL;
	zval *query = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query_param);

	zephir_get_arrval(query, query_param);


	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(cloneObj, SL("queryParams"), query TSRMLS_CC);
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Request, getUploadedFiles) {

	

	RETURN_MEMBER(this_ptr, "uploadedFiles");

}

PHP_METHOD(SnailHttp_Request, withUploadedFiles) {

	zval *uploadedFiles_param = NULL, *cloneObj = NULL;
	zval *uploadedFiles = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uploadedFiles_param);

	zephir_get_arrval(uploadedFiles, uploadedFiles_param);


	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(cloneObj, SL("uploadedFiles"), uploadedFiles TSRMLS_CC);
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Request, getServerParams) {

	

	RETURN_MEMBER(this_ptr, "serverParams");

}

PHP_METHOD(SnailHttp_Request, getAttributes) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("attributes"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "all", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Request, getAttribute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *def = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &def);

	zephir_get_strval(name, name_param);
	if (!def) {
		def = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("attributes"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, name, def);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Request, withAttribute) {

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
	zephir_read_property(&_0, cloneObj, SL("attributes"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "set", NULL, 0, name, value);
	zephir_check_call_status();
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Request, withoutAttribute) {

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
	zephir_read_property(&_0, cloneObj, SL("attributes"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "remove", NULL, 0, name);
	zephir_check_call_status();
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Request, getParsedBody) {

	zend_bool _5$$5, _6$$5;
	zval *_3 = NULL;
	zval *mediaType = NULL, *body = NULL, *parsed = NULL, *func = NULL, *_0, *_1, *_2 = NULL, *_4;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("bodyParsed"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		RETURN_MM_MEMBER(this_ptr, "bodyParsed");
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("body"), PH_NOISY_CC);
	if (!(zephir_is_true(_1))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&mediaType, this_ptr, "getmediatype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getbody", NULL, 0);
	zephir_check_call_status();
	zephir_get_strval(_3, _2);
	ZEPHIR_CPY_WRT(body, _3);
	ZEPHIR_OBS_VAR(func);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("bodyParsers"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&func, _4, mediaType, 0 TSRMLS_CC)) {
		ZEPHIR_CALL_ZVAL_FUNCTION(&parsed, func, NULL, 0, body);
		zephir_check_call_status();
		_5$$5 = !(Z_TYPE_P(parsed) == IS_NULL);
		if (_5$$5) {
			_5$$5 = !(Z_TYPE_P(parsed) == IS_OBJECT);
		}
		_6$$5 = _5$$5;
		if (_6$$5) {
			_6$$5 = !(Z_TYPE_P(parsed) == IS_ARRAY);
		}
		if (_6$$5) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Request body media type parser return value must be an array, an object, or null", "snailhttp/Request.zep", 321);
			return;
		}
		zephir_update_property_this(this_ptr, SL("bodyParsed"), parsed TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "bodyParsed");

}

PHP_METHOD(SnailHttp_Request, withParsedBody) {

	zend_bool _0, _1;
	zval *data, *cloneObj = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	_0 = !(Z_TYPE_P(data) == IS_NULL);
	if (_0) {
		_0 = !(Z_TYPE_P(data) == IS_OBJECT);
	}
	_1 = _0;
	if (_1) {
		_1 = !(Z_TYPE_P(data) == IS_ARRAY);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parsed body value must be an array, an object, or null", "snailhttp/Request.zep", 333);
		return;
	}
	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(cloneObj, SL("bodyParsed"), data TSRMLS_CC);
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Request, getContentType) {

	zval *result = NULL, *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Content-Type", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "getheader", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	if (zephir_is_true(result)) {
		zephir_array_fetch_long(&_0, result, 0, PH_NOISY, "snailhttp/Request.zep", 348 TSRMLS_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(SnailHttp_Request, getMediaType) {

	zval *contentType = NULL, *contentTypeParts = NULL, _0$$3, *_1$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&contentType, this_ptr, "getcontenttype", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(contentType)) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "/\\s*[;,]\\s*/", 0);
		ZEPHIR_CALL_FUNCTION(&contentTypeParts, "preg_split", NULL, 15, &_0$$3, contentType);
		zephir_check_call_status();
		zephir_array_fetch_long(&_1$$3, contentTypeParts, 0, PH_NOISY | PH_READONLY, "snailhttp/Request.zep", 358 TSRMLS_CC);
		zephir_fast_strtolower(return_value, _1$$3);
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

PHP_METHOD(SnailHttp_Request, registerMediaTypeParser) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *mediaType_param = NULL, *callback = NULL, *_0$$3 = NULL;
	zval *mediaType = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &mediaType_param, &callback);

	zephir_get_strval(mediaType, mediaType_param);
	ZEPHIR_SEPARATE_PARAM(callback);


	if (zephir_is_instance_of(callback, SL("SnailHttp\\Closure") TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_0$$3, callback, "bindto", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(callback, _0$$3);
	}
	zephir_get_strval(_1, mediaType);
	zephir_update_property_array(this_ptr, SL("bodyParsers"), _1, callback TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

zend_object_value zephir_init_properties_SnailHttp_Request(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("bodyParsers"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("bodyParsers"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

void zephir_init_static_properties_SnailHttp_Request(TSRMLS_D) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("1.0"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("1.1"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("2.0"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_update_static_property_ce(snailhttp_message_ce, SL("valid"), &_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 9, 0 TSRMLS_CC);
	add_assoc_long_ex(_1, SS("CONNECT"), 1);
	add_assoc_long_ex(_1, SS("DELETE"), 1);
	add_assoc_long_ex(_1, SS("GET"), 1);
	add_assoc_long_ex(_1, SS("HEAD"), 1);
	add_assoc_long_ex(_1, SS("OPTIONS"), 1);
	add_assoc_long_ex(_1, SS("PATCH"), 1);
	add_assoc_long_ex(_1, SS("POST"), 1);
	add_assoc_long_ex(_1, SS("PUT"), 1);
	add_assoc_long_ex(_1, SS("TRACE"), 1);
	zephir_update_static_property_ce(snailhttp_request_ce, SL("validMethods"), &_1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

