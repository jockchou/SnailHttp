
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Collection Interface
 *
 */
ZEPHIR_INIT_CLASS(SnailHttp_CollectionInterface) {

	ZEPHIR_REGISTER_INTERFACE(SnailHttp, CollectionInterface, snailhttp, collectioninterface, snailhttp_collectioninterface_method_entry);

	zend_class_implements(snailhttp_collectioninterface_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(snailhttp_collectioninterface_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(snailhttp_collectioninterface_ce TSRMLS_CC, 1, zend_ce_aggregate);
	return SUCCESS;

}

ZEPHIR_DOC_METHOD(SnailHttp_CollectionInterface, set);

ZEPHIR_DOC_METHOD(SnailHttp_CollectionInterface, get);

ZEPHIR_DOC_METHOD(SnailHttp_CollectionInterface, replace);

ZEPHIR_DOC_METHOD(SnailHttp_CollectionInterface, all);

ZEPHIR_DOC_METHOD(SnailHttp_CollectionInterface, has);

ZEPHIR_DOC_METHOD(SnailHttp_CollectionInterface, remove);

ZEPHIR_DOC_METHOD(SnailHttp_CollectionInterface, clear);

