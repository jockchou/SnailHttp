
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "snailhttp.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *snailhttp_collectioninterface_ce;
zend_class_entry *snailhttp_cookiesinterface_ce;
zend_class_entry *snailhttp_factoryinterface_ce;
zend_class_entry *snailhttp_headersinterface_ce;
zend_class_entry *snailhttp_collection_ce;
zend_class_entry *snailhttp_stream_ce;
zend_class_entry *snailhttp_body_ce;
zend_class_entry *snailhttp_message_ce;
zend_class_entry *snailhttp_0__closure_ce;
zend_class_entry *snailhttp_1__closure_ce;
zend_class_entry *snailhttp_2__closure_ce;
zend_class_entry *snailhttp_3__closure_ce;
zend_class_entry *snailhttp_4__closure_ce;
zend_class_entry *snailhttp_5__closure_ce;
zend_class_entry *snailhttp_cookies_ce;
zend_class_entry *snailhttp_environment_ce;
zend_class_entry *snailhttp_factorydefault_ce;
zend_class_entry *snailhttp_headers_ce;
zend_class_entry *snailhttp_request_ce;
zend_class_entry *snailhttp_requestbody_ce;
zend_class_entry *snailhttp_uri_ce;

ZEND_DECLARE_MODULE_GLOBALS(snailhttp)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(snailhttp)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(SnailHttp_CollectionInterface);
	ZEPHIR_INIT(SnailHttp_CookiesInterface);
	ZEPHIR_INIT(SnailHttp_FactoryInterface);
	ZEPHIR_INIT(SnailHttp_HeadersInterface);
	ZEPHIR_INIT(SnailHttp_Collection);
	ZEPHIR_INIT(SnailHttp_Stream);
	ZEPHIR_INIT(SnailHttp_Body);
	ZEPHIR_INIT(SnailHttp_Message);
	ZEPHIR_INIT(SnailHttp_Cookies);
	ZEPHIR_INIT(SnailHttp_Environment);
	ZEPHIR_INIT(SnailHttp_FactoryDefault);
	ZEPHIR_INIT(SnailHttp_Headers);
	ZEPHIR_INIT(SnailHttp_Request);
	ZEPHIR_INIT(SnailHttp_RequestBody);
	ZEPHIR_INIT(SnailHttp_Uri);
	ZEPHIR_INIT(snailhttp_0__closure);
	ZEPHIR_INIT(snailhttp_1__closure);
	ZEPHIR_INIT(snailhttp_2__closure);
	ZEPHIR_INIT(snailhttp_3__closure);
	ZEPHIR_INIT(snailhttp_4__closure);
	ZEPHIR_INIT(snailhttp_5__closure);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(snailhttp)
{

	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_snailhttp_globals *snailhttp_globals TSRMLS_DC)
{
	snailhttp_globals->initialized = 0;

	/* Memory options */
	snailhttp_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	snailhttp_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	snailhttp_globals->cache_enabled = 1;

	/* Recursive Lock */
	snailhttp_globals->recursive_lock = 0;

	/* Static cache */
	memset(snailhttp_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_snailhttp_globals *snailhttp_globals TSRMLS_DC)
{

}

static PHP_RINIT_FUNCTION(snailhttp)
{

	zend_snailhttp_globals *snailhttp_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(snailhttp_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(snailhttp_globals_ptr TSRMLS_CC);

	zephir_init_static_properties_SnailHttp_Stream(TSRMLS_C);
	zephir_init_static_properties_SnailHttp_Message(TSRMLS_C);
	zephir_init_static_properties_SnailHttp_FactoryDefault(TSRMLS_C);
	zephir_init_static_properties_SnailHttp_Headers(TSRMLS_C);
	zephir_init_static_properties_SnailHttp_Request(TSRMLS_C);
	zephir_init_static_properties_SnailHttp_Uri(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(snailhttp)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(snailhttp)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_SNAILHTTP_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_SNAILHTTP_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_SNAILHTTP_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_SNAILHTTP_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_SNAILHTTP_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(snailhttp)
{
	php_zephir_init_globals(snailhttp_globals TSRMLS_CC);
	php_zephir_init_module_globals(snailhttp_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(snailhttp)
{

}


zend_function_entry php_snailhttp_functions[] = {
ZEND_FE_END

};

zend_module_entry snailhttp_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_SNAILHTTP_EXTNAME,
	php_snailhttp_functions,
	PHP_MINIT(snailhttp),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(snailhttp),
#else
	NULL,
#endif
	PHP_RINIT(snailhttp),
	PHP_RSHUTDOWN(snailhttp),
	PHP_MINFO(snailhttp),
	PHP_SNAILHTTP_VERSION,
	ZEND_MODULE_GLOBALS(snailhttp),
	PHP_GINIT(snailhttp),
	PHP_GSHUTDOWN(snailhttp),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_SNAILHTTP
ZEND_GET_MODULE(snailhttp)
#endif
