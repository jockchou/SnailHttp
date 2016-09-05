
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_SNAILHTTP_H
#define PHP_SNAILHTTP_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_SNAILHTTP_NAME        "snailhttp"
#define PHP_SNAILHTTP_VERSION     "0.0.1"
#define PHP_SNAILHTTP_EXTNAME     "snailhttp"
#define PHP_SNAILHTTP_AUTHOR      ""
#define PHP_SNAILHTTP_ZEPVERSION  "0.9.4a-dev-cbfe80715d"
#define PHP_SNAILHTTP_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(snailhttp)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(snailhttp)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(snailhttp)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(snailhttp_globals_id, zend_snailhttp_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (snailhttp_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_snailhttp_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(snailhttp_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(snailhttp_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def snailhttp_globals
#define zend_zephir_globals_def zend_snailhttp_globals

extern zend_module_entry snailhttp_module_entry;
#define phpext_snailhttp_ptr &snailhttp_module_entry

#endif
