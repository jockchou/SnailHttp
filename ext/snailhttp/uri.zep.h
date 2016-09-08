
extern zend_class_entry *snailhttp_uri_ce;

ZEPHIR_INIT_CLASS(SnailHttp_Uri);

PHP_METHOD(SnailHttp_Uri, __construct);
PHP_METHOD(SnailHttp_Uri, getScheme);
PHP_METHOD(SnailHttp_Uri, getUserInfo);
PHP_METHOD(SnailHttp_Uri, getAuthority);
PHP_METHOD(SnailHttp_Uri, getHost);
PHP_METHOD(SnailHttp_Uri, getPort);
PHP_METHOD(SnailHttp_Uri, hasStandardPort);
PHP_METHOD(SnailHttp_Uri, getPath);
PHP_METHOD(SnailHttp_Uri, getQuery);
PHP_METHOD(SnailHttp_Uri, getFragment);
PHP_METHOD(SnailHttp_Uri, withScheme);
PHP_METHOD(SnailHttp_Uri, withUserInfo);
PHP_METHOD(SnailHttp_Uri, withHost);
PHP_METHOD(SnailHttp_Uri, withPort);
PHP_METHOD(SnailHttp_Uri, withPath);
PHP_METHOD(SnailHttp_Uri, withQuery);
PHP_METHOD(SnailHttp_Uri, withFragment);
PHP_METHOD(SnailHttp_Uri, __toString);
PHP_METHOD(SnailHttp_Uri, filterScheme);
PHP_METHOD(SnailHttp_Uri, filterPort);
PHP_METHOD(SnailHttp_Uri, filterPath);
PHP_METHOD(SnailHttp_Uri, filterQuery);
void zephir_init_static_properties_SnailHttp_Uri(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_uri___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, scheme)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, fragment)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_uri_withscheme, 0, 0, 1)
	ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_uri_withuserinfo, 0, 0, 1)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_uri_withhost, 0, 0, 1)
	ZEND_ARG_INFO(0, host)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_uri_withport, 0, 0, 1)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_uri_withpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_uri_withquery, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_uri_withfragment, 0, 0, 1)
	ZEND_ARG_INFO(0, fragment)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_uri_filterscheme, 0, 0, 1)
	ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_uri_filterport, 0, 0, 1)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_uri_filterpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_uri_filterquery, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailhttp_uri_method_entry) {
	PHP_ME(SnailHttp_Uri, __construct, arginfo_snailhttp_uri___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(SnailHttp_Uri, getScheme, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Uri, getUserInfo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Uri, getAuthority, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Uri, getHost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Uri, getPort, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Uri, hasStandardPort, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(SnailHttp_Uri, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Uri, getQuery, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Uri, getFragment, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Uri, withScheme, arginfo_snailhttp_uri_withscheme, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Uri, withUserInfo, arginfo_snailhttp_uri_withuserinfo, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Uri, withHost, arginfo_snailhttp_uri_withhost, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Uri, withPort, arginfo_snailhttp_uri_withport, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Uri, withPath, arginfo_snailhttp_uri_withpath, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Uri, withQuery, arginfo_snailhttp_uri_withquery, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Uri, withFragment, arginfo_snailhttp_uri_withfragment, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Uri, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Uri, filterScheme, arginfo_snailhttp_uri_filterscheme, ZEND_ACC_PROTECTED)
	PHP_ME(SnailHttp_Uri, filterPort, arginfo_snailhttp_uri_filterport, ZEND_ACC_PROTECTED)
	PHP_ME(SnailHttp_Uri, filterPath, arginfo_snailhttp_uri_filterpath, ZEND_ACC_PROTECTED)
	PHP_ME(SnailHttp_Uri, filterQuery, arginfo_snailhttp_uri_filterquery, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
