
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(SnailHttp_FactoryInterface) {

	ZEPHIR_REGISTER_INTERFACE(SnailHttp, FactoryInterface, snailhttp, factoryinterface, snailhttp_factoryinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(SnailHttp_FactoryInterface, makeRequest);

ZEPHIR_DOC_METHOD(SnailHttp_FactoryInterface, makeUri);

ZEPHIR_DOC_METHOD(SnailHttp_FactoryInterface, makeHeaders);

ZEPHIR_DOC_METHOD(SnailHttp_FactoryInterface, makeBody);

