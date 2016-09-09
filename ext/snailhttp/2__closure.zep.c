
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
#include "kernel/fcall.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(snailhttp_2__closure) {

	ZEPHIR_REGISTER_CLASS(snailhttp, 2__closure, snailhttp, 2__closure, snailhttp_2__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(snailhttp_2__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *input, *backup = NULL, *result = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input);



	ZEPHIR_CALL_FUNCTION(&backup, "libxml_disable_entity_loader", NULL, 40, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "simplexml_load_string", NULL, 41, input);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "libxml_disable_entity_loader", NULL, 40, backup);
	zephir_check_call_status();
	RETURN_CCTOR(result);

}

