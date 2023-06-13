typedef void* (*sqlite3_aggregate_context_fn_ptr_t)(sqlite3_context*, int);
typedef int (*sqlite3_aggregate_count_fn_ptr_t)(sqlite3_context*);
typedef int (*sqlite3_auto_extension_fn_ptr_t)(void (*)(void));
typedef int (*sqlite3_autovacuum_pages_fn_ptr_t)(sqlite3*, unsigned int (*)(void*, const char*, unsigned int, unsigned int, unsigned int), void*, void (*)(void*));
typedef int (*sqlite3_backup_finish_fn_ptr_t)(sqlite3_backup*);
typedef sqlite3_backup* (*sqlite3_backup_init_fn_ptr_t)(sqlite3*, const char*, sqlite3*, const char*);
typedef int (*sqlite3_backup_pagecount_fn_ptr_t)(sqlite3_backup*);
typedef int (*sqlite3_backup_remaining_fn_ptr_t)(sqlite3_backup*);
typedef int (*sqlite3_backup_step_fn_ptr_t)(sqlite3_backup*, int);
typedef int (*sqlite3_bind_blob_fn_ptr_t)(sqlite3_stmt*, int, const void*, int, void (*)(void*));
typedef int (*sqlite3_bind_blob64_fn_ptr_t)(sqlite3_stmt*, int, const void*, sqlite3_uint64, void (*)(void*));
typedef int (*sqlite3_bind_double_fn_ptr_t)(sqlite3_stmt*, int, double);
typedef int (*sqlite3_bind_int_fn_ptr_t)(sqlite3_stmt*, int, int);
typedef int (*sqlite3_bind_int64_fn_ptr_t)(sqlite3_stmt*, int, sqlite_int64);
typedef int (*sqlite3_bind_null_fn_ptr_t)(sqlite3_stmt*, int);
typedef int (*sqlite3_bind_parameter_count_fn_ptr_t)(sqlite3_stmt*);
typedef int (*sqlite3_bind_parameter_index_fn_ptr_t)(sqlite3_stmt*, const char*);
typedef const char* (*sqlite3_bind_parameter_name_fn_ptr_t)(sqlite3_stmt*, int);
typedef int (*sqlite3_bind_pointer_fn_ptr_t)(sqlite3_stmt*, int, void*, const char*, void (*)(void*));
typedef int (*sqlite3_bind_text_fn_ptr_t)(sqlite3_stmt*, int, const char*, int, void (*)(void*));
typedef int (*sqlite3_bind_text16_fn_ptr_t)(sqlite3_stmt*, int, const void*, int, void (*)(void*));
typedef int (*sqlite3_bind_text64_fn_ptr_t)(sqlite3_stmt*, int, const char*, sqlite3_uint64, void (*)(void*), unsigned char);
typedef int (*sqlite3_bind_value_fn_ptr_t)(sqlite3_stmt*, int, const sqlite3_value*);
typedef int (*sqlite3_bind_zeroblob_fn_ptr_t)(sqlite3_stmt*, int, int);
typedef int (*sqlite3_bind_zeroblob64_fn_ptr_t)(sqlite3_stmt*, int, sqlite3_uint64);
typedef int (*sqlite3_blob_bytes_fn_ptr_t)(sqlite3_blob*);
typedef int (*sqlite3_blob_close_fn_ptr_t)(sqlite3_blob*);
typedef int (*sqlite3_blob_open_fn_ptr_t)(sqlite3*, const char*, const char*, const char*, sqlite3_int64, int, sqlite3_blob**);
typedef int (*sqlite3_blob_read_fn_ptr_t)(sqlite3_blob*, void*, int, int);
typedef int (*sqlite3_blob_reopen_fn_ptr_t)(sqlite3_blob*, sqlite3_int64);
typedef int (*sqlite3_blob_write_fn_ptr_t)(sqlite3_blob*, const void*, int, int);
typedef int (*sqlite3_busy_handler_fn_ptr_t)(sqlite3*, int (*)(void*, int), void*);
typedef int (*sqlite3_busy_timeout_fn_ptr_t)(sqlite3*, int);
typedef int (*sqlite3_cancel_auto_extension_fn_ptr_t)(void (*)(void));
typedef int (*sqlite3_changes_fn_ptr_t)(sqlite3*);
typedef sqlite3_int64 (*sqlite3_changes64_fn_ptr_t)(sqlite3*);
typedef int (*sqlite3_clear_bindings_fn_ptr_t)(sqlite3_stmt*);
typedef int (*sqlite3_close_fn_ptr_t)(sqlite3*);
typedef int (*sqlite3_close_v2_fn_ptr_t)(sqlite3*);
typedef int (*sqlite3_collation_needed_fn_ptr_t)(sqlite3*, void*, void (*)(void*, sqlite3*, int, const char*));
typedef int (*sqlite3_collation_needed16_fn_ptr_t)(sqlite3*, void*, void (*)(void*, sqlite3*, int, const void*));
typedef const void* (*sqlite3_column_blob_fn_ptr_t)(sqlite3_stmt*, int);
typedef int (*sqlite3_column_bytes_fn_ptr_t)(sqlite3_stmt*, int);
typedef int (*sqlite3_column_bytes16_fn_ptr_t)(sqlite3_stmt*, int);
typedef int (*sqlite3_column_count_fn_ptr_t)(sqlite3_stmt*);
typedef const char* (*sqlite3_column_database_name_fn_ptr_t)(sqlite3_stmt*, int);
typedef const void* (*sqlite3_column_database_name16_fn_ptr_t)(sqlite3_stmt*, int);
typedef const char* (*sqlite3_column_decltype_fn_ptr_t)(sqlite3_stmt*, int);
typedef const void* (*sqlite3_column_decltype16_fn_ptr_t)(sqlite3_stmt*, int);
typedef double (*sqlite3_column_double_fn_ptr_t)(sqlite3_stmt*, int);
typedef int (*sqlite3_column_int_fn_ptr_t)(sqlite3_stmt*, int);
typedef sqlite_int64 (*sqlite3_column_int64_fn_ptr_t)(sqlite3_stmt*, int);
typedef const char* (*sqlite3_column_name_fn_ptr_t)(sqlite3_stmt*, int);
typedef const void* (*sqlite3_column_name16_fn_ptr_t)(sqlite3_stmt*, int);
typedef const char* (*sqlite3_column_origin_name_fn_ptr_t)(sqlite3_stmt*, int);
typedef const void* (*sqlite3_column_origin_name16_fn_ptr_t)(sqlite3_stmt*, int);
typedef const char* (*sqlite3_column_table_name_fn_ptr_t)(sqlite3_stmt*, int);
typedef const void* (*sqlite3_column_table_name16_fn_ptr_t)(sqlite3_stmt*, int);
typedef const unsigned char* (*sqlite3_column_text_fn_ptr_t)(sqlite3_stmt*, int);
typedef const void* (*sqlite3_column_text16_fn_ptr_t)(sqlite3_stmt*, int);
typedef int (*sqlite3_column_type_fn_ptr_t)(sqlite3_stmt*, int);
typedef sqlite3_value* (*sqlite3_column_value_fn_ptr_t)(sqlite3_stmt*, int);
typedef void* (*sqlite3_commit_hook_fn_ptr_t)(sqlite3*, int (*)(void*), void*);
typedef const char* (*sqlite3_compileoption_get_fn_ptr_t)(int);
typedef int (*sqlite3_compileoption_used_fn_ptr_t)(const char*);
typedef int (*sqlite3_complete_fn_ptr_t)(const char*);
typedef int (*sqlite3_complete16_fn_ptr_t)(const void*);
typedef sqlite3* (*sqlite3_context_db_handle_fn_ptr_t)(sqlite3_context*);
typedef int (*sqlite3_create_collation_fn_ptr_t)(sqlite3*, const char*, int, void*, int (*)(void*, int, const void*, int, const void*));
typedef int (*sqlite3_create_collation_v2_fn_ptr_t)(sqlite3*, const char*, int, void*, int (*)(void*, int, const void*, int, const void*), void (*)(void*));
typedef int (*sqlite3_create_collation16_fn_ptr_t)(sqlite3*, const void*, int, void*, int (*)(void*, int, const void*, int, const void*));
typedef const char* (*sqlite3_create_filename_fn_ptr_t)(const char*, const char*, const char*, int, const char**);
typedef int (*sqlite3_create_function_fn_ptr_t)(sqlite3*, const char*, int, int, void*, void (*)(sqlite3_context*, int, sqlite3_value**), void (*)(sqlite3_context*, int, sqlite3_value**), void (*)(sqlite3_context*));
typedef int (*sqlite3_create_function_v2_fn_ptr_t)(sqlite3*, const char*, int, int, void*, void (*)(sqlite3_context*, int, sqlite3_value**), void (*)(sqlite3_context*, int, sqlite3_value**), void (*)(sqlite3_context*), void (*)(void*));
typedef int (*sqlite3_create_function16_fn_ptr_t)(sqlite3*, const void*, int, int, void*, void (*)(sqlite3_context*, int, sqlite3_value**), void (*)(sqlite3_context*, int, sqlite3_value**), void (*)(sqlite3_context*));
typedef int (*sqlite3_create_module_fn_ptr_t)(sqlite3*, const char*, const sqlite3_module*, void*);
typedef int (*sqlite3_create_module_v2_fn_ptr_t)(sqlite3*, const char*, const sqlite3_module*, void*, void (*)(void*));
typedef int (*sqlite3_create_window_function_fn_ptr_t)(sqlite3*, const char*, int, int, void*, void (*)(sqlite3_context*, int, sqlite3_value**), void (*)(sqlite3_context*), void (*)(sqlite3_context*), void (*)(sqlite3_context*, int, sqlite3_value**), void (*)(void*));
typedef int (*sqlite3_data_count_fn_ptr_t)(sqlite3_stmt*);
typedef sqlite3_file* (*sqlite3_database_file_object_fn_ptr_t)(const char*);
typedef int (*sqlite3_db_cacheflush_fn_ptr_t)(sqlite3*);
typedef const char* (*sqlite3_db_filename_fn_ptr_t)(sqlite3*, const char*);
typedef sqlite3* (*sqlite3_db_handle_fn_ptr_t)(sqlite3_stmt*);
typedef sqlite3_mutex* (*sqlite3_db_mutex_fn_ptr_t)(sqlite3*);
typedef int (*sqlite3_db_readonly_fn_ptr_t)(sqlite3*, const char*);
typedef int (*sqlite3_db_release_memory_fn_ptr_t)(sqlite3*);
typedef int (*sqlite3_db_status_fn_ptr_t)(sqlite3*, int, int*, int*, int);
typedef int (*sqlite3_declare_vtab_fn_ptr_t)(sqlite3*, const char*);
typedef int (*sqlite3_deserialize_fn_ptr_t)(sqlite3*, const char*, unsigned char*, sqlite3_int64, sqlite3_int64, unsigned);
typedef int (*sqlite3_drop_modules_fn_ptr_t)(sqlite3*, const char**);
typedef int (*sqlite3_enable_load_extension_fn_ptr_t)(sqlite3*, int);
typedef int (*sqlite3_enable_shared_cache_fn_ptr_t)(int);
typedef int (*sqlite3_errcode_fn_ptr_t)(sqlite3*);
typedef const char* (*sqlite3_errmsg_fn_ptr_t)(sqlite3*);
typedef const void* (*sqlite3_errmsg16_fn_ptr_t)(sqlite3*);
typedef int (*sqlite3_error_offset_fn_ptr_t)(sqlite3*);
typedef const char* (*sqlite3_errstr_fn_ptr_t)(int);
typedef int (*sqlite3_exec_fn_ptr_t)(sqlite3*, const char*, sqlite3_callback, void*, char**);
typedef char* (*sqlite3_expanded_sql_fn_ptr_t)(sqlite3_stmt*);
typedef int (*sqlite3_expired_fn_ptr_t)(sqlite3_stmt*);
typedef int (*sqlite3_extended_errcode_fn_ptr_t)(sqlite3*);
typedef int (*sqlite3_extended_result_codes_fn_ptr_t)(sqlite3*, int);
typedef int (*sqlite3_file_control_fn_ptr_t)(sqlite3*, const char*, int, void*);
typedef const char* (*sqlite3_filename_database_fn_ptr_t)(const char*);
typedef const char* (*sqlite3_filename_journal_fn_ptr_t)(const char*);
typedef const char* (*sqlite3_filename_wal_fn_ptr_t)(const char*);
typedef int (*sqlite3_finalize_fn_ptr_t)(sqlite3_stmt*);
typedef void (*sqlite3_free_fn_ptr_t)(void*);
typedef void (*sqlite3_free_filename_fn_ptr_t)(const char*);
typedef void (*sqlite3_free_table_fn_ptr_t)(char**);
typedef int (*sqlite3_get_autocommit_fn_ptr_t)(sqlite3*);
typedef void* (*sqlite3_get_auxdata_fn_ptr_t)(sqlite3_context*, int);
typedef int (*sqlite3_get_table_fn_ptr_t)(sqlite3*, const char*, char***, int*, int*, char**);
typedef int (*sqlite3_global_recover_fn_ptr_t)(void);
typedef sqlite3_int64 (*sqlite3_hard_heap_limit64_fn_ptr_t)(sqlite3_int64);
typedef int (*sqlite3_initialize_fn_ptr_t)(void);
typedef void (*sqlite3_interrupt_fn_ptr_t)(sqlite3*);
typedef int (*sqlite3_key_fn_ptr_t)(sqlite3*, const void*, int);
typedef int (*sqlite3_key_v2_fn_ptr_t)(sqlite3*, const char*, const void*, int);
typedef int (*sqlite3_keyword_check_fn_ptr_t)(const char*, int);
typedef int (*sqlite3_keyword_count_fn_ptr_t)(void);
typedef int (*sqlite3_keyword_name_fn_ptr_t)(int, const char**, int*);
typedef sqlite_int64 (*sqlite3_last_insert_rowid_fn_ptr_t)(sqlite3*);
typedef const char* (*sqlite3_libversion_fn_ptr_t)(void);
typedef int (*sqlite3_libversion_number_fn_ptr_t)(void);
typedef int (*sqlite3_limit_fn_ptr_t)(sqlite3*, int, int);
typedef int (*sqlite3_load_extension_fn_ptr_t)(sqlite3*, const char*, const char*, char**);
typedef void* (*sqlite3_malloc_fn_ptr_t)(int);
typedef void* (*sqlite3_malloc64_fn_ptr_t)(sqlite3_uint64);
typedef int (*sqlite3_memory_alarm_fn_ptr_t)(void (*)(void*, sqlite3_int64, int), void*, sqlite3_int64);
typedef sqlite3_int64 (*sqlite3_memory_highwater_fn_ptr_t)(int);
typedef sqlite3_int64 (*sqlite3_memory_used_fn_ptr_t)(void);
typedef sqlite3_uint64 (*sqlite3_msize_fn_ptr_t)(void*);
typedef sqlite3_mutex* (*sqlite3_mutex_alloc_fn_ptr_t)(int);
typedef void (*sqlite3_mutex_enter_fn_ptr_t)(sqlite3_mutex*);
typedef void (*sqlite3_mutex_free_fn_ptr_t)(sqlite3_mutex*);
typedef void (*sqlite3_mutex_leave_fn_ptr_t)(sqlite3_mutex*);
typedef int (*sqlite3_mutex_try_fn_ptr_t)(sqlite3_mutex*);
typedef sqlite3_stmt* (*sqlite3_next_stmt_fn_ptr_t)(sqlite3*, sqlite3_stmt*);
typedef int (*sqlite3_open_fn_ptr_t)(const char*, sqlite3**);
typedef int (*sqlite3_open_v2_fn_ptr_t)(const char*, sqlite3**, int, const char*);
typedef int (*sqlite3_open16_fn_ptr_t)(const void*, sqlite3**);
typedef int (*sqlite3_os_end_fn_ptr_t)(void);
typedef int (*sqlite3_os_init_fn_ptr_t)(void);
typedef int (*sqlite3_overload_function_fn_ptr_t)(sqlite3*, const char*, int);
typedef int (*sqlite3_prepare_fn_ptr_t)(sqlite3*, const char*, int, sqlite3_stmt**, const char**);
typedef int (*sqlite3_prepare_v2_fn_ptr_t)(sqlite3*, const char*, int, sqlite3_stmt**, const char**);
typedef int (*sqlite3_prepare_v3_fn_ptr_t)(sqlite3*, const char*, int, unsigned int, sqlite3_stmt**, const char**);
typedef int (*sqlite3_prepare16_fn_ptr_t)(sqlite3*, const void*, int, sqlite3_stmt**, const void**);
typedef int (*sqlite3_prepare16_v2_fn_ptr_t)(sqlite3*, const void*, int, sqlite3_stmt**, const void**);
typedef int (*sqlite3_prepare16_v3_fn_ptr_t)(sqlite3*, const void*, int, unsigned int, sqlite3_stmt**, const void**);
typedef void* (*sqlite3_profile_fn_ptr_t)(sqlite3*, void (*)(void*, const char*, sqlite_uint64), void*);
typedef void (*sqlite3_progress_handler_fn_ptr_t)(sqlite3*, int, int (*)(void*), void*);
typedef void (*sqlite3_randomness_fn_ptr_t)(int, void*);
typedef void* (*sqlite3_realloc_fn_ptr_t)(void*, int);
typedef void* (*sqlite3_realloc64_fn_ptr_t)(void*, sqlite3_uint64);
typedef int (*sqlite3_rekey_fn_ptr_t)(sqlite3*, const void*, int);
typedef int (*sqlite3_rekey_v2_fn_ptr_t)(sqlite3*, const char*, const void*, int);
typedef int (*sqlite3_release_memory_fn_ptr_t)(int);
typedef int (*sqlite3_reset_fn_ptr_t)(sqlite3_stmt*);
typedef void (*sqlite3_reset_auto_extension_fn_ptr_t)(void);
typedef void (*sqlite3_result_blob_fn_ptr_t)(sqlite3_context*, const void*, int, void (*)(void*));
typedef void (*sqlite3_result_blob64_fn_ptr_t)(sqlite3_context*, const void*, sqlite3_uint64, void (*)(void*));
typedef void (*sqlite3_result_double_fn_ptr_t)(sqlite3_context*, double);
typedef void (*sqlite3_result_error_fn_ptr_t)(sqlite3_context*, const char*, int);
typedef void (*sqlite3_result_error_code_fn_ptr_t)(sqlite3_context*, int);
typedef void (*sqlite3_result_error_nomem_fn_ptr_t)(sqlite3_context*);
typedef void (*sqlite3_result_error_toobig_fn_ptr_t)(sqlite3_context*);
typedef void (*sqlite3_result_error16_fn_ptr_t)(sqlite3_context*, const void*, int);
typedef void (*sqlite3_result_int_fn_ptr_t)(sqlite3_context*, int);
typedef void (*sqlite3_result_int64_fn_ptr_t)(sqlite3_context*, sqlite_int64);
typedef void (*sqlite3_result_null_fn_ptr_t)(sqlite3_context*);
typedef void (*sqlite3_result_pointer_fn_ptr_t)(sqlite3_context*, void*, const char*, void (*)(void*));
typedef void (*sqlite3_result_subtype_fn_ptr_t)(sqlite3_context*, unsigned int);
typedef void (*sqlite3_result_text_fn_ptr_t)(sqlite3_context*, const char*, int, void (*)(void*));
typedef void (*sqlite3_result_text16_fn_ptr_t)(sqlite3_context*, const void*, int, void (*)(void*));
typedef void (*sqlite3_result_text16be_fn_ptr_t)(sqlite3_context*, const void*, int, void (*)(void*));
typedef void (*sqlite3_result_text16le_fn_ptr_t)(sqlite3_context*, const void*, int, void (*)(void*));
typedef void (*sqlite3_result_text64_fn_ptr_t)(sqlite3_context*, const char*, sqlite3_uint64, void (*)(void*), unsigned char);
typedef void (*sqlite3_result_value_fn_ptr_t)(sqlite3_context*, sqlite3_value*);
typedef void (*sqlite3_result_zeroblob_fn_ptr_t)(sqlite3_context*, int);
typedef int (*sqlite3_result_zeroblob64_fn_ptr_t)(sqlite3_context*, sqlite3_uint64);
typedef void* (*sqlite3_rollback_hook_fn_ptr_t)(sqlite3*, void (*)(void*), void*);
typedef int (*sqlite3_rtree_geometry_callback_fn_ptr_t)(sqlite3*, const char*, int (*)(sqlite3_rtree_geometry*, int, sqlite3_rtree_dbl*, int*), void*);
typedef int (*sqlite3_rtree_query_callback_fn_ptr_t)(sqlite3*, const char*, int (*)(sqlite3_rtree_query_info*), void*, void (*)(void*));
typedef unsigned char* (*sqlite3_serialize_fn_ptr_t)(sqlite3*, const char*, sqlite3_int64*, unsigned int);
typedef int (*sqlite3_set_authorizer_fn_ptr_t)(sqlite3*, int (*)(void*, int, const char*, const char*, const char*, const char*), void*);
typedef void (*sqlite3_set_auxdata_fn_ptr_t)(sqlite3_context*, int, void*, void (*)(void*));
typedef void (*sqlite3_set_last_insert_rowid_fn_ptr_t)(sqlite3*, sqlite3_int64);
typedef int (*sqlite3_shutdown_fn_ptr_t)(void);
typedef int (*sqlite3_sleep_fn_ptr_t)(int);
typedef int (*sqlite3_snapshot_cmp_fn_ptr_t)(sqlite3_snapshot*, sqlite3_snapshot*);
typedef void (*sqlite3_snapshot_free_fn_ptr_t)(sqlite3_snapshot*);
typedef int (*sqlite3_snapshot_get_fn_ptr_t)(sqlite3*, const char*, sqlite3_snapshot**);
typedef int (*sqlite3_snapshot_open_fn_ptr_t)(sqlite3*, const char*, sqlite3_snapshot*);
typedef int (*sqlite3_snapshot_recover_fn_ptr_t)(sqlite3*, const char*);
typedef void (*sqlite3_soft_heap_limit_fn_ptr_t)(int);
typedef sqlite3_int64 (*sqlite3_soft_heap_limit64_fn_ptr_t)(sqlite3_int64);
typedef const char* (*sqlite3_sourceid_fn_ptr_t)(void);
typedef const char* (*sqlite3_sql_fn_ptr_t)(sqlite3_stmt*);
typedef int (*sqlite3_status_fn_ptr_t)(int, int*, int*, int);
typedef int (*sqlite3_status64_fn_ptr_t)(int, sqlite3_int64*, sqlite3_int64*, int);
typedef int (*sqlite3_step_fn_ptr_t)(sqlite3_stmt*);
typedef int (*sqlite3_stmt_busy_fn_ptr_t)(sqlite3_stmt*);
typedef int (*sqlite3_stmt_isexplain_fn_ptr_t)(sqlite3_stmt*);
typedef int (*sqlite3_stmt_readonly_fn_ptr_t)(sqlite3_stmt*);
typedef int (*sqlite3_stmt_status_fn_ptr_t)(sqlite3_stmt*, int, int);
typedef void (*sqlite3_str_append_fn_ptr_t)(sqlite3_str*, const char*, int);
typedef void (*sqlite3_str_appendall_fn_ptr_t)(sqlite3_str*, const char*);
typedef void (*sqlite3_str_appendchar_fn_ptr_t)(sqlite3_str*, int, char);
typedef int (*sqlite3_str_errcode_fn_ptr_t)(sqlite3_str*);
typedef char* (*sqlite3_str_finish_fn_ptr_t)(sqlite3_str*);
typedef int (*sqlite3_str_length_fn_ptr_t)(sqlite3_str*);
typedef sqlite3_str* (*sqlite3_str_new_fn_ptr_t)(sqlite3*);
typedef void (*sqlite3_str_reset_fn_ptr_t)(sqlite3_str*);
typedef char* (*sqlite3_str_value_fn_ptr_t)(sqlite3_str*);
typedef void (*sqlite3_str_vappendf_fn_ptr_t)(sqlite3_str*, const char*, va_list);
typedef int (*sqlite3_strglob_fn_ptr_t)(const char*, const char*);
typedef int (*sqlite3_stricmp_fn_ptr_t)(const char*, const char*);
typedef int (*sqlite3_strlike_fn_ptr_t)(const char*, const char*, unsigned int);
typedef int (*sqlite3_strnicmp_fn_ptr_t)(const char*, const char*, int);
typedef int (*sqlite3_system_errno_fn_ptr_t)(sqlite3*);
typedef int (*sqlite3_table_column_metadata_fn_ptr_t)(sqlite3*, const char*, const char*, const char*, char const**, char const**, int*, int*, int*);
typedef void (*sqlite3_thread_cleanup_fn_ptr_t)(void);
typedef int (*sqlite3_threadsafe_fn_ptr_t)(void);
typedef int (*sqlite3_total_changes_fn_ptr_t)(sqlite3*);
typedef sqlite3_int64 (*sqlite3_total_changes64_fn_ptr_t)(sqlite3*);
typedef void* (*sqlite3_trace_fn_ptr_t)(sqlite3*, void (*)(void*, const char*), void*);
typedef int (*sqlite3_trace_v2_fn_ptr_t)(sqlite3*, unsigned, int (*)(unsigned, void*, void*, void*), void*);
typedef int (*sqlite3_transfer_bindings_fn_ptr_t)(sqlite3_stmt*, sqlite3_stmt*);
typedef int (*sqlite3_txn_state_fn_ptr_t)(sqlite3*, const char*);
typedef void* (*sqlite3_update_hook_fn_ptr_t)(sqlite3*, void (*)(void*, int, char const*, char const*, sqlite_int64), void*);
typedef int (*sqlite3_uri_boolean_fn_ptr_t)(const char*, const char*, int);
typedef sqlite3_int64 (*sqlite3_uri_int64_fn_ptr_t)(const char*, const char*, sqlite3_int64);
typedef const char* (*sqlite3_uri_key_fn_ptr_t)(const char*, int);
typedef const char* (*sqlite3_uri_parameter_fn_ptr_t)(const char*, const char*);
typedef void* (*sqlite3_user_data_fn_ptr_t)(sqlite3_context*);
typedef const void* (*sqlite3_value_blob_fn_ptr_t)(sqlite3_value*);
typedef int (*sqlite3_value_bytes_fn_ptr_t)(sqlite3_value*);
typedef int (*sqlite3_value_bytes16_fn_ptr_t)(sqlite3_value*);
typedef double (*sqlite3_value_double_fn_ptr_t)(sqlite3_value*);
typedef sqlite3_value* (*sqlite3_value_dup_fn_ptr_t)(const sqlite3_value*);
typedef void (*sqlite3_value_free_fn_ptr_t)(sqlite3_value*);
typedef int (*sqlite3_value_frombind_fn_ptr_t)(sqlite3_value*);
typedef int (*sqlite3_value_int_fn_ptr_t)(sqlite3_value*);
typedef sqlite_int64 (*sqlite3_value_int64_fn_ptr_t)(sqlite3_value*);
typedef int (*sqlite3_value_nochange_fn_ptr_t)(sqlite3_value*);
typedef int (*sqlite3_value_numeric_type_fn_ptr_t)(sqlite3_value*);
typedef void* (*sqlite3_value_pointer_fn_ptr_t)(sqlite3_value*, const char*);
typedef unsigned int (*sqlite3_value_subtype_fn_ptr_t)(sqlite3_value*);
typedef const unsigned char* (*sqlite3_value_text_fn_ptr_t)(sqlite3_value*);
typedef const void* (*sqlite3_value_text16_fn_ptr_t)(sqlite3_value*);
typedef const void* (*sqlite3_value_text16be_fn_ptr_t)(sqlite3_value*);
typedef const void* (*sqlite3_value_text16le_fn_ptr_t)(sqlite3_value*);
typedef int (*sqlite3_value_type_fn_ptr_t)(sqlite3_value*);
typedef sqlite3_vfs* (*sqlite3_vfs_find_fn_ptr_t)(const char*);
typedef int (*sqlite3_vfs_register_fn_ptr_t)(sqlite3_vfs*, int);
typedef int (*sqlite3_vfs_unregister_fn_ptr_t)(sqlite3_vfs*);
typedef char* (*sqlite3_vmprintf_fn_ptr_t)(const char*, va_list);
typedef char* (*sqlite3_vsnprintf_fn_ptr_t)(int, char*, const char*, va_list);
typedef const char* (*sqlite3_vtab_collation_fn_ptr_t)(sqlite3_index_info*, int);
typedef int (*sqlite3_vtab_distinct_fn_ptr_t)(sqlite3_index_info*);
typedef int (*sqlite3_vtab_in_fn_ptr_t)(sqlite3_index_info*, int, int);
typedef int (*sqlite3_vtab_in_first_fn_ptr_t)(sqlite3_value*, sqlite3_value**);
typedef int (*sqlite3_vtab_in_next_fn_ptr_t)(sqlite3_value*, sqlite3_value**);
typedef int (*sqlite3_vtab_nochange_fn_ptr_t)(sqlite3_context*);
typedef int (*sqlite3_vtab_on_conflict_fn_ptr_t)(sqlite3*);
typedef int (*sqlite3_vtab_rhs_value_fn_ptr_t)(sqlite3_index_info*, int, sqlite3_value**);
typedef int (*sqlite3_wal_autocheckpoint_fn_ptr_t)(sqlite3*, int);
typedef int (*sqlite3_wal_checkpoint_fn_ptr_t)(sqlite3*, const char*);
typedef int (*sqlite3_wal_checkpoint_v2_fn_ptr_t)(sqlite3*, const char*, int, int*, int*);
typedef void* (*sqlite3_wal_hook_fn_ptr_t)(sqlite3*, int (*)(void*, sqlite3*, const char*, int), void*);
typedef int (*sqlite3_win32_is_nt_fn_ptr_t)(void);
typedef char* (*sqlite3_win32_mbcs_to_utf8_fn_ptr_t)(const char*);
typedef char* (*sqlite3_win32_mbcs_to_utf8_v2_fn_ptr_t)(const char*, int);
typedef int (*sqlite3_win32_set_directory_fn_ptr_t)(unsigned long, void*);
typedef int (*sqlite3_win32_set_directory16_fn_ptr_t)(unsigned long, const void*);
typedef int (*sqlite3_win32_set_directory8_fn_ptr_t)(unsigned long, const char*);
typedef void (*sqlite3_win32_sleep_fn_ptr_t)(DWORD);
typedef char* (*sqlite3_win32_unicode_to_utf8_fn_ptr_t)(LPCWSTR);
typedef char* (*sqlite3_win32_utf8_to_mbcs_fn_ptr_t)(const char*);
typedef char* (*sqlite3_win32_utf8_to_mbcs_v2_fn_ptr_t)(const char*, int);
typedef LPWSTR (*sqlite3_win32_utf8_to_unicode_fn_ptr_t)(const char*);
typedef void (*sqlite3_win32_write_debug_fn_ptr_t)(const char*, int);
