
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
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(SnailHttp_Stream) {

	ZEPHIR_REGISTER_CLASS(SnailHttp, Stream, snailhttp, stream, snailhttp_stream_method_entry, 0);

	zend_class_implements(snailhttp_stream_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("psr\\http\\message\\streaminterface") TSRMLS_CC));
	return SUCCESS;

}

PHP_METHOD(SnailHttp_Stream, __toString) {

	


}

PHP_METHOD(SnailHttp_Stream, close) {

	


}

PHP_METHOD(SnailHttp_Stream, detach) {

	


}

PHP_METHOD(SnailHttp_Stream, getSize) {

	


}

PHP_METHOD(SnailHttp_Stream, tell) {

	


}

PHP_METHOD(SnailHttp_Stream, eof) {

	


}

PHP_METHOD(SnailHttp_Stream, isSeekable) {

	


}

PHP_METHOD(SnailHttp_Stream, seek) {

	zval *offset_param = NULL, *whence_param = NULL;
	int offset, whence;

	zephir_fetch_params(0, 2, 0, &offset_param, &whence_param);

	offset = zephir_get_intval(offset_param);
	whence = zephir_get_intval(whence_param);



}

PHP_METHOD(SnailHttp_Stream, rewind) {

	


}

PHP_METHOD(SnailHttp_Stream, isWritable) {

	


}

PHP_METHOD(SnailHttp_Stream, write) {

	zval *str_param = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);



}

PHP_METHOD(SnailHttp_Stream, isReadable) {

	


}

PHP_METHOD(SnailHttp_Stream, read) {

	zval *length_param = NULL;
	int length;

	zephir_fetch_params(0, 1, 0, &length_param);

	length = zephir_get_intval(length_param);



}

PHP_METHOD(SnailHttp_Stream, getContents) {

	


}

PHP_METHOD(SnailHttp_Stream, getMetadata) {

	zval *key = NULL;

	zephir_fetch_params(0, 0, 1, &key);

	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}



}

