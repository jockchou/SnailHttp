
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Headers Interface
 *
 */
ZEPHIR_INIT_CLASS(SnailHttp_HeadersInterface) {

	ZEPHIR_REGISTER_INTERFACE(SnailHttp, HeadersInterface, snailhttp, headersinterface, snailhttp_headersinterface_method_entry);

	zend_class_implements(snailhttp_headersinterface_ce TSRMLS_CC, 1, snailhttp_collectioninterface_ce);
	return SUCCESS;

}

ZEPHIR_DOC_METHOD(SnailHttp_HeadersInterface, add);

ZEPHIR_DOC_METHOD(SnailHttp_HeadersInterface, normalizeKey);

