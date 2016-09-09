
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(SnailHttp_Uri) {

	ZEPHIR_REGISTER_CLASS(SnailHttp, Uri, snailhttp, uri, snailhttp_uri_method_entry, 0);

	zend_declare_property_null(snailhttp_uri_ce, SL("schemeValid"), ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * Uri scheme (without "://" suffix)
	 *
	 * @var string
	 */
	zend_declare_property_string(snailhttp_uri_ce, SL("scheme"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Uri user
	 *
	 * @var string
	 */
	zend_declare_property_string(snailhttp_uri_ce, SL("user"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Uri password
	 *
	 * @var string
	 */
	zend_declare_property_string(snailhttp_uri_ce, SL("password"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Uri host
	 *
	 * @var string
	 */
	zend_declare_property_string(snailhttp_uri_ce, SL("host"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Uri port number
	 *
	 * @var null|int
	 */
	zend_declare_property_null(snailhttp_uri_ce, SL("port"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Uri path
	 *
	 * @var string
	 */
	zend_declare_property_string(snailhttp_uri_ce, SL("path"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Uri query string (without "?" prefix)
	 *
	 * @var string
	 */
	zend_declare_property_string(snailhttp_uri_ce, SL("query"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Uri fragment string (without "#" prefix)
	 *
	 * @var string
	 */
	zend_declare_property_string(snailhttp_uri_ce, SL("fragment"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(snailhttp_uri_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("psr\\http\\message\\uriinterface") TSRMLS_CC));
	return SUCCESS;

}

/**
 * Create new Uri.
 *
 * @param string $scheme   Uri scheme.
 * @param string $host     Uri host.
 * @param int    $port     Uri port number.
 * @param string $path     Uri path.
 * @param string $query    Uri query string.
 * @param string $fragment Uri fragment.
 * @param string $user     Uri user.
 * @param string $password Uri password.
 */
PHP_METHOD(SnailHttp_Uri, __construct) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *scheme_param = NULL, *host_param = NULL, *port = NULL, *path_param = NULL, *query_param = NULL, *fragment_param = NULL, *user_param = NULL, *password_param = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_5 = NULL;
	zval *scheme = NULL, *host = NULL, *path = NULL, *query = NULL, *fragment = NULL, *user = NULL, *password = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 6, &scheme_param, &host_param, &port, &path_param, &query_param, &fragment_param, &user_param, &password_param);

	zephir_get_strval(scheme, scheme_param);
	zephir_get_strval(host, host_param);
	if (!port) {
		port = ZEPHIR_GLOBAL(global_null);
	}
	if (!path_param) {
		ZEPHIR_INIT_VAR(path);
		ZVAL_STRING(path, "/", 1);
	} else {
		zephir_get_strval(path, path_param);
	}
	if (!query_param) {
		ZEPHIR_INIT_VAR(query);
		ZVAL_STRING(query, "", 1);
	} else {
		zephir_get_strval(query, query_param);
	}
	if (!fragment_param) {
		ZEPHIR_INIT_VAR(fragment);
		ZVAL_STRING(fragment, "", 1);
	} else {
		zephir_get_strval(fragment, fragment_param);
	}
	if (!user_param) {
		ZEPHIR_INIT_VAR(user);
		ZVAL_STRING(user, "", 1);
	} else {
		zephir_get_strval(user, user_param);
	}
	if (!password_param) {
		ZEPHIR_INIT_VAR(password);
		ZVAL_STRING(password, "", 1);
	} else {
		zephir_get_strval(password, password_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filterscheme", NULL, 0, scheme);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("scheme"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("host"), host TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "filterport", NULL, 0, port);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("port"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	if (ZEPHIR_IS_EMPTY(path)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "/", 1);
	} else {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "filterpath", NULL, 0, path);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("path"), _2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "filterquery", &_4, 0, query);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("query"), _3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "filterquery", &_4, 0, fragment);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("fragment"), _5 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("user"), user TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("password"), password TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Uri, getScheme) {

	

	RETURN_MEMBER(this_ptr, "scheme");

}

PHP_METHOD(SnailHttp_Uri, getUserInfo) {

	zval *_0, *_1 = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("user"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("password"), PH_NOISY_CC);
	if (zephir_is_true(_2)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("password"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_CONCAT_SV(_1, ":", _3);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "", 1);
	}
	ZEPHIR_CONCAT_VV(return_value, _0, _1);
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Uri, getAuthority) {

	zval *userInfo = NULL, *host = NULL, *port = NULL, *_0 = NULL, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&userInfo, this_ptr, "getuserinfo", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&host, this_ptr, "gethost", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&port, this_ptr, "getport", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	if (zephir_is_true(userInfo)) {
		ZEPHIR_INIT_NVAR(_0);
		ZEPHIR_CONCAT_VS(_0, userInfo, "@");
	} else {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "", 1);
	}
	ZEPHIR_INIT_VAR(_1);
	if (Z_TYPE_P(port) != IS_NULL) {
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_CONCAT_SV(_1, ":", port);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "", 1);
	}
	ZEPHIR_CONCAT_VVV(return_value, _0, host, _1);
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Uri, getHost) {

	

	RETURN_MEMBER(this_ptr, "host");

}

PHP_METHOD(SnailHttp_Uri, getPort) {

	zend_bool _2;
	zval *_0, *_1, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("port"), PH_NOISY_CC);
	_2 = zephir_is_true(_1);
	if (_2) {
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "hasstandardport", NULL, 0);
		zephir_check_call_status();
		_2 = !zephir_is_true(_3);
	}
	if (_2) {
		zephir_read_property_this(&_0, this_ptr, SL("port"), PH_NOISY_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(SnailHttp_Uri, hasStandardPort) {

	zend_bool _1, _3, _5;
	zval *_0, *_2, *_4, *_6;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("scheme"), PH_NOISY_CC);
	_1 = ZEPHIR_IS_STRING_IDENTICAL(_0, "http");
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("port"), PH_NOISY_CC);
		_1 = ZEPHIR_IS_LONG_IDENTICAL(_2, 80);
	}
	_3 = _1;
	if (!(_3)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("scheme"), PH_NOISY_CC);
		_5 = ZEPHIR_IS_STRING_IDENTICAL(_4, "https");
		if (_5) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("port"), PH_NOISY_CC);
			_5 = ZEPHIR_IS_LONG_IDENTICAL(_6, 443);
		}
		_3 = _5;
	}
	RETURN_BOOL(_3);

}

PHP_METHOD(SnailHttp_Uri, getPath) {

	

	RETURN_MEMBER(this_ptr, "path");

}

PHP_METHOD(SnailHttp_Uri, getQuery) {

	

	RETURN_MEMBER(this_ptr, "query");

}

PHP_METHOD(SnailHttp_Uri, getFragment) {

	

	RETURN_MEMBER(this_ptr, "fragment");

}

PHP_METHOD(SnailHttp_Uri, withScheme) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *scheme_param = NULL, *cloneObj = NULL, *_0 = NULL;
	zval *scheme = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &scheme_param);

	zephir_get_strval(scheme, scheme_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filterscheme", NULL, 0, scheme);
	zephir_check_call_status();
	zephir_get_strval(scheme, _0);
	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(cloneObj, SL("scheme"), scheme TSRMLS_CC);
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Uri, withUserInfo) {

	zval *user_param = NULL, *password = NULL, *cloneObj = NULL, *_0 = NULL;
	zval *user = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &user_param, &password);

	zephir_get_strval(user, user_param);
	if (!password) {
		password = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(cloneObj, SL("user"), user TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	if (zephir_is_true(password)) {
		ZEPHIR_CPY_WRT(_0, password);
	} else {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "", 1);
	}
	zephir_update_property_zval(cloneObj, SL("password"), _0 TSRMLS_CC);
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Uri, withHost) {

	zval *host_param = NULL, *cloneObj = NULL;
	zval *host = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &host_param);

	zephir_get_strval(host, host_param);


	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(cloneObj, SL("host"), host TSRMLS_CC);
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Uri, withPort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *port = NULL, *cloneObj = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &port);

	ZEPHIR_SEPARATE_PARAM(port);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filterport", NULL, 0, port);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(port, _0);
	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(cloneObj, SL("port"), port TSRMLS_CC);
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Uri, withPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *cloneObj = NULL, *_0 = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	if (!(Z_TYPE_P(path) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Uri path must be a string", "snailhttp/Uri.zep", 208);
		return;
	}
	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filterpath", NULL, 0, path);
	zephir_check_call_status();
	zephir_update_property_zval(cloneObj, SL("path"), _0 TSRMLS_CC);
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Uri, withQuery) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *query_param = NULL, *cloneObj = NULL, _2, *_3 = NULL;
	zval *query = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query_param);

	zephir_get_strval(query, query_param);


	_0 = !(Z_TYPE_P(query) == IS_STRING);
	if (_0) {
		_0 = !((zephir_method_exists_ex(query, SS("__tostring") TSRMLS_CC) == SUCCESS));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Uri query must be a string", "snailhttp/Uri.zep", 223);
		return;
	}
	zephir_get_strval(_1, query);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "?", 0);
	ZEPHIR_INIT_NVAR(query);
	zephir_fast_trim(query, _1, &_2, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "filterquery", NULL, 0, query);
	zephir_check_call_status();
	zephir_update_property_zval(cloneObj, SL("query"), _3 TSRMLS_CC);
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Uri, withFragment) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *fragment_param = NULL, *cloneObj = NULL, _2, *_3 = NULL;
	zval *fragment = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fragment_param);

	zephir_get_strval(fragment, fragment_param);


	_0 = !(Z_TYPE_P(fragment) == IS_STRING);
	if (_0) {
		_0 = !((zephir_method_exists_ex(fragment, SS("__tostring") TSRMLS_CC) == SUCCESS));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Uri fragment must be a string", "snailhttp/Uri.zep", 238);
		return;
	}
	zephir_get_strval(_1, fragment);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "#", 0);
	ZEPHIR_INIT_NVAR(fragment);
	zephir_fast_trim(fragment, _1, &_2, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	ZEPHIR_INIT_VAR(cloneObj);
	if (zephir_clone(cloneObj, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "filterquery", NULL, 0, fragment);
	zephir_check_call_status();
	zephir_update_property_zval(cloneObj, SL("fragment"), _3 TSRMLS_CC);
	RETURN_CCTOR(cloneObj);

}

PHP_METHOD(SnailHttp_Uri, __toString) {

	zval *scheme = NULL, *authority = NULL, *path = NULL, *query = NULL, *fragment = NULL, *_0, _1, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&scheme, this_ptr, "getscheme", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&authority, this_ptr, "getauthority", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&path, this_ptr, "getpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, this_ptr, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&fragment, this_ptr, "getfragment", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/", 0);
	zephir_fast_trim(_0, path, &_1, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "/", _0);
	ZEPHIR_CPY_WRT(path, _2);
	ZEPHIR_INIT_LNVAR(_2);
	if (zephir_is_true(scheme)) {
		ZEPHIR_INIT_NVAR(_2);
		ZEPHIR_CONCAT_VS(_2, scheme, ":");
	} else {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "", 1);
	}
	ZEPHIR_INIT_VAR(_3);
	if (zephir_is_true(authority)) {
		ZEPHIR_INIT_NVAR(_3);
		ZEPHIR_CONCAT_SV(_3, "//", authority);
	} else {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "", 1);
	}
	ZEPHIR_INIT_VAR(_4);
	if (zephir_is_true(query)) {
		ZEPHIR_INIT_NVAR(_4);
		ZEPHIR_CONCAT_SV(_4, "?", query);
	} else {
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "", 1);
	}
	ZEPHIR_INIT_VAR(_5);
	if (zephir_is_true(fragment)) {
		ZEPHIR_INIT_NVAR(_5);
		ZEPHIR_CONCAT_SV(_5, "#", fragment);
	} else {
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "", 1);
	}
	ZEPHIR_CONCAT_VVVVV(return_value, _2, _3, path, _4, _5);
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Uri, filterScheme) {

	zend_bool _0;
	zval *scheme_param = NULL, *_1, _2, _3, *_4;
	zval *scheme = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &scheme_param);

	zephir_get_strval(scheme, scheme_param);


	_0 = !(Z_TYPE_P(scheme) == IS_STRING);
	if (_0) {
		_0 = !((zephir_method_exists_ex(scheme, SS("__tostring") TSRMLS_CC) == SUCCESS));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Uri scheme must be a string", "snailhttp/Uri.zep", 271);
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, scheme);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "://", 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "", 0);
	ZEPHIR_INIT_NVAR(scheme);
	zephir_fast_str_replace(&scheme, &_2, &_3, _1 TSRMLS_CC);
	_4 = zephir_fetch_static_property_ce(snailhttp_uri_ce, SL("schemeValid") TSRMLS_CC);
	if (!(zephir_array_isset(_4, scheme))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Uri scheme must be one of: \"\", \"https\", \"http\"", "snailhttp/Uri.zep", 277);
		return;
	}
	RETURN_CTOR(scheme);

}

PHP_METHOD(SnailHttp_Uri, filterPort) {

	zend_bool _0, _2, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *port, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &port);



	_0 = Z_TYPE_P(port) == IS_NULL;
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_integer", NULL, 31, port);
		zephir_check_call_status();
		_2 = zephir_is_true(_1);
		if (_2) {
			_3 = ZEPHIR_GE_LONG(port, 1);
			if (_3) {
				_3 = ZEPHIR_LE_LONG(port, 65535);
			}
			_2 = _3;
		}
		_0 = _2;
	}
	if (_0) {
		RETVAL_ZVAL(port, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Uri port must be null or an integer between 1 and 65535 (inclusive)", "snailhttp/Uri.zep", 290);
	return;

}

PHP_METHOD(SnailHttp_Uri, filterPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *_0 = NULL, *_1;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_NVAR(_0);
	zephir_create_closure_ex(_0, NULL, snailhttp_4__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "/(?:[^a-zA-Z0-9_\\-\\.~:@&=\\+\\$,\\/;%]+|%(?![A-Fa-f0-9]{2}))/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace_callback", NULL, 32, _1, _0, path);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Uri, filterQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *query_param = NULL, *_0 = NULL, *_1;
	zval *query = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query_param);

	zephir_get_strval(query, query_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_NVAR(_0);
	zephir_create_closure_ex(_0, NULL, snailhttp_5__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "/(?:[^a-zA-Z0-9_\\-\\.~!\\$&\\'\\(\\)\\*\\+,;=%:@\\/\\?]+|%(?![A-Fa-f0-9]{2}))/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace_callback", NULL, 32, _1, _0, query);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

void zephir_init_static_properties_SnailHttp_Uri(TSRMLS_D) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL(""), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("https"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("http"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_update_static_property_ce(snailhttp_uri_ce, SL("schemeValid"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

