
extern zend_class_entry *snailhttp_stream_ce;

ZEPHIR_INIT_CLASS(SnailHttp_Stream);

PHP_METHOD(SnailHttp_Stream, __construct);
PHP_METHOD(SnailHttp_Stream, __toString);
PHP_METHOD(SnailHttp_Stream, __destruct);
PHP_METHOD(SnailHttp_Stream, close);
PHP_METHOD(SnailHttp_Stream, detach);
PHP_METHOD(SnailHttp_Stream, getSize);
PHP_METHOD(SnailHttp_Stream, tell);
PHP_METHOD(SnailHttp_Stream, eof);
PHP_METHOD(SnailHttp_Stream, isSeekable);
PHP_METHOD(SnailHttp_Stream, seek);
PHP_METHOD(SnailHttp_Stream, rewind);
PHP_METHOD(SnailHttp_Stream, isWritable);
PHP_METHOD(SnailHttp_Stream, write);
PHP_METHOD(SnailHttp_Stream, isReadable);
PHP_METHOD(SnailHttp_Stream, read);
PHP_METHOD(SnailHttp_Stream, getContents);
PHP_METHOD(SnailHttp_Stream, getMetadata);
zend_object_value zephir_init_properties_SnailHttp_Stream(zend_class_entry *class_type TSRMLS_DC);
void zephir_init_static_properties_SnailHttp_Stream(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_stream___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_stream_seek, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, whence)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_stream_write, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_stream_read, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailhttp_stream_getmetadata, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailhttp_stream_method_entry) {
	PHP_ME(SnailHttp_Stream, __construct, arginfo_snailhttp_stream___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(SnailHttp_Stream, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Stream, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(SnailHttp_Stream, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Stream, detach, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Stream, getSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Stream, tell, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Stream, eof, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Stream, isSeekable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Stream, seek, arginfo_snailhttp_stream_seek, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Stream, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Stream, isWritable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Stream, write, arginfo_snailhttp_stream_write, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Stream, isReadable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Stream, read, arginfo_snailhttp_stream_read, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Stream, getContents, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailHttp_Stream, getMetadata, arginfo_snailhttp_stream_getmetadata, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
