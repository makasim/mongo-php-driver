/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 2014 Hannes Magnusson                                  |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Hannes Magnusson <bjori@php.net>                             |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHONGO_H
#define PHONGO_H

/* External libs */
#include <bson.h>
#include <mongoc.h>

extern zend_module_entry phongo_module_entry;

#define PHONGO_VERSION_S "3.0.0"
#define PHONGO_VERSION   PHONGO_VERSION_S

#ifdef PHP_WIN32
#	define PHONGO_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHONGO_API __attribute__ ((visibility("default")))
#else
#	define PHONGO_API
#endif

#ifdef ZTS
#	include "TSRM.h"
#endif

ZEND_BEGIN_MODULE_GLOBALS(phongo)
	char *be_awesome;
ZEND_END_MODULE_GLOBALS(phongo)

#ifdef ZTS
#	define PHONGO_G(v) TSRMG(phongo_globals_id, zend_phongo_globals *, v)
#else
#	define PHONGO_G(v) (phongo_globals.v)
#endif

typedef struct {
	zend_object std;
} php_phongo_command_t;
typedef struct {
	zend_object std;
} php_phongo_commandcursor_t;
typedef struct {
	zend_object std;
} php_phongo_commandresult_t;
typedef struct {
	zend_object std;
} php_phongo_cursor_t;
typedef struct {
	zend_object std;
} php_phongo_cursorid_t;
typedef struct {
	zend_object std;
} php_phongo_deletebatch_t;
typedef struct {
	zend_object std;
} php_phongo_deleteresult_t;
typedef struct {
	zend_object std;
} php_phongo_generatedid_t;
typedef struct {
	zend_object std;
} php_phongo_insertbatch_t;
typedef struct {
	zend_object std;
} php_phongo_insertresult_t;
typedef struct {
	zend_object std;
} php_phongo_manager_t;
typedef struct {
	zend_object std;
} php_phongo_query_t;
typedef struct {
	zend_object std;
} php_phongo_querycursor_t;
typedef struct {
	zend_object std;
} php_phongo_readpreference_t;
typedef struct {
	zend_object std;
} php_phongo_server_t;
typedef struct {
	zend_object std;
} php_phongo_updatebatch_t;
typedef struct {
	zend_object std;
} php_phongo_updateresult_t;
typedef struct {
	zend_object std;
} php_phongo_writebatch_t;
typedef struct {
	zend_object std;
} php_phongo_writeconcernerror_t;
typedef struct {
	zend_object std;
} php_phongo_writeerror_t;
typedef struct {
	zend_object std;
} php_phongo_writeresult_t;

extern PHPAPI zend_class_entry *php_phongo_command_ce;
extern PHPAPI zend_class_entry *php_phongo_commandcursor_ce;
extern PHPAPI zend_class_entry *php_phongo_commandresult_ce;
extern PHPAPI zend_class_entry *php_phongo_cursor_ce;
extern PHPAPI zend_class_entry *php_phongo_cursorid_ce;
extern PHPAPI zend_class_entry *php_phongo_deletebatch_ce;
extern PHPAPI zend_class_entry *php_phongo_deleteresult_ce;
extern PHPAPI zend_class_entry *php_phongo_generatedid_ce;
extern PHPAPI zend_class_entry *php_phongo_insertbatch_ce;
extern PHPAPI zend_class_entry *php_phongo_insertresult_ce;
extern PHPAPI zend_class_entry *php_phongo_manager_ce;
extern PHPAPI zend_class_entry *php_phongo_query_ce;
extern PHPAPI zend_class_entry *php_phongo_querycursor_ce;
extern PHPAPI zend_class_entry *php_phongo_readpreference_ce;
extern PHPAPI zend_class_entry *php_phongo_server_ce;
extern PHPAPI zend_class_entry *php_phongo_updatebatch_ce;
extern PHPAPI zend_class_entry *php_phongo_updateresult_ce;
extern PHPAPI zend_class_entry *php_phongo_writebatch_ce;
extern PHPAPI zend_class_entry *php_phongo_writeconcernerror_ce;
extern PHPAPI zend_class_entry *php_phongo_writeerror_ce;
extern PHPAPI zend_class_entry *php_phongo_writeresult_ce;

typedef enum {
	PHONGO_INVALID_ARGUMENT = 1,
	PHONGO_RUNETIME_ERROR   = 2,
} php_phongo_error_domain_t;

PHONGO_API zend_class_entry* phongo_exception_from_mongoc_domain(mongoc_error_domain_t domain);
PHONGO_API zend_class_entry* phongo_exception_from_phongo_domain(php_phongo_error_domain_t domain);
PHONGO_API void phongo_throw_exception(php_phongo_error_domain_t domain TSRMLS_DC, char *message);

PHONGO_API zend_object_handlers *phongo_get_std_object_handlers(void);

PHP_MINIT_FUNCTION(bson);
PHP_MINIT_FUNCTION(Command);
PHP_MINIT_FUNCTION(CommandCursor);
PHP_MINIT_FUNCTION(CommandResult);
PHP_MINIT_FUNCTION(Cursor);
PHP_MINIT_FUNCTION(CursorId);
PHP_MINIT_FUNCTION(DeleteBatch);
PHP_MINIT_FUNCTION(DeleteResult);
PHP_MINIT_FUNCTION(GeneratedId);
PHP_MINIT_FUNCTION(InsertBatch);
PHP_MINIT_FUNCTION(InsertResult);
PHP_MINIT_FUNCTION(Manager);
PHP_MINIT_FUNCTION(Query);
PHP_MINIT_FUNCTION(QueryCursor);
PHP_MINIT_FUNCTION(ReadPreference);
PHP_MINIT_FUNCTION(Server);
PHP_MINIT_FUNCTION(UpdateBatch);
PHP_MINIT_FUNCTION(UpdateResult);
PHP_MINIT_FUNCTION(WriteBatch);
PHP_MINIT_FUNCTION(WriteConcernError);
PHP_MINIT_FUNCTION(WriteError);
PHP_MINIT_FUNCTION(WriteResult);
#endif /* PHONGO_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
