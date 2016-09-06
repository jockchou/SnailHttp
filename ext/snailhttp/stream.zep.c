
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(SnailHttp_Stream) {

	ZEPHIR_REGISTER_CLASS(SnailHttp, Stream, snailhttp, stream, snailhttp_stream_method_entry, 0);

	zend_declare_property_null(snailhttp_stream_ce, SL("stream"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_stream_ce, SL("size"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_stream_ce, SL("seekable"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_stream_ce, SL("readable"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_stream_ce, SL("writable"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(snailhttp_stream_ce, SL("uri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/** @var array Hash of readable and writable stream types */
	zend_declare_property_null(snailhttp_stream_ce, SL("readWriteHash"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(snailhttp_stream_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("psr\\http\\message\\streaminterface") TSRMLS_CC));
	return SUCCESS;

}

PHP_METHOD(SnailHttp_Stream, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *stream, *meta = NULL, *mode = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_6 = NULL, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &stream);



	ZEPHIR_INIT_VAR(meta);
	ZVAL_NULL(meta);
	zephir_update_property_this(this_ptr, SL("stream"), stream TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&meta, "stream_get_meta_data", NULL, 1, _0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(mode);
	zephir_array_fetch_string(&mode, meta, SL("mode"), PH_NOISY, "snailhttp/Stream.zep", 28 TSRMLS_CC);
	zephir_array_fetch_string(&_1, meta, SL("seekable "), PH_NOISY | PH_READONLY, "snailhttp/Stream.zep", 29 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("seekable"), _1 TSRMLS_CC);
	_2 = zephir_fetch_static_property_ce(snailhttp_stream_ce, SL("readWriteHash") TSRMLS_CC);
	zephir_array_fetch_string(&_3, _2, SL("read"), PH_NOISY | PH_READONLY, "snailhttp/Stream.zep", 30 TSRMLS_CC);
	if (zephir_fast_in_array(mode, _3 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("readable"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("readable"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	_4 = zephir_fetch_static_property_ce(snailhttp_stream_ce, SL("readWriteHash") TSRMLS_CC);
	zephir_array_fetch_string(&_5, _4, SL("write"), PH_NOISY | PH_READONLY, "snailhttp/Stream.zep", 31 TSRMLS_CC);
	if (zephir_fast_in_array(mode, _5 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("writable"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("writable"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "uri", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getmetadata", NULL, 0, _7);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("uri"), _6 TSRMLS_CC);
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

	zval *_0, *_1$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_RESOURCE) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
		zephir_fclose(_1$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Stream, detach) {

	zval *result = NULL, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	if (!(Z_TYPE_P(_0) == IS_RESOURCE)) {
		RETURN_NULL();
	}
	result = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("stream"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
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

	zval *stats = NULL, *_0, *_1, *_2, *_4, *_3$$5, *_5$$6;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("size"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		RETURN_MM_MEMBER(this_ptr, "size");
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	if (!(Z_TYPE_P(_1) == IS_RESOURCE)) {
		RETURN_MM_NULL();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	if (zephir_is_true(_2)) {
		_3$$5 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "clearstatcache", NULL, 3, ZEPHIR_GLOBAL(global_true), _3$$5);
		zephir_check_call_status();
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&stats, "fstat", NULL, 4, _4);
	zephir_check_call_status();
	if (zephir_array_isset_string(stats, SS("size"))) {
		zephir_array_fetch_string(&_5$$6, stats, SL("size"), PH_NOISY | PH_READONLY, "snailhttp/Stream.zep", 99 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("size"), _5$$6 TSRMLS_CC);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Unable to determine stream position", "snailhttp/Stream.zep", 112);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Stream is not seekable", "snailhttp/Stream.zep", 131);
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
		zephir_throw_exception_debug(_5$$4, "snailhttp/Stream.zep", 133 TSRMLS_CC);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Cannot write to a non-writable stream", "snailhttp/Stream.zep", 152);
		return;
	}
	zephir_update_property_this(this_ptr, SL("size"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(result);
	zephir_fwrite(result, _1, str TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(result)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Write to stream fail", "snailhttp/Stream.zep", 160);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Cannot read from non-readable stream", "snailhttp/Stream.zep", 176);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, length);
	ZEPHIR_CALL_FUNCTION(&result, "fread", NULL, 9, _1, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(result)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Read from stream fail", "snailhttp/Stream.zep", 182);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Read contents from stream fail", "snailhttp/Stream.zep", 192);
		return;
	}
	RETURN_CCTOR(contents);

}

PHP_METHOD(SnailHttp_Stream, getMetadata) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *meta = NULL, *_0, *_2, *_1$$3, *_3$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key);

	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(meta);
	ZVAL_NULL(meta);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	if (!(Z_TYPE_P(_0) == IS_RESOURCE)) {
		ZEPHIR_INIT_VAR(_1$$3);
		if (zephir_is_true(key)) {
			ZVAL_NULL(_1$$3);
		} else {
			array_init(_1$$3);
		}
		RETURN_CCTOR(_1$$3);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("stream"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&meta, "stream_get_meta_data", NULL, 1, _2);
	zephir_check_call_status();
	if (!(zephir_is_true(key))) {
		RETURN_CCTOR(meta);
	} else {
		ZEPHIR_INIT_VAR(_3$$5);
		if (zephir_array_isset(meta, key)) {
			zephir_array_fetch(&_3$$5, meta, key, PH_NOISY, "snailhttp/Stream.zep", 211 TSRMLS_CC);
		} else {
			ZVAL_NULL(_3$$5);
		}
		RETURN_CCTOR(_3$$5);
	}

}

void zephir_init_static_properties_SnailHttp_Stream(TSRMLS_D) {

	zval *_2 = NULL;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 6, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "r", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "r+", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "w+", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "a+", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "x+", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "c+", 1);
	zephir_array_fast_append(_1, _2);
	zephir_array_update_string(&_0, SL("read"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	zephir_create_array(_1, 9, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "r+", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "w", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "w+", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "a", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "a+", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "x", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "x+", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "c", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "c+", 1);
	zephir_array_fast_append(_1, _2);
	zephir_array_update_string(&_0, SL("write"), &_1, PH_COPY | PH_SEPARATE);
	zephir_update_static_property_ce(snailhttp_stream_ce, SL("readWriteHash"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

