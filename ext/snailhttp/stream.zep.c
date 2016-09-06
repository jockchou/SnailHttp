
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(SnailHttp_Stream) {

	ZEPHIR_REGISTER_CLASS(SnailHttp, Stream, snailhttp, stream, snailhttp_stream_method_entry, 0);

	zend_declare_property_null(snailhttp_stream_ce, SL("stream"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(snailhttp_stream_ce, SL("size"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(snailhttp_stream_ce, SL("seekable"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(snailhttp_stream_ce, SL("readable"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(snailhttp_stream_ce, SL("writable"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(snailhttp_stream_ce, SL("uri"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(snailhttp_stream_ce, SL("customMetadata"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/** @var array Hash of readable and writable stream types */
	zend_declare_property_null(snailhttp_stream_ce, SL("readWriteHash"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	snailhttp_stream_ce->create_object = zephir_init_properties_SnailHttp_Stream;

	zend_class_implements(snailhttp_stream_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("psr\\http\\message\\streaminterface") TSRMLS_CC));
	return SUCCESS;

}

PHP_METHOD(SnailHttp_Stream, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *stream, *options_param = NULL, *meta = NULL, *_2, *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_10 = NULL, *_11, *_0$$3, *_1$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &stream, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(meta);
	ZVAL_NULL(meta);
	if (zephir_array_isset_string(options, SS("size"))) {
		zephir_array_fetch_string(&_0$$3, options, SL("size"), PH_NOISY | PH_READONLY, "snailhttp/Stream.zep", 36 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("size"), _0$$3 TSRMLS_CC);
	}
	if (zephir_array_isset_string(options, SS("metadata"))) {
		zephir_array_fetch_string(&_1$$4, options, SL("metadata"), PH_NOISY | PH_READONLY, "snailhttp/Stream.zep", 40 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("customMetadata"), _1$$4 TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("stream"), stream TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&meta, "stream_get_meta_data", NULL, 1, _2);
	zephir_check_call_status();
	zephir_array_fetch_string(&_3, meta, SL("seekable "), PH_NOISY | PH_READONLY, "snailhttp/Stream.zep", 46 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("seekable"), _3 TSRMLS_CC);
	_4 = zephir_fetch_static_property_ce(snailhttp_stream_ce, SL("readWriteHash") TSRMLS_CC);
	zephir_array_fetch_string(&_5, _4, SL("read"), PH_READONLY, "snailhttp/Stream.zep", 47 TSRMLS_CC);
	zephir_array_fetch_string(&_6, meta, SL("mode"), PH_READONLY, "snailhttp/Stream.zep", 47 TSRMLS_CC);
	if (zephir_array_isset(_5, _6)) {
		zephir_update_property_this(this_ptr, SL("readable"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("readable"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	_7 = zephir_fetch_static_property_ce(snailhttp_stream_ce, SL("readWriteHash") TSRMLS_CC);
	zephir_array_fetch_string(&_8, _7, SL("write"), PH_READONLY, "snailhttp/Stream.zep", 48 TSRMLS_CC);
	zephir_array_fetch_string(&_9, meta, SL("mode"), PH_READONLY, "snailhttp/Stream.zep", 48 TSRMLS_CC);
	if (zephir_array_isset(_8, _9)) {
		zephir_update_property_this(this_ptr, SL("writable"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("writable"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_11);
	ZVAL_STRING(_11, "uri", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "getmetadata", NULL, 0, _11);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("uri"), _10 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Stream, __toString) {

	zval *_3 = NULL;
	zval *_0, *_1, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 0, _0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "stream_get_contents", NULL, 2, _1);
	zephir_check_call_status();
	zephir_get_strval(_3, _2);
	RETURN_CTOR(_3);

}

/**
 * Closes the stream when the destructed
 */
PHP_METHOD(SnailHttp_Stream, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "close", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Stream, close) {

	zval *_0$$3, *_1$$4;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	if (zephir_isset_property(this_ptr, SS("stream") TSRMLS_CC)) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
		if (Z_TYPE_P(_0$$3) == IS_RESOURCE) {
			_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
			zephir_fclose(_1$$4 TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Stream, detach) {

	zval *result = NULL;


	if (!(zephir_isset_property(this_ptr, SS("stream") TSRMLS_CC))) {
		RETURN_NULL();
	}
	result = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	zephir_unset_property(this_ptr, "stream" TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("size"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("uri"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	if (0) {
		zephir_update_property_this(this_ptr, SL("readable"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("readable"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("writable"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("writable"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("seekable"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("seekable"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_CTORW(result);

}

PHP_METHOD(SnailHttp_Stream, getSize) {

	zval *stats = NULL, *_0, *_1, *_3, *_2$$5, *_4$$6;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("size"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		RETURN_MM_MEMBER(this_ptr, "size");
	}
	if (!(zephir_isset_property(this_ptr, SS("stream") TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	if (zephir_is_true(_1)) {
		_2$$5 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "clearstatcache", NULL, 3, ZEPHIR_GLOBAL(global_true), _2$$5);
		zephir_check_call_status();
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&stats, "fstat", NULL, 4, _3);
	zephir_check_call_status();
	if (zephir_array_isset_string(stats, SS("size"))) {
		zephir_array_fetch_string(&_4$$6, stats, SL("size"), PH_NOISY | PH_READONLY, "snailhttp/Stream.zep", 118 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("size"), _4$$6 TSRMLS_CC);
		RETURN_MM_MEMBER(this_ptr, "size");
	}
	RETURN_MM_NULL();

}

PHP_METHOD(SnailHttp_Stream, tell) {

	zval *result = NULL, *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&result, "ftell", NULL, 5, _0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(result)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Unable to determine stream position", "snailhttp/Stream.zep", 131);
		return;
	}
	RETURN_CCTOR(result);

}

PHP_METHOD(SnailHttp_Stream, eof) {

	zend_bool _1;
	zval *_0, *_2;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	_1 = !zephir_is_true(_0);
	if (!(_1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
		_1 = zephir_feof(_2 TSRMLS_CC);
	}
	RETURN_BOOL(_1);

}

PHP_METHOD(SnailHttp_Stream, isSeekable) {

	

	RETURN_MEMBER(this_ptr, "seekable");

}

PHP_METHOD(SnailHttp_Stream, seek) {

	zval *offset_param = NULL, *whence_param = NULL, *_0, *_1, _2, _3, *_4 = NULL, *_5$$4, _6$$4, _7$$4, _8$$4, *_9$$4 = NULL;
	int offset, whence, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &offset_param, &whence_param);

	offset = zephir_get_intval(offset_param);
	if (!whence_param) {
		whence = 0;
	} else {
		whence = zephir_get_intval(whence_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("seekable"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, offset);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, whence);
	ZEPHIR_CALL_FUNCTION(&_4, "fseek", NULL, 6, _1, &_2, &_3);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Stream is not seekable", "snailhttp/Stream.zep", 150);
		return;
	} else if (ZEPHIR_IS_LONG_IDENTICAL(_4, -1)) {
		ZEPHIR_INIT_VAR(_5$$4);
		object_init_ex(_5$$4, spl_ce_RuntimeException);
		ZEPHIR_SINIT_VAR(_6$$4);
		ZVAL_STRING(&_6$$4, "Unable to seek to stream position %d with whence %d", 0);
		ZEPHIR_SINIT_VAR(_7$$4);
		ZVAL_LONG(&_7$$4, offset);
		ZEPHIR_SINIT_VAR(_8$$4);
		ZVAL_LONG(&_8$$4, whence);
		ZEPHIR_CALL_FUNCTION(&_9$$4, "sprintf", NULL, 7, &_6$$4, &_7$$4, &_8$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _5$$4, "__construct", NULL, 8, _9$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$4, "snailhttp/Stream.zep", 152 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Stream, rewind) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Stream, isWritable) {

	

	RETURN_MEMBER(this_ptr, "writable");

}

PHP_METHOD(SnailHttp_Stream, write) {

	zval *str_param = NULL, *result = NULL, *_0, *_1;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("writable"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Cannot write to a non-writable stream", "snailhttp/Stream.zep", 171);
		return;
	}
	zephir_update_property_this(this_ptr, SL("size"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(result);
	zephir_fwrite(result, _1, str TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(result)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Write to stream fail", "snailhttp/Stream.zep", 179);
		return;
	}
	RETURN_CCTOR(result);

}

PHP_METHOD(SnailHttp_Stream, isReadable) {

	

	RETURN_MEMBER(this_ptr, "readable");

}

PHP_METHOD(SnailHttp_Stream, read) {

	zval *length_param = NULL, *result = NULL, *_0, *_1, _2;
	int length, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &length_param);

	length = zephir_get_intval(length_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("readable"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Cannot read from non-readable stream", "snailhttp/Stream.zep", 195);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, length);
	ZEPHIR_CALL_FUNCTION(&result, "fread", NULL, 9, _1, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(result)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Read from stream fail", "snailhttp/Stream.zep", 201);
		return;
	}
	RETURN_CCTOR(result);

}

PHP_METHOD(SnailHttp_Stream, getContents) {

	zval *contents = NULL, *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&contents, "stream_get_contents", NULL, 2, _0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(contents)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Read contents from stream fail", "snailhttp/Stream.zep", 211);
		return;
	}
	RETURN_CCTOR(contents);

}

PHP_METHOD(SnailHttp_Stream, getMetadata) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *meta = NULL, *_0, *_6, *_7, *_1$$3, *_2$$4, *_3$$4, *_4$$5, *_5$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key);

	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(meta);
	ZVAL_NULL(meta);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("customMetadata"), PH_NOISY_CC);
	if (!(zephir_isset_property(this_ptr, SS("stream") TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1$$3);
		if (zephir_is_true(key)) {
			ZVAL_NULL(_1$$3);
		} else {
			array_init(_1$$3);
		}
		RETURN_CCTOR(_1$$3);
	} else if (!(zephir_is_true(key))) {
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&meta, "stream_get_meta_data", NULL, 1, _2$$4);
		zephir_check_call_status();
		_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("customMetadata"), PH_NOISY_CC);
		zephir_fast_array_merge(return_value, &(_3$$4), &(meta) TSRMLS_CC);
		RETURN_MM();
	} else if (zephir_array_isset(_0, key)) {
		_4$$5 = zephir_fetch_nproperty_this(this_ptr, SL("customMetadata"), PH_NOISY_CC);
		zephir_array_fetch(&_5$$5, _4$$5, key, PH_NOISY | PH_READONLY, "snailhttp/Stream.zep", 227 TSRMLS_CC);
		RETURN_CTOR(_5$$5);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&meta, "stream_get_meta_data", NULL, 1, _6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_7);
	if (zephir_array_isset(meta, key)) {
		zephir_array_fetch(&_7, meta, key, PH_NOISY, "snailhttp/Stream.zep", 231 TSRMLS_CC);
	} else {
		ZVAL_NULL(_7);
	}
	RETURN_CCTOR(_7);

}

zend_object_value zephir_init_properties_SnailHttp_Stream(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("customMetadata"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("customMetadata"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

void zephir_init_static_properties_SnailHttp_Stream(TSRMLS_D) {

	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 16, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("r"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("w+"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("r+"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("x+"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("c+"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("rb"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("w+b"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("r+b"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("x+b"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("c+b"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("rt"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("w+t"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("r+t"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("x+t"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("c+t"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("a+"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("read"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	zephir_create_array(_1, 17, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("w"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("w+"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("rw"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("r+"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("x+"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("c+"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("wb"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("w+b"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("r+b"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("x+b"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("c+b"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("w+t"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("r+t"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("x+t"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("c+t"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("a"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("a+"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("write"), &_1, PH_COPY | PH_SEPARATE);
	zephir_update_static_property_ce(snailhttp_stream_ce, SL("readWriteHash"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

