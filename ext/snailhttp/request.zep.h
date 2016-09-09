
extern zend_class_entry *snailhttp_request_ce;

ZEPHIR_INIT_CLASS(SnailHttp_Request);

PHP_METHOD(SnailHttp_Request, __construct);
PHP_METHOD(SnailHttp_Request, __clone);
PHP_METHOD(SnailHttp_Request, getMethod);
PHP_METHOD(SnailHttp_Request, withMethod);
PHP_METHOD(SnailHttp_Request, filterMethod);
PHP_METHOD(SnailHttp_Request, getRequestTarget);
PHP_METHOD(SnailHttp_Request, withRequestTarget);
PHP_METHOD(SnailHttp_Request, getUri);
PHP_METHOD(SnailHttp_Request, withUri);
PHP_METHOD(SnailHttp_Request, getCookieParams);
PHP_METHOD(SnailHttp_Request, withCookieParams);
PHP_METHOD(SnailHttp_Request, getQueryParams);
PHP_METHOD(SnailHttp_Request, withQueryParams);
PHP_METHOD(SnailHttp_Request, getUploadedFiles);
PHP_METHOD(SnailHttp_Request, withUploadedFiles);
PHP_METHOD(SnailHttp_Request, getServerParams);
PHP_METHOD(SnailHttp_Request, getAttributes);
PHP_METHOD(SnailHttp_Request, getAttribute);
PHP_METHOD(SnailHttp_Request, withAttribute);
PHP_METHOD(SnailHttp_Request, withoutAttribute);
PHP_METHOD(SnailHttp_Request, getParsedBody);
PHP_METHOD(SnailHttp_Request, withParsedBody);
PHP_METHOD(SnailHttp_Request, getContentType);
PHP_METHOD(SnailHttp_Request, getMediaType);
PHP_METHOD(SnailHttp_Request, registerMediaTypeParser);
zend_object_value zephir_init_properties_SnailHttp_Request(zend_class_entry *class_type TSRMLS_DC);
void zephir_init_static_properties_SnailHttp_Request(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_request___construct, 0, 0, 6)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_OBJ_INFO(0, uri, Psr\\Http\\Message\\UriInterface, 0)
	ZEND_ARG_OBJ_INFO(0, headers, SnailHttp\\HeadersInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, cookies, 0)
	ZEND_ARG_ARRAY_INFO(0, serverParams, 0)
	ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, uploadedFiles, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_request_withmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_request_filtermethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_request_withrequesttarget, 0, 0, 1)
	ZEND_ARG_INFO(0, requestTarget)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_request_withuri, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, uri, Psr\\Http\\Message\\UriInterface, 0)
	ZEND_ARG_INFO(0, preserveHost)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_request_withcookieparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, cookies, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_request_withqueryparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, query, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_request_withuploadedfiles, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, uploadedFiles, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_request_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, def)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_request_withattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_request_withoutattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_request_withparsedbody, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_request_registermediatypeparser, 0, 0, 2)
	ZEND_ARG_INFO(0, mediaType)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailhttp_request_method_entry) {
	PHP_ME(SnailHttp_Request, __construct, arginfo_snailhttp_request___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(SnailHttp_Request, __clone, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, withMethod, arginfo_snailhttp_request_withmethod, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, filterMethod, arginfo_snailhttp_request_filtermethod, ZEND_ACC_PROTECTED)
	PHP_ME(SnailHttp_Request, getRequestTarget, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, withRequestTarget, arginfo_snailhttp_request_withrequesttarget, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, getUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, withUri, arginfo_snailhttp_request_withuri, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, getCookieParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, withCookieParams, arginfo_snailhttp_request_withcookieparams, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, getQueryParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, withQueryParams, arginfo_snailhttp_request_withqueryparams, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, getUploadedFiles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, withUploadedFiles, arginfo_snailhttp_request_withuploadedfiles, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, getServerParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, getAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, getAttribute, arginfo_snailhttp_request_getattribute, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, withAttribute, arginfo_snailhttp_request_withattribute, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, withoutAttribute, arginfo_snailhttp_request_withoutattribute, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, getParsedBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, withParsedBody, arginfo_snailhttp_request_withparsedbody, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, getContentType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, getMediaType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Request, registerMediaTypeParser, arginfo_snailhttp_request_registermediatypeparser, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
