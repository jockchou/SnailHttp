
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Cookies Interface
 */
ZEPHIR_INIT_CLASS(SnailHttp_CookiesInterface) {

	ZEPHIR_REGISTER_INTERFACE(SnailHttp, CookiesInterface, snailhttp, cookiesinterface, snailhttp_cookiesinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(SnailHttp_CookiesInterface, get);

ZEPHIR_DOC_METHOD(SnailHttp_CookiesInterface, set);

ZEPHIR_DOC_METHOD(SnailHttp_CookiesInterface, toHeaders);

ZEPHIR_DOC_METHOD(SnailHttp_CookiesInterface, parseHeader);

