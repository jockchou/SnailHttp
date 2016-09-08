
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
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(SnailHttp_Collection) {

	ZEPHIR_REGISTER_CLASS(SnailHttp, Collection, snailhttp, collection, snailhttp_collection_method_entry, 0);

	zend_declare_property_null(snailhttp_collection_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	snailhttp_collection_ce->create_object = zephir_init_properties_SnailHttp_Collection;

	zend_class_implements(snailhttp_collection_ce TSRMLS_CC, 1, snailhttp_collectioninterface_ce);
	return SUCCESS;

}

PHP_METHOD(SnailHttp_Collection, __construct) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *items_param = NULL, *key = NULL, *val = NULL, **_2;
	zval *items = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &items_param);

	if (!items_param) {
		ZEPHIR_INIT_VAR(items);
		array_init(items);
	} else {
		zephir_get_arrval(items, items_param);
	}


	zephir_is_iterable(items, &_1, &_0, 0, 0, "snailhttp/Collection.zep", 19);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 0, key, val);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/********************************************************************************
 * Collection interface
 *******************************************************************************/
PHP_METHOD(SnailHttp_Collection, set) {

	zval *key_param = NULL, *val;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &val);

	zephir_get_strval(key, key_param);


	zephir_update_property_array(this_ptr, SL("data"), key, val TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Collection, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *def = NULL, *_0 = NULL, *_1 = NULL, *_2;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &def);

	zephir_get_strval(key, key_param);
	if (!def) {
		def = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "has", NULL, 0, key);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		zephir_array_fetch(&_0, _2, key, PH_NOISY, "snailhttp/Collection.zep", 34 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(_0, def);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(SnailHttp_Collection, replace) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *items_param = NULL, *key = NULL, *val = NULL, **_2;
	zval *items = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &items_param);

	if (!items_param) {
		ZEPHIR_INIT_VAR(items);
		array_init(items);
	} else {
		zephir_get_arrval(items, items_param);
	}


	zephir_is_iterable(items, &_1, &_0, 0, 0, "snailhttp/Collection.zep", 45);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 0, key, val);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Collection, all) {

	

	RETURN_MEMBER(this_ptr, "data");

}

PHP_METHOD(SnailHttp_Collection, keys) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_array_keys(return_value, _0 TSRMLS_CC);
	return;

}

PHP_METHOD(SnailHttp_Collection, has) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_key_exists(_0, key TSRMLS_CC));

}

PHP_METHOD(SnailHttp_Collection, remove) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_array_unset(&_0, key, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Collection, clear) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("data"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/********************************************************************************
 * ArrayAccess interface
 *******************************************************************************/
PHP_METHOD(SnailHttp_Collection, offsetExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Collection, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SnailHttp_Collection, offsetSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *val;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &val);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, key, val);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Collection, offsetUnset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SnailHttp_Collection, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/********************************************************************************
 * IteratorAggregate interface
 *******************************************************************************/
PHP_METHOD(SnailHttp_Collection, getIterator) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SS("\\arrayiterator") TSRMLS_CC));
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 1, _0);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object_value zephir_init_properties_SnailHttp_Collection(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("data"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

