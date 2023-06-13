DetourTransactionBegin();
DetourUpdateThread(GetCurrentThread());

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_AGGREGATE_CONTEXT], (PVOID)hook_sqlite3_aggregate_context);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_AGGREGATE_COUNT], (PVOID)hook_sqlite3_aggregate_count);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_AUTO_EXTENSION], (PVOID)hook_sqlite3_auto_extension);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_AUTOVACUUM_PAGES], (PVOID)hook_sqlite3_autovacuum_pages);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BACKUP_FINISH], (PVOID)hook_sqlite3_backup_finish);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BACKUP_INIT], (PVOID)hook_sqlite3_backup_init);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BACKUP_PAGECOUNT], (PVOID)hook_sqlite3_backup_pagecount);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BACKUP_REMAINING], (PVOID)hook_sqlite3_backup_remaining);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BACKUP_STEP], (PVOID)hook_sqlite3_backup_step);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BIND_BLOB], (PVOID)hook_sqlite3_bind_blob);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BIND_BLOB64], (PVOID)hook_sqlite3_bind_blob64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BIND_DOUBLE], (PVOID)hook_sqlite3_bind_double);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BIND_INT], (PVOID)hook_sqlite3_bind_int);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BIND_INT64], (PVOID)hook_sqlite3_bind_int64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BIND_NULL], (PVOID)hook_sqlite3_bind_null);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BIND_PARAMETER_COUNT], (PVOID)hook_sqlite3_bind_parameter_count);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BIND_PARAMETER_INDEX], (PVOID)hook_sqlite3_bind_parameter_index);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BIND_PARAMETER_NAME], (PVOID)hook_sqlite3_bind_parameter_name);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BIND_POINTER], (PVOID)hook_sqlite3_bind_pointer);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BIND_TEXT], (PVOID)hook_sqlite3_bind_text);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BIND_TEXT16], (PVOID)hook_sqlite3_bind_text16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BIND_TEXT64], (PVOID)hook_sqlite3_bind_text64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BIND_VALUE], (PVOID)hook_sqlite3_bind_value);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BIND_ZEROBLOB], (PVOID)hook_sqlite3_bind_zeroblob);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BIND_ZEROBLOB64], (PVOID)hook_sqlite3_bind_zeroblob64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BLOB_BYTES], (PVOID)hook_sqlite3_blob_bytes);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BLOB_CLOSE], (PVOID)hook_sqlite3_blob_close);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BLOB_OPEN], (PVOID)hook_sqlite3_blob_open);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BLOB_READ], (PVOID)hook_sqlite3_blob_read);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BLOB_REOPEN], (PVOID)hook_sqlite3_blob_reopen);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BLOB_WRITE], (PVOID)hook_sqlite3_blob_write);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BUSY_HANDLER], (PVOID)hook_sqlite3_busy_handler);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_BUSY_TIMEOUT], (PVOID)hook_sqlite3_busy_timeout);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CANCEL_AUTO_EXTENSION], (PVOID)hook_sqlite3_cancel_auto_extension);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CHANGES], (PVOID)hook_sqlite3_changes);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CHANGES64], (PVOID)hook_sqlite3_changes64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CLEAR_BINDINGS], (PVOID)hook_sqlite3_clear_bindings);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CLOSE], (PVOID)hook_sqlite3_close);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CLOSE_V2], (PVOID)hook_sqlite3_close_v2);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLLATION_NEEDED], (PVOID)hook_sqlite3_collation_needed);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLLATION_NEEDED16], (PVOID)hook_sqlite3_collation_needed16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_BLOB], (PVOID)hook_sqlite3_column_blob);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_BYTES], (PVOID)hook_sqlite3_column_bytes);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_BYTES16], (PVOID)hook_sqlite3_column_bytes16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_COUNT], (PVOID)hook_sqlite3_column_count);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_DATABASE_NAME], (PVOID)hook_sqlite3_column_database_name);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_DATABASE_NAME16], (PVOID)hook_sqlite3_column_database_name16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_DECLTYPE], (PVOID)hook_sqlite3_column_decltype);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_DECLTYPE16], (PVOID)hook_sqlite3_column_decltype16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_DOUBLE], (PVOID)hook_sqlite3_column_double);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_INT], (PVOID)hook_sqlite3_column_int);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_INT64], (PVOID)hook_sqlite3_column_int64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_NAME], (PVOID)hook_sqlite3_column_name);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_NAME16], (PVOID)hook_sqlite3_column_name16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_ORIGIN_NAME], (PVOID)hook_sqlite3_column_origin_name);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_ORIGIN_NAME16], (PVOID)hook_sqlite3_column_origin_name16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_TABLE_NAME], (PVOID)hook_sqlite3_column_table_name);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_TABLE_NAME16], (PVOID)hook_sqlite3_column_table_name16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_TEXT], (PVOID)hook_sqlite3_column_text);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_TEXT16], (PVOID)hook_sqlite3_column_text16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_TYPE], (PVOID)hook_sqlite3_column_type);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_VALUE], (PVOID)hook_sqlite3_column_value);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COMMIT_HOOK], (PVOID)hook_sqlite3_commit_hook);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COMPILEOPTION_GET], (PVOID)hook_sqlite3_compileoption_get);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COMPILEOPTION_USED], (PVOID)hook_sqlite3_compileoption_used);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COMPLETE], (PVOID)hook_sqlite3_complete);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_COMPLETE16], (PVOID)hook_sqlite3_complete16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CONTEXT_DB_HANDLE], (PVOID)hook_sqlite3_context_db_handle);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_COLLATION], (PVOID)hook_sqlite3_create_collation);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_COLLATION_V2], (PVOID)hook_sqlite3_create_collation_v2);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_COLLATION16], (PVOID)hook_sqlite3_create_collation16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_FILENAME], (PVOID)hook_sqlite3_create_filename);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_FUNCTION], (PVOID)hook_sqlite3_create_function);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_FUNCTION_V2], (PVOID)hook_sqlite3_create_function_v2);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_FUNCTION16], (PVOID)hook_sqlite3_create_function16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_MODULE], (PVOID)hook_sqlite3_create_module);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_MODULE_V2], (PVOID)hook_sqlite3_create_module_v2);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_WINDOW_FUNCTION], (PVOID)hook_sqlite3_create_window_function);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_DATA_COUNT], (PVOID)hook_sqlite3_data_count);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_DATABASE_FILE_OBJECT], (PVOID)hook_sqlite3_database_file_object);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_DB_CACHEFLUSH], (PVOID)hook_sqlite3_db_cacheflush);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_DB_FILENAME], (PVOID)hook_sqlite3_db_filename);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_DB_HANDLE], (PVOID)hook_sqlite3_db_handle);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_DB_MUTEX], (PVOID)hook_sqlite3_db_mutex);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_DB_READONLY], (PVOID)hook_sqlite3_db_readonly);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_DB_RELEASE_MEMORY], (PVOID)hook_sqlite3_db_release_memory);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_DB_STATUS], (PVOID)hook_sqlite3_db_status);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_DECLARE_VTAB], (PVOID)hook_sqlite3_declare_vtab);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_DESERIALIZE], (PVOID)hook_sqlite3_deserialize);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_DROP_MODULES], (PVOID)hook_sqlite3_drop_modules);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_ENABLE_LOAD_EXTENSION], (PVOID)hook_sqlite3_enable_load_extension);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_ENABLE_SHARED_CACHE], (PVOID)hook_sqlite3_enable_shared_cache);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_ERRCODE], (PVOID)hook_sqlite3_errcode);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_ERRMSG], (PVOID)hook_sqlite3_errmsg);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_ERRMSG16], (PVOID)hook_sqlite3_errmsg16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_ERROR_OFFSET], (PVOID)hook_sqlite3_error_offset);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_ERRSTR], (PVOID)hook_sqlite3_errstr);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_EXEC], (PVOID)hook_sqlite3_exec);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_EXPANDED_SQL], (PVOID)hook_sqlite3_expanded_sql);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_EXPIRED], (PVOID)hook_sqlite3_expired);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_EXTENDED_ERRCODE], (PVOID)hook_sqlite3_extended_errcode);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_EXTENDED_RESULT_CODES], (PVOID)hook_sqlite3_extended_result_codes);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_FILE_CONTROL], (PVOID)hook_sqlite3_file_control);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_FILENAME_DATABASE], (PVOID)hook_sqlite3_filename_database);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_FILENAME_JOURNAL], (PVOID)hook_sqlite3_filename_journal);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_FILENAME_WAL], (PVOID)hook_sqlite3_filename_wal);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_FINALIZE], (PVOID)hook_sqlite3_finalize);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_FREE], (PVOID)hook_sqlite3_free);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_FREE_FILENAME], (PVOID)hook_sqlite3_free_filename);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_FREE_TABLE], (PVOID)hook_sqlite3_free_table);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_GET_AUTOCOMMIT], (PVOID)hook_sqlite3_get_autocommit);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_GET_AUXDATA], (PVOID)hook_sqlite3_get_auxdata);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_GET_TABLE], (PVOID)hook_sqlite3_get_table);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_GLOBAL_RECOVER], (PVOID)hook_sqlite3_global_recover);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_HARD_HEAP_LIMIT64], (PVOID)hook_sqlite3_hard_heap_limit64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_INITIALIZE], (PVOID)hook_sqlite3_initialize);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_INTERRUPT], (PVOID)hook_sqlite3_interrupt);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_KEY], (PVOID)hook_sqlite3_key);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_KEY_V2], (PVOID)hook_sqlite3_key_v2);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_KEYWORD_CHECK], (PVOID)hook_sqlite3_keyword_check);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_KEYWORD_COUNT], (PVOID)hook_sqlite3_keyword_count);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_KEYWORD_NAME], (PVOID)hook_sqlite3_keyword_name);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_LAST_INSERT_ROWID], (PVOID)hook_sqlite3_last_insert_rowid);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_LIBVERSION], (PVOID)hook_sqlite3_libversion);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_LIBVERSION_NUMBER], (PVOID)hook_sqlite3_libversion_number);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_LIMIT], (PVOID)hook_sqlite3_limit);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_LOAD_EXTENSION], (PVOID)hook_sqlite3_load_extension);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_MALLOC], (PVOID)hook_sqlite3_malloc);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_MALLOC64], (PVOID)hook_sqlite3_malloc64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_MEMORY_ALARM], (PVOID)hook_sqlite3_memory_alarm);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_MEMORY_HIGHWATER], (PVOID)hook_sqlite3_memory_highwater);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_MEMORY_USED], (PVOID)hook_sqlite3_memory_used);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_MSIZE], (PVOID)hook_sqlite3_msize);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_MUTEX_ALLOC], (PVOID)hook_sqlite3_mutex_alloc);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_MUTEX_ENTER], (PVOID)hook_sqlite3_mutex_enter);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_MUTEX_FREE], (PVOID)hook_sqlite3_mutex_free);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_MUTEX_LEAVE], (PVOID)hook_sqlite3_mutex_leave);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_MUTEX_TRY], (PVOID)hook_sqlite3_mutex_try);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_NEXT_STMT], (PVOID)hook_sqlite3_next_stmt);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_OPEN], (PVOID)hook_sqlite3_open);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_OPEN_V2], (PVOID)hook_sqlite3_open_v2);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_OPEN16], (PVOID)hook_sqlite3_open16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_OS_END], (PVOID)hook_sqlite3_os_end);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_OS_INIT], (PVOID)hook_sqlite3_os_init);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_OVERLOAD_FUNCTION], (PVOID)hook_sqlite3_overload_function);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_PREPARE], (PVOID)hook_sqlite3_prepare);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_PREPARE_V2], (PVOID)hook_sqlite3_prepare_v2);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_PREPARE_V3], (PVOID)hook_sqlite3_prepare_v3);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_PREPARE16], (PVOID)hook_sqlite3_prepare16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_PREPARE16_V2], (PVOID)hook_sqlite3_prepare16_v2);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_PREPARE16_V3], (PVOID)hook_sqlite3_prepare16_v3);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_PROFILE], (PVOID)hook_sqlite3_profile);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_PROGRESS_HANDLER], (PVOID)hook_sqlite3_progress_handler);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RANDOMNESS], (PVOID)hook_sqlite3_randomness);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_REALLOC], (PVOID)hook_sqlite3_realloc);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_REALLOC64], (PVOID)hook_sqlite3_realloc64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_REKEY], (PVOID)hook_sqlite3_rekey);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_REKEY_V2], (PVOID)hook_sqlite3_rekey_v2);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RELEASE_MEMORY], (PVOID)hook_sqlite3_release_memory);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESET], (PVOID)hook_sqlite3_reset);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESET_AUTO_EXTENSION], (PVOID)hook_sqlite3_reset_auto_extension);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_BLOB], (PVOID)hook_sqlite3_result_blob);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_BLOB64], (PVOID)hook_sqlite3_result_blob64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_DOUBLE], (PVOID)hook_sqlite3_result_double);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_ERROR], (PVOID)hook_sqlite3_result_error);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_ERROR_CODE], (PVOID)hook_sqlite3_result_error_code);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_ERROR_NOMEM], (PVOID)hook_sqlite3_result_error_nomem);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_ERROR_TOOBIG], (PVOID)hook_sqlite3_result_error_toobig);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_ERROR16], (PVOID)hook_sqlite3_result_error16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_INT], (PVOID)hook_sqlite3_result_int);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_INT64], (PVOID)hook_sqlite3_result_int64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_NULL], (PVOID)hook_sqlite3_result_null);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_POINTER], (PVOID)hook_sqlite3_result_pointer);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_SUBTYPE], (PVOID)hook_sqlite3_result_subtype);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_TEXT], (PVOID)hook_sqlite3_result_text);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_TEXT16], (PVOID)hook_sqlite3_result_text16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_TEXT16BE], (PVOID)hook_sqlite3_result_text16be);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_TEXT16LE], (PVOID)hook_sqlite3_result_text16le);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_TEXT64], (PVOID)hook_sqlite3_result_text64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_VALUE], (PVOID)hook_sqlite3_result_value);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_ZEROBLOB], (PVOID)hook_sqlite3_result_zeroblob);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_ZEROBLOB64], (PVOID)hook_sqlite3_result_zeroblob64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_ROLLBACK_HOOK], (PVOID)hook_sqlite3_rollback_hook);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RTREE_GEOMETRY_CALLBACK], (PVOID)hook_sqlite3_rtree_geometry_callback);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_RTREE_QUERY_CALLBACK], (PVOID)hook_sqlite3_rtree_query_callback);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_SERIALIZE], (PVOID)hook_sqlite3_serialize);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_SET_AUTHORIZER], (PVOID)hook_sqlite3_set_authorizer);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_SET_AUXDATA], (PVOID)hook_sqlite3_set_auxdata);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_SET_LAST_INSERT_ROWID], (PVOID)hook_sqlite3_set_last_insert_rowid);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_SHUTDOWN], (PVOID)hook_sqlite3_shutdown);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_SLEEP], (PVOID)hook_sqlite3_sleep);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_SNAPSHOT_CMP], (PVOID)hook_sqlite3_snapshot_cmp);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_SNAPSHOT_FREE], (PVOID)hook_sqlite3_snapshot_free);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_SNAPSHOT_GET], (PVOID)hook_sqlite3_snapshot_get);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_SNAPSHOT_OPEN], (PVOID)hook_sqlite3_snapshot_open);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_SNAPSHOT_RECOVER], (PVOID)hook_sqlite3_snapshot_recover);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_SOFT_HEAP_LIMIT], (PVOID)hook_sqlite3_soft_heap_limit);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_SOFT_HEAP_LIMIT64], (PVOID)hook_sqlite3_soft_heap_limit64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_SOURCEID], (PVOID)hook_sqlite3_sourceid);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_SQL], (PVOID)hook_sqlite3_sql);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STATUS], (PVOID)hook_sqlite3_status);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STATUS64], (PVOID)hook_sqlite3_status64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STEP], (PVOID)hook_sqlite3_step);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STMT_BUSY], (PVOID)hook_sqlite3_stmt_busy);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STMT_ISEXPLAIN], (PVOID)hook_sqlite3_stmt_isexplain);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STMT_READONLY], (PVOID)hook_sqlite3_stmt_readonly);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STMT_STATUS], (PVOID)hook_sqlite3_stmt_status);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STR_APPEND], (PVOID)hook_sqlite3_str_append);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STR_APPENDALL], (PVOID)hook_sqlite3_str_appendall);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STR_APPENDCHAR], (PVOID)hook_sqlite3_str_appendchar);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STR_ERRCODE], (PVOID)hook_sqlite3_str_errcode);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STR_FINISH], (PVOID)hook_sqlite3_str_finish);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STR_LENGTH], (PVOID)hook_sqlite3_str_length);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STR_NEW], (PVOID)hook_sqlite3_str_new);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STR_RESET], (PVOID)hook_sqlite3_str_reset);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STR_VALUE], (PVOID)hook_sqlite3_str_value);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STR_VAPPENDF], (PVOID)hook_sqlite3_str_vappendf);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STRGLOB], (PVOID)hook_sqlite3_strglob);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STRICMP], (PVOID)hook_sqlite3_stricmp);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STRLIKE], (PVOID)hook_sqlite3_strlike);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_STRNICMP], (PVOID)hook_sqlite3_strnicmp);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_SYSTEM_ERRNO], (PVOID)hook_sqlite3_system_errno);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_TABLE_COLUMN_METADATA], (PVOID)hook_sqlite3_table_column_metadata);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_THREAD_CLEANUP], (PVOID)hook_sqlite3_thread_cleanup);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_THREADSAFE], (PVOID)hook_sqlite3_threadsafe);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_TOTAL_CHANGES], (PVOID)hook_sqlite3_total_changes);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_TOTAL_CHANGES64], (PVOID)hook_sqlite3_total_changes64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_TRACE], (PVOID)hook_sqlite3_trace);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_TRACE_V2], (PVOID)hook_sqlite3_trace_v2);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_TRANSFER_BINDINGS], (PVOID)hook_sqlite3_transfer_bindings);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_TXN_STATE], (PVOID)hook_sqlite3_txn_state);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_UPDATE_HOOK], (PVOID)hook_sqlite3_update_hook);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_URI_BOOLEAN], (PVOID)hook_sqlite3_uri_boolean);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_URI_INT64], (PVOID)hook_sqlite3_uri_int64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_URI_KEY], (PVOID)hook_sqlite3_uri_key);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_URI_PARAMETER], (PVOID)hook_sqlite3_uri_parameter);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_USER_DATA], (PVOID)hook_sqlite3_user_data);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_BLOB], (PVOID)hook_sqlite3_value_blob);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_BYTES], (PVOID)hook_sqlite3_value_bytes);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_BYTES16], (PVOID)hook_sqlite3_value_bytes16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_DOUBLE], (PVOID)hook_sqlite3_value_double);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_DUP], (PVOID)hook_sqlite3_value_dup);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_FREE], (PVOID)hook_sqlite3_value_free);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_FROMBIND], (PVOID)hook_sqlite3_value_frombind);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_INT], (PVOID)hook_sqlite3_value_int);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_INT64], (PVOID)hook_sqlite3_value_int64);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_NOCHANGE], (PVOID)hook_sqlite3_value_nochange);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_NUMERIC_TYPE], (PVOID)hook_sqlite3_value_numeric_type);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_POINTER], (PVOID)hook_sqlite3_value_pointer);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_SUBTYPE], (PVOID)hook_sqlite3_value_subtype);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_TEXT], (PVOID)hook_sqlite3_value_text);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_TEXT16], (PVOID)hook_sqlite3_value_text16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_TEXT16BE], (PVOID)hook_sqlite3_value_text16be);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_TEXT16LE], (PVOID)hook_sqlite3_value_text16le);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_TYPE], (PVOID)hook_sqlite3_value_type);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VFS_FIND], (PVOID)hook_sqlite3_vfs_find);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VFS_REGISTER], (PVOID)hook_sqlite3_vfs_register);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VFS_UNREGISTER], (PVOID)hook_sqlite3_vfs_unregister);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VMPRINTF], (PVOID)hook_sqlite3_vmprintf);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VSNPRINTF], (PVOID)hook_sqlite3_vsnprintf);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VTAB_COLLATION], (PVOID)hook_sqlite3_vtab_collation);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VTAB_DISTINCT], (PVOID)hook_sqlite3_vtab_distinct);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VTAB_IN], (PVOID)hook_sqlite3_vtab_in);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VTAB_IN_FIRST], (PVOID)hook_sqlite3_vtab_in_first);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VTAB_IN_NEXT], (PVOID)hook_sqlite3_vtab_in_next);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VTAB_NOCHANGE], (PVOID)hook_sqlite3_vtab_nochange);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VTAB_ON_CONFLICT], (PVOID)hook_sqlite3_vtab_on_conflict);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_VTAB_RHS_VALUE], (PVOID)hook_sqlite3_vtab_rhs_value);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_WAL_AUTOCHECKPOINT], (PVOID)hook_sqlite3_wal_autocheckpoint);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_WAL_CHECKPOINT], (PVOID)hook_sqlite3_wal_checkpoint);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_WAL_CHECKPOINT_V2], (PVOID)hook_sqlite3_wal_checkpoint_v2);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_WAL_HOOK], (PVOID)hook_sqlite3_wal_hook);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_IS_NT], (PVOID)hook_sqlite3_win32_is_nt);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_MBCS_TO_UTF8], (PVOID)hook_sqlite3_win32_mbcs_to_utf8);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_MBCS_TO_UTF8_V2], (PVOID)hook_sqlite3_win32_mbcs_to_utf8_v2);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_SET_DIRECTORY], (PVOID)hook_sqlite3_win32_set_directory);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_SET_DIRECTORY16], (PVOID)hook_sqlite3_win32_set_directory16);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_SET_DIRECTORY8], (PVOID)hook_sqlite3_win32_set_directory8);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_SLEEP], (PVOID)hook_sqlite3_win32_sleep);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_UNICODE_TO_UTF8], (PVOID)hook_sqlite3_win32_unicode_to_utf8);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_UTF8_TO_MBCS], (PVOID)hook_sqlite3_win32_utf8_to_mbcs);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_UTF8_TO_MBCS_V2], (PVOID)hook_sqlite3_win32_utf8_to_mbcs_v2);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_UTF8_TO_UNICODE], (PVOID)hook_sqlite3_win32_utf8_to_unicode);

DetourDetach(&(PVOID&)sqlite3orgFuncPointers[SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_WRITE_DEBUG], (PVOID)hook_sqlite3_win32_write_debug);


DetourTransactionCommit();

