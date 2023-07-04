SQLITE3_PROXY_EXPORT void* hook_sqlite3_aggregate_context(sqlite3_context* pCtx, int nBytes)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_aggregate_context"));
    sqlite3_aggregate_context_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_aggregate_context_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_AGGREGATE_CONTEXT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_AGGREGATE_CONTEXT)
        SQLITE3_PROXY_HANDLE_SQLITE3_AGGREGATE_CONTEXT();
    #endif
    return orgFnPtr(pCtx, nBytes);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_aggregate_count(sqlite3_context* pCtx)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_aggregate_count"));
    sqlite3_aggregate_count_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_aggregate_count_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_AGGREGATE_COUNT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_AGGREGATE_COUNT)
        SQLITE3_PROXY_HANDLE_SQLITE3_AGGREGATE_COUNT();
    #endif
    return orgFnPtr(pCtx);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_auto_extension(void (*pfn)(void))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_auto_extension"));
    sqlite3_auto_extension_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_auto_extension_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_AUTO_EXTENSION);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_AUTO_EXTENSION)
        SQLITE3_PROXY_HANDLE_SQLITE3_AUTO_EXTENSION();
    #endif
    return orgFnPtr(pfn);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_autovacuum_pages(sqlite3* pDb, unsigned int (*pfn)(void*, const char*, unsigned int, unsigned int, unsigned int), void* pv, void (*pfn2)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_autovacuum_pages"));
    sqlite3_autovacuum_pages_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_autovacuum_pages_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_AUTOVACUUM_PAGES);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_AUTOVACUUM_PAGES)
        SQLITE3_PROXY_HANDLE_SQLITE3_AUTOVACUUM_PAGES();
    #endif
    return orgFnPtr(pDb, pfn, pv, pfn2);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_backup_finish(sqlite3_backup* pBckp)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_backup_finish"));
    sqlite3_backup_finish_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_backup_finish_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BACKUP_FINISH);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BACKUP_FINISH)
        SQLITE3_PROXY_HANDLE_SQLITE3_BACKUP_FINISH();
    #endif
    return orgFnPtr(pBckp);
}

SQLITE3_PROXY_EXPORT sqlite3_backup* hook_sqlite3_backup_init(sqlite3* pDb, const char* pcStr, sqlite3* pDb2, const char* pcStr2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_backup_init"));
    sqlite3_backup_init_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_backup_init_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BACKUP_INIT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BACKUP_INIT)
        SQLITE3_PROXY_HANDLE_SQLITE3_BACKUP_INIT();
    #endif
    return orgFnPtr(pDb, pcStr, pDb2, pcStr2);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_backup_pagecount(sqlite3_backup* pBckp)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_backup_pagecount"));
    sqlite3_backup_pagecount_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_backup_pagecount_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BACKUP_PAGECOUNT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BACKUP_PAGECOUNT)
        SQLITE3_PROXY_HANDLE_SQLITE3_BACKUP_PAGECOUNT();
    #endif
    return orgFnPtr(pBckp);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_backup_remaining(sqlite3_backup* pBckp)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_backup_remaining"));
    sqlite3_backup_remaining_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_backup_remaining_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BACKUP_REMAINING);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BACKUP_REMAINING)
        SQLITE3_PROXY_HANDLE_SQLITE3_BACKUP_REMAINING();
    #endif
    return orgFnPtr(pBckp);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_backup_step(sqlite3_backup* pBckp, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_backup_step"));
    sqlite3_backup_step_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_backup_step_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BACKUP_STEP);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BACKUP_STEP)
        SQLITE3_PROXY_HANDLE_SQLITE3_BACKUP_STEP();
    #endif
    return orgFnPtr(pBckp, i);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_bind_blob(sqlite3_stmt* pStmt, int i, const void* pcv, int n, void (*pfn)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_bind_blob"));
    sqlite3_bind_blob_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_bind_blob_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BIND_BLOB);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BIND_BLOB)
        SQLITE3_PROXY_HANDLE_SQLITE3_BIND_BLOB();
    #endif
    return orgFnPtr(pStmt, i, pcv, n, pfn);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_bind_blob64(sqlite3_stmt* pStmt, int i, const void* pcv, sqlite3_uint64 u64, void (*pfn)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_bind_blob64"));
    sqlite3_bind_blob64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_bind_blob64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BIND_BLOB64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BIND_BLOB64)
        SQLITE3_PROXY_HANDLE_SQLITE3_BIND_BLOB64();
    #endif
    return orgFnPtr(pStmt, i, pcv, u64, pfn);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_bind_double(sqlite3_stmt* pStmt, int i, double dbl)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_bind_double"));
    sqlite3_bind_double_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_bind_double_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BIND_DOUBLE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BIND_DOUBLE)
        SQLITE3_PROXY_HANDLE_SQLITE3_BIND_DOUBLE();
    #endif
    return orgFnPtr(pStmt, i, dbl);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_bind_int(sqlite3_stmt* pStmt, int i, int i2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_bind_int"));
    sqlite3_bind_int_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_bind_int_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BIND_INT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BIND_INT)
        SQLITE3_PROXY_HANDLE_SQLITE3_BIND_INT();
    #endif
    return orgFnPtr(pStmt, i, i2);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_bind_int64(sqlite3_stmt* pStmt, int i, sqlite_int64 i64)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_bind_int64"));
    sqlite3_bind_int64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_bind_int64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BIND_INT64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BIND_INT64)
        SQLITE3_PROXY_HANDLE_SQLITE3_BIND_INT64();
    #endif
    return orgFnPtr(pStmt, i, i64);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_bind_null(sqlite3_stmt* pStmt, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_bind_null"));
    sqlite3_bind_null_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_bind_null_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BIND_NULL);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BIND_NULL)
        SQLITE3_PROXY_HANDLE_SQLITE3_BIND_NULL();
    #endif
    return orgFnPtr(pStmt, i);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_bind_parameter_count(sqlite3_stmt* pStmt)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_bind_parameter_count"));
    sqlite3_bind_parameter_count_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_bind_parameter_count_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BIND_PARAMETER_COUNT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BIND_PARAMETER_COUNT)
        SQLITE3_PROXY_HANDLE_SQLITE3_BIND_PARAMETER_COUNT();
    #endif
    return orgFnPtr(pStmt);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_bind_parameter_index(sqlite3_stmt* pStmt, const char* zName)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_bind_parameter_index"));
    sqlite3_bind_parameter_index_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_bind_parameter_index_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BIND_PARAMETER_INDEX);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BIND_PARAMETER_INDEX)
        SQLITE3_PROXY_HANDLE_SQLITE3_BIND_PARAMETER_INDEX();
    #endif
    return orgFnPtr(pStmt, zName);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_bind_parameter_name(sqlite3_stmt* pStmt, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_bind_parameter_name"));
    sqlite3_bind_parameter_name_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_bind_parameter_name_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BIND_PARAMETER_NAME);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BIND_PARAMETER_NAME)
        SQLITE3_PROXY_HANDLE_SQLITE3_BIND_PARAMETER_NAME();
    #endif
    return orgFnPtr(pStmt, i);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_bind_pointer(sqlite3_stmt* pStmt, int i, void* pv, const char* pcStr, void (*pfn)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_bind_pointer"));
    sqlite3_bind_pointer_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_bind_pointer_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BIND_POINTER);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BIND_POINTER)
        SQLITE3_PROXY_HANDLE_SQLITE3_BIND_POINTER();
    #endif
    return orgFnPtr(pStmt, i, pv, pcStr, pfn);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_bind_text(sqlite3_stmt* pStmt, int i, const char* pcStr, int n, void (*pfn)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_bind_text"));
    sqlite3_bind_text_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_bind_text_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BIND_TEXT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BIND_TEXT)
        SQLITE3_PROXY_HANDLE_SQLITE3_BIND_TEXT();
    #endif
    return orgFnPtr(pStmt, i, pcStr, n, pfn);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_bind_text16(sqlite3_stmt* pStmt, int i, const void* pcv, int i2, void (*pfn)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_bind_text16"));
    sqlite3_bind_text16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_bind_text16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BIND_TEXT16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BIND_TEXT16)
        SQLITE3_PROXY_HANDLE_SQLITE3_BIND_TEXT16();
    #endif
    return orgFnPtr(pStmt, i, pcv, i2, pfn);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_bind_text64(sqlite3_stmt* pStmt, int i, const char* pcStr, sqlite3_uint64 u64, void (*pfn)(void*), unsigned char uch)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_bind_text64"));
    sqlite3_bind_text64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_bind_text64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BIND_TEXT64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BIND_TEXT64)
        SQLITE3_PROXY_HANDLE_SQLITE3_BIND_TEXT64();
    #endif
    return orgFnPtr(pStmt, i, pcStr, u64, pfn, uch);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_bind_value(sqlite3_stmt* pStmt, int i, const sqlite3_value* pcVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_bind_value"));
    sqlite3_bind_value_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_bind_value_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BIND_VALUE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BIND_VALUE)
        SQLITE3_PROXY_HANDLE_SQLITE3_BIND_VALUE();
    #endif
    return orgFnPtr(pStmt, i, pcVal);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_bind_zeroblob(sqlite3_stmt* pStmt, int i, int i2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_bind_zeroblob"));
    sqlite3_bind_zeroblob_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_bind_zeroblob_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BIND_ZEROBLOB);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BIND_ZEROBLOB)
        SQLITE3_PROXY_HANDLE_SQLITE3_BIND_ZEROBLOB();
    #endif
    return orgFnPtr(pStmt, i, i2);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_bind_zeroblob64(sqlite3_stmt* pStmt, int i, sqlite3_uint64 u64)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_bind_zeroblob64"));
    sqlite3_bind_zeroblob64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_bind_zeroblob64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BIND_ZEROBLOB64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BIND_ZEROBLOB64)
        SQLITE3_PROXY_HANDLE_SQLITE3_BIND_ZEROBLOB64();
    #endif
    return orgFnPtr(pStmt, i, u64);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_blob_bytes(sqlite3_blob* pBlob)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_blob_bytes"));
    sqlite3_blob_bytes_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_blob_bytes_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BLOB_BYTES);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BLOB_BYTES)
        SQLITE3_PROXY_HANDLE_SQLITE3_BLOB_BYTES();
    #endif
    return orgFnPtr(pBlob);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_blob_close(sqlite3_blob* pBlob)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_blob_close"));
    sqlite3_blob_close_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_blob_close_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BLOB_CLOSE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BLOB_CLOSE)
        SQLITE3_PROXY_HANDLE_SQLITE3_BLOB_CLOSE();
    #endif
    return orgFnPtr(pBlob);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_blob_open(sqlite3* pDb, const char* pcStr, const char* pcStr2, const char* pcStr3, sqlite3_int64 i64, int i, sqlite3_blob** ppBlob)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_blob_open"));
    sqlite3_blob_open_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_blob_open_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BLOB_OPEN);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BLOB_OPEN)
        SQLITE3_PROXY_HANDLE_SQLITE3_BLOB_OPEN();
    #endif
    return orgFnPtr(pDb, pcStr, pcStr2, pcStr3, i64, i, ppBlob);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_blob_read(sqlite3_blob* pBlob, void* pv, int i, int i2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_blob_read"));
    sqlite3_blob_read_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_blob_read_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BLOB_READ);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BLOB_READ)
        SQLITE3_PROXY_HANDLE_SQLITE3_BLOB_READ();
    #endif
    return orgFnPtr(pBlob, pv, i, i2);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_blob_reopen(sqlite3_blob* pBlob, sqlite3_int64 i64)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_blob_reopen"));
    sqlite3_blob_reopen_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_blob_reopen_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BLOB_REOPEN);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BLOB_REOPEN)
        SQLITE3_PROXY_HANDLE_SQLITE3_BLOB_REOPEN();
    #endif
    return orgFnPtr(pBlob, i64);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_blob_write(sqlite3_blob* pBlob, const void* pcv, int i, int i2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_blob_write"));
    sqlite3_blob_write_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_blob_write_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BLOB_WRITE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BLOB_WRITE)
        SQLITE3_PROXY_HANDLE_SQLITE3_BLOB_WRITE();
    #endif
    return orgFnPtr(pBlob, pcv, i, i2);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_busy_handler(sqlite3* pDb, int (*pfn)(void*, int), void* pv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_busy_handler"));
    sqlite3_busy_handler_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_busy_handler_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BUSY_HANDLER);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BUSY_HANDLER)
        SQLITE3_PROXY_HANDLE_SQLITE3_BUSY_HANDLER();
    #endif
    return orgFnPtr(pDb, pfn, pv);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_busy_timeout(sqlite3* pDb, int ms)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_busy_timeout"));
    sqlite3_busy_timeout_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_busy_timeout_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_BUSY_TIMEOUT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_BUSY_TIMEOUT)
        SQLITE3_PROXY_HANDLE_SQLITE3_BUSY_TIMEOUT();
    #endif
    return orgFnPtr(pDb, ms);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_cancel_auto_extension(void (*pfn)(void))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_cancel_auto_extension"));
    sqlite3_cancel_auto_extension_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_cancel_auto_extension_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CANCEL_AUTO_EXTENSION);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CANCEL_AUTO_EXTENSION)
        SQLITE3_PROXY_HANDLE_SQLITE3_CANCEL_AUTO_EXTENSION();
    #endif
    return orgFnPtr(pfn);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_changes(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_changes"));
    sqlite3_changes_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_changes_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CHANGES);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CHANGES)
        SQLITE3_PROXY_HANDLE_SQLITE3_CHANGES();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT sqlite3_int64 hook_sqlite3_changes64(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_changes64"));
    sqlite3_changes64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_changes64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CHANGES64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CHANGES64)
        SQLITE3_PROXY_HANDLE_SQLITE3_CHANGES64();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_clear_bindings(sqlite3_stmt* pStmt)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_clear_bindings"));
    sqlite3_clear_bindings_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_clear_bindings_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CLEAR_BINDINGS);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CLEAR_BINDINGS)
        SQLITE3_PROXY_HANDLE_SQLITE3_CLEAR_BINDINGS();
    #endif
    return orgFnPtr(pStmt);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_close(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_close"));
    sqlite3_close_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_close_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CLOSE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CLOSE)
        SQLITE3_PROXY_HANDLE_SQLITE3_CLOSE();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_close_v2(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_close_v2"));
    sqlite3_close_v2_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_close_v2_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CLOSE_V2);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CLOSE_V2)
        SQLITE3_PROXY_HANDLE_SQLITE3_CLOSE_V2();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_collation_needed(sqlite3* pDb, void* pv, void (*pfn)(void*, sqlite3*, int, const char*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_collation_needed"));
    sqlite3_collation_needed_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_collation_needed_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLLATION_NEEDED);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLLATION_NEEDED)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLLATION_NEEDED();
    #endif
    return orgFnPtr(pDb, pv, pfn);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_collation_needed16(sqlite3* pDb, void* pv, void (*pfn)(void*, sqlite3*, int, const void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_collation_needed16"));
    sqlite3_collation_needed16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_collation_needed16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLLATION_NEEDED16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLLATION_NEEDED16)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLLATION_NEEDED16();
    #endif
    return orgFnPtr(pDb, pv, pfn);
}

SQLITE3_PROXY_EXPORT const void* hook_sqlite3_column_blob(sqlite3_stmt* pStmt, int iCol)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_blob"));
    sqlite3_column_blob_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_blob_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_BLOB);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_BLOB)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_BLOB();
    #endif
    return orgFnPtr(pStmt, iCol);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_column_bytes(sqlite3_stmt* pStmt, int iCol)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_bytes"));
    sqlite3_column_bytes_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_bytes_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_BYTES);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_BYTES)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_BYTES();
    #endif
    return orgFnPtr(pStmt, iCol);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_column_bytes16(sqlite3_stmt* pStmt, int iCol)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_bytes16"));
    sqlite3_column_bytes16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_bytes16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_BYTES16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_BYTES16)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_BYTES16();
    #endif
    return orgFnPtr(pStmt, iCol);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_column_count(sqlite3_stmt* pStmt)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_count"));
    sqlite3_column_count_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_count_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_COUNT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_COUNT)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_COUNT();
    #endif
    return orgFnPtr(pStmt);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_column_database_name(sqlite3_stmt* pStmt, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_database_name"));
    sqlite3_column_database_name_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_database_name_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_DATABASE_NAME);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_DATABASE_NAME)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_DATABASE_NAME();
    #endif
    return orgFnPtr(pStmt, i);
}

SQLITE3_PROXY_EXPORT const void* hook_sqlite3_column_database_name16(sqlite3_stmt* pStmt, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_database_name16"));
    sqlite3_column_database_name16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_database_name16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_DATABASE_NAME16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_DATABASE_NAME16)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_DATABASE_NAME16();
    #endif
    return orgFnPtr(pStmt, i);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_column_decltype(sqlite3_stmt* pStmt, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_decltype"));
    sqlite3_column_decltype_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_decltype_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_DECLTYPE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_DECLTYPE)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_DECLTYPE();
    #endif
    return orgFnPtr(pStmt, i);
}

SQLITE3_PROXY_EXPORT const void* hook_sqlite3_column_decltype16(sqlite3_stmt* pStmt, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_decltype16"));
    sqlite3_column_decltype16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_decltype16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_DECLTYPE16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_DECLTYPE16)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_DECLTYPE16();
    #endif
    return orgFnPtr(pStmt, i);
}

SQLITE3_PROXY_EXPORT double hook_sqlite3_column_double(sqlite3_stmt* pStmt, int iCol)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_double"));
    sqlite3_column_double_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_double_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_DOUBLE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_DOUBLE)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_DOUBLE();
    #endif
    return orgFnPtr(pStmt, iCol);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_column_int(sqlite3_stmt* pStmt, int iCol)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_int"));
    sqlite3_column_int_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_int_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_INT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_INT)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_INT();
    #endif
    return orgFnPtr(pStmt, iCol);
}

SQLITE3_PROXY_EXPORT sqlite_int64 hook_sqlite3_column_int64(sqlite3_stmt* pStmt, int iCol)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_int64"));
    sqlite3_column_int64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_int64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_INT64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_INT64)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_INT64();
    #endif
    return orgFnPtr(pStmt, iCol);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_column_name(sqlite3_stmt* pStmt, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_name"));
    sqlite3_column_name_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_name_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_NAME);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_NAME)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_NAME();
    #endif
    return orgFnPtr(pStmt, i);
}

SQLITE3_PROXY_EXPORT const void* hook_sqlite3_column_name16(sqlite3_stmt* pStmt, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_name16"));
    sqlite3_column_name16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_name16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_NAME16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_NAME16)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_NAME16();
    #endif
    return orgFnPtr(pStmt, i);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_column_origin_name(sqlite3_stmt* pStmt, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_origin_name"));
    sqlite3_column_origin_name_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_origin_name_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_ORIGIN_NAME);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_ORIGIN_NAME)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_ORIGIN_NAME();
    #endif
    return orgFnPtr(pStmt, i);
}

SQLITE3_PROXY_EXPORT const void* hook_sqlite3_column_origin_name16(sqlite3_stmt* pStmt, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_origin_name16"));
    sqlite3_column_origin_name16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_origin_name16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_ORIGIN_NAME16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_ORIGIN_NAME16)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_ORIGIN_NAME16();
    #endif
    return orgFnPtr(pStmt, i);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_column_table_name(sqlite3_stmt* pStmt, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_table_name"));
    sqlite3_column_table_name_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_table_name_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_TABLE_NAME);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_TABLE_NAME)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_TABLE_NAME();
    #endif
    return orgFnPtr(pStmt, i);
}

SQLITE3_PROXY_EXPORT const void* hook_sqlite3_column_table_name16(sqlite3_stmt* pStmt, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_table_name16"));
    sqlite3_column_table_name16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_table_name16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_TABLE_NAME16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_TABLE_NAME16)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_TABLE_NAME16();
    #endif
    return orgFnPtr(pStmt, i);
}

SQLITE3_PROXY_EXPORT const unsigned char* hook_sqlite3_column_text(sqlite3_stmt* pStmt, int iCol)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_text"));
    sqlite3_column_text_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_text_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_TEXT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_TEXT)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_TEXT();
    #endif
    return orgFnPtr(pStmt, iCol);
}

SQLITE3_PROXY_EXPORT const void* hook_sqlite3_column_text16(sqlite3_stmt* pStmt, int iCol)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_text16"));
    sqlite3_column_text16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_text16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_TEXT16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_TEXT16)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_TEXT16();
    #endif
    return orgFnPtr(pStmt, iCol);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_column_type(sqlite3_stmt* pStmt, int iCol)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_type"));
    sqlite3_column_type_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_type_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_TYPE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_TYPE)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_TYPE();
    #endif
    return orgFnPtr(pStmt, iCol);
}

SQLITE3_PROXY_EXPORT sqlite3_value* hook_sqlite3_column_value(sqlite3_stmt* pStmt, int iCol)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_column_value"));
    sqlite3_column_value_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_column_value_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COLUMN_VALUE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_VALUE)
        SQLITE3_PROXY_HANDLE_SQLITE3_COLUMN_VALUE();
    #endif
    return orgFnPtr(pStmt, iCol);
}

SQLITE3_PROXY_EXPORT void* hook_sqlite3_commit_hook(sqlite3* pDb, int (*pfn)(void*), void* pv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_commit_hook"));
    sqlite3_commit_hook_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_commit_hook_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COMMIT_HOOK);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COMMIT_HOOK)
        SQLITE3_PROXY_HANDLE_SQLITE3_COMMIT_HOOK();
    #endif
    return orgFnPtr(pDb, pfn, pv);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_compileoption_get(int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_compileoption_get"));
    sqlite3_compileoption_get_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_compileoption_get_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COMPILEOPTION_GET);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COMPILEOPTION_GET)
        SQLITE3_PROXY_HANDLE_SQLITE3_COMPILEOPTION_GET();
    #endif
    return orgFnPtr(i);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_compileoption_used(const char* pcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_compileoption_used"));
    sqlite3_compileoption_used_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_compileoption_used_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COMPILEOPTION_USED);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COMPILEOPTION_USED)
        SQLITE3_PROXY_HANDLE_SQLITE3_COMPILEOPTION_USED();
    #endif
    return orgFnPtr(pcStr);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_complete(const char* sql)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_complete"));
    sqlite3_complete_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_complete_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COMPLETE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COMPLETE)
        SQLITE3_PROXY_HANDLE_SQLITE3_COMPLETE();
    #endif
    return orgFnPtr(sql);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_complete16(const void* sql)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_complete16"));
    sqlite3_complete16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_complete16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_COMPLETE16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_COMPLETE16)
        SQLITE3_PROXY_HANDLE_SQLITE3_COMPLETE16();
    #endif
    return orgFnPtr(sql);
}

SQLITE3_PROXY_EXPORT sqlite3* hook_sqlite3_context_db_handle(sqlite3_context* pCtx)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_context_db_handle"));
    sqlite3_context_db_handle_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_context_db_handle_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CONTEXT_DB_HANDLE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CONTEXT_DB_HANDLE)
        SQLITE3_PROXY_HANDLE_SQLITE3_CONTEXT_DB_HANDLE();
    #endif
    return orgFnPtr(pCtx);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_create_collation(sqlite3* pDb, const char* pcStr, int i, void* pv, int (*pfn)(void*, int, const void*, int, const void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_create_collation"));
    sqlite3_create_collation_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_create_collation_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_COLLATION);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_COLLATION)
        SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_COLLATION();
    #endif
    return orgFnPtr(pDb, pcStr, i, pv, pfn);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_create_collation16(sqlite3* pDb, const void* pcv, int i, void* pv, int (*pfn)(void*, int, const void*, int, const void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_create_collation16"));
    sqlite3_create_collation16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_create_collation16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_COLLATION16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_COLLATION16)
        SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_COLLATION16();
    #endif
    return orgFnPtr(pDb, pcv, i, pv, pfn);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_create_collation_v2(sqlite3* pDb, const char* pcStr, int i, void* pv, int (*pfn)(void*, int, const void*, int, const void*), void (*pfn2)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_create_collation_v2"));
    sqlite3_create_collation_v2_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_create_collation_v2_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_COLLATION_V2);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_COLLATION_V2)
        SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_COLLATION_V2();
    #endif
    return orgFnPtr(pDb, pcStr, i, pv, pfn, pfn2);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_create_filename(const char* pcStr, const char* pcStr2, const char* pcStr3, int i, const char** ppcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_create_filename"));
    sqlite3_create_filename_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_create_filename_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_FILENAME);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_FILENAME)
        SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_FILENAME();
    #endif
    return orgFnPtr(pcStr, pcStr2, pcStr3, i, ppcStr);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_create_function(sqlite3* pDb, const char* pcStr, int i, int i2, void* pv, void (*sqlite3_xFunc)(sqlite3_context*, int, sqlite3_value**), void (*sqlite3_xStep)(sqlite3_context*, int, sqlite3_value**), void (*sqlite3_xFinal)(sqlite3_context*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_create_function"));
    sqlite3_create_function_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_create_function_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_FUNCTION);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_FUNCTION)
        SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_FUNCTION();
    #endif
    return orgFnPtr(pDb, pcStr, i, i2, pv, sqlite3_xFunc, sqlite3_xStep, sqlite3_xFinal);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_create_function16(sqlite3* pDb, const void* pcv, int i, int i2, void* pv, void (*sqlite3_xFunc)(sqlite3_context*, int, sqlite3_value**), void (*sqlite3_xStep)(sqlite3_context*, int, sqlite3_value**), void (*sqlite3_xFinal)(sqlite3_context*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_create_function16"));
    sqlite3_create_function16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_create_function16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_FUNCTION16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_FUNCTION16)
        SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_FUNCTION16();
    #endif
    return orgFnPtr(pDb, pcv, i, i2, pv, sqlite3_xFunc, sqlite3_xStep, sqlite3_xFinal);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_create_function_v2(sqlite3* pDb, const char* pcStr, int i, int i2, void* pv, void (*sqlite3_xFunc)(sqlite3_context*, int, sqlite3_value**), void (*sqlite3_xStep)(sqlite3_context*, int, sqlite3_value**), void (*sqlite3_xFinal)(sqlite3_context*), void (*sqlite3_xDestroy)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_create_function_v2"));
    sqlite3_create_function_v2_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_create_function_v2_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_FUNCTION_V2);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_FUNCTION_V2)
        SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_FUNCTION_V2();
    #endif
    return orgFnPtr(pDb, pcStr, i, i2, pv, sqlite3_xFunc, sqlite3_xStep, sqlite3_xFinal, sqlite3_xDestroy);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_create_module(sqlite3* pDb, const char* pcStr, const sqlite3_module* pcMod, void* pv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_create_module"));
    sqlite3_create_module_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_create_module_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_MODULE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_MODULE)
        SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_MODULE();
    #endif
    return orgFnPtr(pDb, pcStr, pcMod, pv);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_create_module_v2(sqlite3* pDb, const char* pcStr, const sqlite3_module* pcMod, void* pv, void (*sqlite3_xDestroy)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_create_module_v2"));
    sqlite3_create_module_v2_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_create_module_v2_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_MODULE_V2);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_MODULE_V2)
        SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_MODULE_V2();
    #endif
    return orgFnPtr(pDb, pcStr, pcMod, pv, sqlite3_xDestroy);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_create_window_function(sqlite3* pDb, const char* pcStr, int i, int i2, void* pv, void (*sqlite3_xStep)(sqlite3_context*, int, sqlite3_value**), void (*sqlite3_xFinal)(sqlite3_context*), void (*sqlite3_xValue)(sqlite3_context*), void (*sqlite3_xInv)(sqlite3_context*, int, sqlite3_value**), void (*sqlite3_xDestroy)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_create_window_function"));
    sqlite3_create_window_function_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_create_window_function_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_CREATE_WINDOW_FUNCTION);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_WINDOW_FUNCTION)
        SQLITE3_PROXY_HANDLE_SQLITE3_CREATE_WINDOW_FUNCTION();
    #endif
    return orgFnPtr(pDb, pcStr, i, i2, pv, sqlite3_xStep, sqlite3_xFinal, sqlite3_xValue, sqlite3_xInv, sqlite3_xDestroy);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_data_count(sqlite3_stmt* pStmt)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_data_count"));
    sqlite3_data_count_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_data_count_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_DATA_COUNT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_DATA_COUNT)
        SQLITE3_PROXY_HANDLE_SQLITE3_DATA_COUNT();
    #endif
    return orgFnPtr(pStmt);
}

SQLITE3_PROXY_EXPORT sqlite3_file* hook_sqlite3_database_file_object(const char* pcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_database_file_object"));
    sqlite3_database_file_object_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_database_file_object_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_DATABASE_FILE_OBJECT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_DATABASE_FILE_OBJECT)
        SQLITE3_PROXY_HANDLE_SQLITE3_DATABASE_FILE_OBJECT();
    #endif
    return orgFnPtr(pcStr);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_db_cacheflush(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_db_cacheflush"));
    sqlite3_db_cacheflush_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_db_cacheflush_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_DB_CACHEFLUSH);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_DB_CACHEFLUSH)
        SQLITE3_PROXY_HANDLE_SQLITE3_DB_CACHEFLUSH();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_db_filename(sqlite3* pDb, const char* pcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_db_filename"));
    sqlite3_db_filename_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_db_filename_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_DB_FILENAME);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_DB_FILENAME)
        SQLITE3_PROXY_HANDLE_SQLITE3_DB_FILENAME();
    #endif
    return orgFnPtr(pDb, pcStr);
}

SQLITE3_PROXY_EXPORT sqlite3* hook_sqlite3_db_handle(sqlite3_stmt* pStmt)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_db_handle"));
    sqlite3_db_handle_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_db_handle_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_DB_HANDLE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_DB_HANDLE)
        SQLITE3_PROXY_HANDLE_SQLITE3_DB_HANDLE();
    #endif
    return orgFnPtr(pStmt);
}

SQLITE3_PROXY_EXPORT sqlite3_mutex* hook_sqlite3_db_mutex(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_db_mutex"));
    sqlite3_db_mutex_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_db_mutex_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_DB_MUTEX);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_DB_MUTEX)
        SQLITE3_PROXY_HANDLE_SQLITE3_DB_MUTEX();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_db_readonly(sqlite3* pDb, const char* pcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_db_readonly"));
    sqlite3_db_readonly_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_db_readonly_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_DB_READONLY);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_DB_READONLY)
        SQLITE3_PROXY_HANDLE_SQLITE3_DB_READONLY();
    #endif
    return orgFnPtr(pDb, pcStr);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_db_release_memory(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_db_release_memory"));
    sqlite3_db_release_memory_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_db_release_memory_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_DB_RELEASE_MEMORY);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_DB_RELEASE_MEMORY)
        SQLITE3_PROXY_HANDLE_SQLITE3_DB_RELEASE_MEMORY();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_db_status(sqlite3* pDb, int i, int* pInt, int* pInt2, int i2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_db_status"));
    sqlite3_db_status_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_db_status_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_DB_STATUS);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_DB_STATUS)
        SQLITE3_PROXY_HANDLE_SQLITE3_DB_STATUS();
    #endif
    return orgFnPtr(pDb, i, pInt, pInt2, i2);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_declare_vtab(sqlite3* pDb, const char* pcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_declare_vtab"));
    sqlite3_declare_vtab_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_declare_vtab_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_DECLARE_VTAB);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_DECLARE_VTAB)
        SQLITE3_PROXY_HANDLE_SQLITE3_DECLARE_VTAB();
    #endif
    return orgFnPtr(pDb, pcStr);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_deserialize(sqlite3* pDb, const char* pcStr, unsigned char* pBytes, sqlite3_int64 i64, sqlite3_int64 i642, unsigned u)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_deserialize"));
    sqlite3_deserialize_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_deserialize_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_DESERIALIZE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_DESERIALIZE)
        SQLITE3_PROXY_HANDLE_SQLITE3_DESERIALIZE();
    #endif
    return orgFnPtr(pDb, pcStr, pBytes, i64, i642, u);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_drop_modules(sqlite3* pDb, const char** ppcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_drop_modules"));
    sqlite3_drop_modules_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_drop_modules_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_DROP_MODULES);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_DROP_MODULES)
        SQLITE3_PROXY_HANDLE_SQLITE3_DROP_MODULES();
    #endif
    return orgFnPtr(pDb, ppcStr);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_enable_load_extension(sqlite3* db, int onoff)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_enable_load_extension"));
    sqlite3_enable_load_extension_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_enable_load_extension_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_ENABLE_LOAD_EXTENSION);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_ENABLE_LOAD_EXTENSION)
        SQLITE3_PROXY_HANDLE_SQLITE3_ENABLE_LOAD_EXTENSION();
    #endif
    return orgFnPtr(db, onoff);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_enable_shared_cache(int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_enable_shared_cache"));
    sqlite3_enable_shared_cache_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_enable_shared_cache_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_ENABLE_SHARED_CACHE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_ENABLE_SHARED_CACHE)
        SQLITE3_PROXY_HANDLE_SQLITE3_ENABLE_SHARED_CACHE();
    #endif
    return orgFnPtr(i);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_errcode(sqlite3* db)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_errcode"));
    sqlite3_errcode_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_errcode_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_ERRCODE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_ERRCODE)
        SQLITE3_PROXY_HANDLE_SQLITE3_ERRCODE();
    #endif
    return orgFnPtr(db);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_errmsg(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_errmsg"));
    sqlite3_errmsg_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_errmsg_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_ERRMSG);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_ERRMSG)
        SQLITE3_PROXY_HANDLE_SQLITE3_ERRMSG();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT const void* hook_sqlite3_errmsg16(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_errmsg16"));
    sqlite3_errmsg16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_errmsg16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_ERRMSG16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_ERRMSG16)
        SQLITE3_PROXY_HANDLE_SQLITE3_ERRMSG16();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_error_offset(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_error_offset"));
    sqlite3_error_offset_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_error_offset_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_ERROR_OFFSET);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_ERROR_OFFSET)
        SQLITE3_PROXY_HANDLE_SQLITE3_ERROR_OFFSET();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_errstr(int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_errstr"));
    sqlite3_errstr_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_errstr_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_ERRSTR);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_ERRSTR)
        SQLITE3_PROXY_HANDLE_SQLITE3_ERRSTR();
    #endif
    return orgFnPtr(i);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_exec(sqlite3* pDb, const char* pcStr, sqlite3_callback cbk, void* pv, char** ppStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_exec"));
    sqlite3_exec_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_exec_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_EXEC);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_EXEC)
        SQLITE3_PROXY_HANDLE_SQLITE3_EXEC();
    #endif
    return orgFnPtr(pDb, pcStr, cbk, pv, ppStr);
}

SQLITE3_PROXY_EXPORT char* hook_sqlite3_expanded_sql(sqlite3_stmt* pStmt)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_expanded_sql"));
    sqlite3_expanded_sql_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_expanded_sql_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_EXPANDED_SQL);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_EXPANDED_SQL)
        SQLITE3_PROXY_HANDLE_SQLITE3_EXPANDED_SQL();
    #endif
    return orgFnPtr(pStmt);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_expired(sqlite3_stmt* pStmt)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_expired"));
    sqlite3_expired_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_expired_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_EXPIRED);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_EXPIRED)
        SQLITE3_PROXY_HANDLE_SQLITE3_EXPIRED();
    #endif
    return orgFnPtr(pStmt);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_extended_errcode(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_extended_errcode"));
    sqlite3_extended_errcode_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_extended_errcode_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_EXTENDED_ERRCODE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_EXTENDED_ERRCODE)
        SQLITE3_PROXY_HANDLE_SQLITE3_EXTENDED_ERRCODE();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_extended_result_codes(sqlite3* pDb, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_extended_result_codes"));
    sqlite3_extended_result_codes_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_extended_result_codes_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_EXTENDED_RESULT_CODES);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_EXTENDED_RESULT_CODES)
        SQLITE3_PROXY_HANDLE_SQLITE3_EXTENDED_RESULT_CODES();
    #endif
    return orgFnPtr(pDb, i);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_file_control(sqlite3* pDb, const char* pcStr, int i, void* pv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_file_control"));
    sqlite3_file_control_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_file_control_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_FILE_CONTROL);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_FILE_CONTROL)
        SQLITE3_PROXY_HANDLE_SQLITE3_FILE_CONTROL();
    #endif
    return orgFnPtr(pDb, pcStr, i, pv);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_filename_database(const char* pcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_filename_database"));
    sqlite3_filename_database_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_filename_database_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_FILENAME_DATABASE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_FILENAME_DATABASE)
        SQLITE3_PROXY_HANDLE_SQLITE3_FILENAME_DATABASE();
    #endif
    return orgFnPtr(pcStr);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_filename_journal(const char* pcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_filename_journal"));
    sqlite3_filename_journal_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_filename_journal_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_FILENAME_JOURNAL);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_FILENAME_JOURNAL)
        SQLITE3_PROXY_HANDLE_SQLITE3_FILENAME_JOURNAL();
    #endif
    return orgFnPtr(pcStr);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_filename_wal(const char* pcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_filename_wal"));
    sqlite3_filename_wal_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_filename_wal_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_FILENAME_WAL);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_FILENAME_WAL)
        SQLITE3_PROXY_HANDLE_SQLITE3_FILENAME_WAL();
    #endif
    return orgFnPtr(pcStr);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_finalize(sqlite3_stmt* pStmt)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_finalize"));
    sqlite3_finalize_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_finalize_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_FINALIZE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_FINALIZE)
        SQLITE3_PROXY_HANDLE_SQLITE3_FINALIZE();
    #endif
    return orgFnPtr(pStmt);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_free(void* pv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_free"));
    sqlite3_free_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_free_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_FREE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_FREE)
        SQLITE3_PROXY_HANDLE_SQLITE3_FREE();
    #endif
    orgFnPtr(pv);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_free_filename(const char* pcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_free_filename"));
    sqlite3_free_filename_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_free_filename_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_FREE_FILENAME);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_FREE_FILENAME)
        SQLITE3_PROXY_HANDLE_SQLITE3_FREE_FILENAME();
    #endif
    orgFnPtr(pcStr);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_free_table(char** result)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_free_table"));
    sqlite3_free_table_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_free_table_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_FREE_TABLE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_FREE_TABLE)
        SQLITE3_PROXY_HANDLE_SQLITE3_FREE_TABLE();
    #endif
    orgFnPtr(result);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_get_autocommit(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_get_autocommit"));
    sqlite3_get_autocommit_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_get_autocommit_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_GET_AUTOCOMMIT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_GET_AUTOCOMMIT)
        SQLITE3_PROXY_HANDLE_SQLITE3_GET_AUTOCOMMIT();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT void* hook_sqlite3_get_auxdata(sqlite3_context* pCtx, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_get_auxdata"));
    sqlite3_get_auxdata_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_get_auxdata_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_GET_AUXDATA);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_GET_AUXDATA)
        SQLITE3_PROXY_HANDLE_SQLITE3_GET_AUXDATA();
    #endif
    return orgFnPtr(pCtx, i);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_get_table(sqlite3* pDb, const char* pcStr, char*** pppStr, int* pInt, int* pInt2, char** ppStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_get_table"));
    sqlite3_get_table_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_get_table_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_GET_TABLE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_GET_TABLE)
        SQLITE3_PROXY_HANDLE_SQLITE3_GET_TABLE();
    #endif
    return orgFnPtr(pDb, pcStr, pppStr, pInt, pInt2, ppStr);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_global_recover(void)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_global_recover"));
    sqlite3_global_recover_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_global_recover_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_GLOBAL_RECOVER);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_GLOBAL_RECOVER)
        SQLITE3_PROXY_HANDLE_SQLITE3_GLOBAL_RECOVER();
    #endif
    return orgFnPtr();
}

SQLITE3_PROXY_EXPORT sqlite3_int64 hook_sqlite3_hard_heap_limit64(sqlite3_int64 i64)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_hard_heap_limit64"));
    sqlite3_hard_heap_limit64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_hard_heap_limit64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_HARD_HEAP_LIMIT64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_HARD_HEAP_LIMIT64)
        SQLITE3_PROXY_HANDLE_SQLITE3_HARD_HEAP_LIMIT64();
    #endif
    return orgFnPtr(i64);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_initialize(void)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_initialize"));
    sqlite3_initialize_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_initialize_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_INITIALIZE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_INITIALIZE)
        SQLITE3_PROXY_HANDLE_SQLITE3_INITIALIZE();
    #endif
    return orgFnPtr();
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_interrupt(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_interrupt"));
    sqlite3_interrupt_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_interrupt_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_INTERRUPT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_INTERRUPT)
        SQLITE3_PROXY_HANDLE_SQLITE3_INTERRUPT();
    #endif
    orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_key(sqlite3* db, const void* pKey, int nKey)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_key"));
    sqlite3_key_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_key_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_KEY);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_KEY)
        SQLITE3_PROXY_HANDLE_SQLITE3_KEY();
    #endif
    return orgFnPtr(db, pKey, nKey);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_key_v2(sqlite3* db, const char* zDbName, const void* pKey, int nKey)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_key_v2"));
    sqlite3_key_v2_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_key_v2_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_KEY_V2);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_KEY_V2)
        SQLITE3_PROXY_HANDLE_SQLITE3_KEY_V2();
    #endif
    return orgFnPtr(db, zDbName, pKey, nKey);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_keyword_check(const char* pcStr, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_keyword_check"));
    sqlite3_keyword_check_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_keyword_check_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_KEYWORD_CHECK);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_KEYWORD_CHECK)
        SQLITE3_PROXY_HANDLE_SQLITE3_KEYWORD_CHECK();
    #endif
    return orgFnPtr(pcStr, i);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_keyword_count(void)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_keyword_count"));
    sqlite3_keyword_count_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_keyword_count_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_KEYWORD_COUNT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_KEYWORD_COUNT)
        SQLITE3_PROXY_HANDLE_SQLITE3_KEYWORD_COUNT();
    #endif
    return orgFnPtr();
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_keyword_name(int i, const char** ppcStr, int* pInt)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_keyword_name"));
    sqlite3_keyword_name_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_keyword_name_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_KEYWORD_NAME);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_KEYWORD_NAME)
        SQLITE3_PROXY_HANDLE_SQLITE3_KEYWORD_NAME();
    #endif
    return orgFnPtr(i, ppcStr, pInt);
}

SQLITE3_PROXY_EXPORT sqlite_int64 hook_sqlite3_last_insert_rowid(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_last_insert_rowid"));
    sqlite3_last_insert_rowid_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_last_insert_rowid_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_LAST_INSERT_ROWID);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_LAST_INSERT_ROWID)
        SQLITE3_PROXY_HANDLE_SQLITE3_LAST_INSERT_ROWID();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_libversion(void)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_libversion"));
    sqlite3_libversion_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_libversion_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_LIBVERSION);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_LIBVERSION)
        SQLITE3_PROXY_HANDLE_SQLITE3_LIBVERSION();
    #endif
    return orgFnPtr();
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_libversion_number(void)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_libversion_number"));
    sqlite3_libversion_number_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_libversion_number_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_LIBVERSION_NUMBER);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_LIBVERSION_NUMBER)
        SQLITE3_PROXY_HANDLE_SQLITE3_LIBVERSION_NUMBER();
    #endif
    return orgFnPtr();
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_limit(sqlite3* pDb, int i, int i2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_limit"));
    sqlite3_limit_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_limit_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_LIMIT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_LIMIT)
        SQLITE3_PROXY_HANDLE_SQLITE3_LIMIT();
    #endif
    return orgFnPtr(pDb, i, i2);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_load_extension(sqlite3* pDb, const char* pcStr, const char* pcStr2, char** ppStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_load_extension"));
    sqlite3_load_extension_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_load_extension_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_LOAD_EXTENSION);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_LOAD_EXTENSION)
        SQLITE3_PROXY_HANDLE_SQLITE3_LOAD_EXTENSION();
    #endif
    return orgFnPtr(pDb, pcStr, pcStr2, ppStr);
}

SQLITE3_PROXY_EXPORT void* hook_sqlite3_malloc(int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_malloc"));
    sqlite3_malloc_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_malloc_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_MALLOC);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_MALLOC)
        SQLITE3_PROXY_HANDLE_SQLITE3_MALLOC();
    #endif
    return orgFnPtr(i);
}

SQLITE3_PROXY_EXPORT void* hook_sqlite3_malloc64(sqlite3_uint64 u64)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_malloc64"));
    sqlite3_malloc64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_malloc64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_MALLOC64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_MALLOC64)
        SQLITE3_PROXY_HANDLE_SQLITE3_MALLOC64();
    #endif
    return orgFnPtr(u64);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_memory_alarm(void (*pfn)(void*, sqlite3_int64, int), void* pv, sqlite3_int64 i64)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_memory_alarm"));
    sqlite3_memory_alarm_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_memory_alarm_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_MEMORY_ALARM);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_MEMORY_ALARM)
        SQLITE3_PROXY_HANDLE_SQLITE3_MEMORY_ALARM();
    #endif
    return orgFnPtr(pfn, pv, i64);
}

SQLITE3_PROXY_EXPORT sqlite3_int64 hook_sqlite3_memory_highwater(int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_memory_highwater"));
    sqlite3_memory_highwater_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_memory_highwater_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_MEMORY_HIGHWATER);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_MEMORY_HIGHWATER)
        SQLITE3_PROXY_HANDLE_SQLITE3_MEMORY_HIGHWATER();
    #endif
    return orgFnPtr(i);
}

SQLITE3_PROXY_EXPORT sqlite3_int64 hook_sqlite3_memory_used(void)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_memory_used"));
    sqlite3_memory_used_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_memory_used_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_MEMORY_USED);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_MEMORY_USED)
        SQLITE3_PROXY_HANDLE_SQLITE3_MEMORY_USED();
    #endif
    return orgFnPtr();
}

SQLITE3_PROXY_EXPORT sqlite3_uint64 hook_sqlite3_msize(void* pv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_msize"));
    sqlite3_msize_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_msize_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_MSIZE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_MSIZE)
        SQLITE3_PROXY_HANDLE_SQLITE3_MSIZE();
    #endif
    return orgFnPtr(pv);
}

SQLITE3_PROXY_EXPORT sqlite3_mutex* hook_sqlite3_mutex_alloc(int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_mutex_alloc"));
    sqlite3_mutex_alloc_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_mutex_alloc_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_MUTEX_ALLOC);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_MUTEX_ALLOC)
        SQLITE3_PROXY_HANDLE_SQLITE3_MUTEX_ALLOC();
    #endif
    return orgFnPtr(i);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_mutex_enter(sqlite3_mutex* pMutex)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_mutex_enter"));
    sqlite3_mutex_enter_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_mutex_enter_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_MUTEX_ENTER);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_MUTEX_ENTER)
        SQLITE3_PROXY_HANDLE_SQLITE3_MUTEX_ENTER();
    #endif
    orgFnPtr(pMutex);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_mutex_free(sqlite3_mutex* pMutex)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_mutex_free"));
    sqlite3_mutex_free_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_mutex_free_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_MUTEX_FREE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_MUTEX_FREE)
        SQLITE3_PROXY_HANDLE_SQLITE3_MUTEX_FREE();
    #endif
    orgFnPtr(pMutex);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_mutex_leave(sqlite3_mutex* pMutex)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_mutex_leave"));
    sqlite3_mutex_leave_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_mutex_leave_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_MUTEX_LEAVE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_MUTEX_LEAVE)
        SQLITE3_PROXY_HANDLE_SQLITE3_MUTEX_LEAVE();
    #endif
    orgFnPtr(pMutex);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_mutex_try(sqlite3_mutex* pMutex)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_mutex_try"));
    sqlite3_mutex_try_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_mutex_try_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_MUTEX_TRY);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_MUTEX_TRY)
        SQLITE3_PROXY_HANDLE_SQLITE3_MUTEX_TRY();
    #endif
    return orgFnPtr(pMutex);
}

SQLITE3_PROXY_EXPORT sqlite3_stmt* hook_sqlite3_next_stmt(sqlite3* pDb, sqlite3_stmt* pStmt)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_next_stmt"));
    sqlite3_next_stmt_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_next_stmt_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_NEXT_STMT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_NEXT_STMT)
        SQLITE3_PROXY_HANDLE_SQLITE3_NEXT_STMT();
    #endif
    return orgFnPtr(pDb, pStmt);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_open(const char* pcStr, sqlite3** ppDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_open"));
    sqlite3_open_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_open_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_OPEN);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_OPEN)
        SQLITE3_PROXY_HANDLE_SQLITE3_OPEN();
    #endif
    return orgFnPtr(pcStr, ppDb);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_open16(const void* pcv, sqlite3** ppDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_open16"));
    sqlite3_open16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_open16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_OPEN16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_OPEN16)
        SQLITE3_PROXY_HANDLE_SQLITE3_OPEN16();
    #endif
    return orgFnPtr(pcv, ppDb);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_open_v2(const char* pcStr, sqlite3** ppDb, int i, const char* pcStr2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_open_v2"));
    sqlite3_open_v2_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_open_v2_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_OPEN_V2);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_OPEN_V2)
        SQLITE3_PROXY_HANDLE_SQLITE3_OPEN_V2();
    #endif
    return orgFnPtr(pcStr, ppDb, i, pcStr2);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_os_end(void)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_os_end"));
    sqlite3_os_end_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_os_end_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_OS_END);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_OS_END)
        SQLITE3_PROXY_HANDLE_SQLITE3_OS_END();
    #endif
    return orgFnPtr();
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_os_init(void)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_os_init"));
    sqlite3_os_init_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_os_init_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_OS_INIT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_OS_INIT)
        SQLITE3_PROXY_HANDLE_SQLITE3_OS_INIT();
    #endif
    return orgFnPtr();
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_overload_function(sqlite3* pDb, const char* zFuncName, int nArg)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_overload_function"));
    sqlite3_overload_function_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_overload_function_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_OVERLOAD_FUNCTION);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_OVERLOAD_FUNCTION)
        SQLITE3_PROXY_HANDLE_SQLITE3_OVERLOAD_FUNCTION();
    #endif
    return orgFnPtr(pDb, zFuncName, nArg);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_prepare(sqlite3* pDb, const char* pcStr, int i, sqlite3_stmt** ppStmt, const char** ppcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_prepare"));
    sqlite3_prepare_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_prepare_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_PREPARE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_PREPARE)
        SQLITE3_PROXY_HANDLE_SQLITE3_PREPARE();
    #endif
    return orgFnPtr(pDb, pcStr, i, ppStmt, ppcStr);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_prepare16(sqlite3* pDb, const void* pcv, int i, sqlite3_stmt** ppStmt, const void** ppcv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_prepare16"));
    sqlite3_prepare16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_prepare16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_PREPARE16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_PREPARE16)
        SQLITE3_PROXY_HANDLE_SQLITE3_PREPARE16();
    #endif
    return orgFnPtr(pDb, pcv, i, ppStmt, ppcv);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_prepare16_v2(sqlite3* pDb, const void* pcv, int i, sqlite3_stmt** ppStmt, const void** ppcv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_prepare16_v2"));
    sqlite3_prepare16_v2_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_prepare16_v2_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_PREPARE16_V2);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_PREPARE16_V2)
        SQLITE3_PROXY_HANDLE_SQLITE3_PREPARE16_V2();
    #endif
    return orgFnPtr(pDb, pcv, i, ppStmt, ppcv);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_prepare16_v3(sqlite3* pDb, const void* pcv, int i, unsigned int u, sqlite3_stmt** ppStmt, const void** ppcv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_prepare16_v3"));
    sqlite3_prepare16_v3_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_prepare16_v3_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_PREPARE16_V3);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_PREPARE16_V3)
        SQLITE3_PROXY_HANDLE_SQLITE3_PREPARE16_V3();
    #endif
    return orgFnPtr(pDb, pcv, i, u, ppStmt, ppcv);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_prepare_v2(sqlite3* pDb, const char* pcStr, int i, sqlite3_stmt** ppStmt, const char** ppcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_prepare_v2"));
    sqlite3_prepare_v2_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_prepare_v2_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_PREPARE_V2);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_PREPARE_V2)
        SQLITE3_PROXY_HANDLE_SQLITE3_PREPARE_V2();
    #endif
    return orgFnPtr(pDb, pcStr, i, ppStmt, ppcStr);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_prepare_v3(sqlite3* pDb, const char* pcStr, int i, unsigned int u, sqlite3_stmt** ppStmt, const char** ppcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_prepare_v3"));
    sqlite3_prepare_v3_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_prepare_v3_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_PREPARE_V3);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_PREPARE_V3)
        SQLITE3_PROXY_HANDLE_SQLITE3_PREPARE_V3();
    #endif
    return orgFnPtr(pDb, pcStr, i, u, ppStmt, ppcStr);
}

SQLITE3_PROXY_EXPORT void* hook_sqlite3_profile(sqlite3* pDb, void (*pfn)(void*, const char*, sqlite_uint64), void* pv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_profile"));
    sqlite3_profile_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_profile_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_PROFILE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_PROFILE)
        SQLITE3_PROXY_HANDLE_SQLITE3_PROFILE();
    #endif
    return orgFnPtr(pDb, pfn, pv);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_progress_handler(sqlite3* pDb, int i, int (*pfn)(void*), void* pv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_progress_handler"));
    sqlite3_progress_handler_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_progress_handler_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_PROGRESS_HANDLER);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_PROGRESS_HANDLER)
        SQLITE3_PROXY_HANDLE_SQLITE3_PROGRESS_HANDLER();
    #endif
    orgFnPtr(pDb, i, pfn, pv);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_randomness(int i, void* pv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_randomness"));
    sqlite3_randomness_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_randomness_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RANDOMNESS);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RANDOMNESS)
        SQLITE3_PROXY_HANDLE_SQLITE3_RANDOMNESS();
    #endif
    orgFnPtr(i, pv);
}

SQLITE3_PROXY_EXPORT void* hook_sqlite3_realloc(void* pv, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_realloc"));
    sqlite3_realloc_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_realloc_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_REALLOC);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_REALLOC)
        SQLITE3_PROXY_HANDLE_SQLITE3_REALLOC();
    #endif
    return orgFnPtr(pv, i);
}

SQLITE3_PROXY_EXPORT void* hook_sqlite3_realloc64(void* pv, sqlite3_uint64 u64)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_realloc64"));
    sqlite3_realloc64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_realloc64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_REALLOC64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_REALLOC64)
        SQLITE3_PROXY_HANDLE_SQLITE3_REALLOC64();
    #endif
    return orgFnPtr(pv, u64);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_rekey(sqlite3* db, const void* pKey, int nKey)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_rekey"));
    sqlite3_rekey_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_rekey_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_REKEY);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_REKEY)
        SQLITE3_PROXY_HANDLE_SQLITE3_REKEY();
    #endif
    return orgFnPtr(db, pKey, nKey);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_rekey_v2(sqlite3* db, const char* zDbName, const void* pKey, int nKey)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_rekey_v2"));
    sqlite3_rekey_v2_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_rekey_v2_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_REKEY_V2);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_REKEY_V2)
        SQLITE3_PROXY_HANDLE_SQLITE3_REKEY_V2();
    #endif
    return orgFnPtr(db, zDbName, pKey, nKey);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_release_memory(int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_release_memory"));
    sqlite3_release_memory_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_release_memory_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RELEASE_MEMORY);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RELEASE_MEMORY)
        SQLITE3_PROXY_HANDLE_SQLITE3_RELEASE_MEMORY();
    #endif
    return orgFnPtr(i);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_reset(sqlite3_stmt* pStmt)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_reset"));
    sqlite3_reset_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_reset_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESET);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESET)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESET();
    #endif
    return orgFnPtr(pStmt);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_reset_auto_extension(void)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_reset_auto_extension"));
    sqlite3_reset_auto_extension_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_reset_auto_extension_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESET_AUTO_EXTENSION);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESET_AUTO_EXTENSION)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESET_AUTO_EXTENSION();
    #endif
    orgFnPtr();
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_blob(sqlite3_context* pCtx, const void* pcv, int i, void (*pfn)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_blob"));
    sqlite3_result_blob_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_blob_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_BLOB);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_BLOB)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_BLOB();
    #endif
    orgFnPtr(pCtx, pcv, i, pfn);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_blob64(sqlite3_context* pCtx, const void* pcv, sqlite3_uint64 u64, void (*pfn)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_blob64"));
    sqlite3_result_blob64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_blob64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_BLOB64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_BLOB64)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_BLOB64();
    #endif
    orgFnPtr(pCtx, pcv, u64, pfn);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_double(sqlite3_context* pCtx, double dbl)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_double"));
    sqlite3_result_double_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_double_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_DOUBLE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_DOUBLE)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_DOUBLE();
    #endif
    orgFnPtr(pCtx, dbl);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_error(sqlite3_context* pCtx, const char* pcStr, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_error"));
    sqlite3_result_error_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_error_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_ERROR);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_ERROR)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_ERROR();
    #endif
    orgFnPtr(pCtx, pcStr, i);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_error16(sqlite3_context* pCtx, const void* pcv, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_error16"));
    sqlite3_result_error16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_error16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_ERROR16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_ERROR16)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_ERROR16();
    #endif
    orgFnPtr(pCtx, pcv, i);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_error_code(sqlite3_context* pCtx, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_error_code"));
    sqlite3_result_error_code_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_error_code_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_ERROR_CODE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_ERROR_CODE)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_ERROR_CODE();
    #endif
    orgFnPtr(pCtx, i);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_error_nomem(sqlite3_context* pCtx)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_error_nomem"));
    sqlite3_result_error_nomem_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_error_nomem_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_ERROR_NOMEM);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_ERROR_NOMEM)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_ERROR_NOMEM();
    #endif
    orgFnPtr(pCtx);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_error_toobig(sqlite3_context* pCtx)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_error_toobig"));
    sqlite3_result_error_toobig_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_error_toobig_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_ERROR_TOOBIG);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_ERROR_TOOBIG)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_ERROR_TOOBIG();
    #endif
    orgFnPtr(pCtx);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_int(sqlite3_context* pCtx, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_int"));
    sqlite3_result_int_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_int_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_INT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_INT)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_INT();
    #endif
    orgFnPtr(pCtx, i);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_int64(sqlite3_context* pCtx, sqlite_int64 i64)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_int64"));
    sqlite3_result_int64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_int64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_INT64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_INT64)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_INT64();
    #endif
    orgFnPtr(pCtx, i64);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_null(sqlite3_context* pCtx)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_null"));
    sqlite3_result_null_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_null_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_NULL);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_NULL)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_NULL();
    #endif
    orgFnPtr(pCtx);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_pointer(sqlite3_context* pCtx, void* pv, const char* pcStr, void (*pfn)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_pointer"));
    sqlite3_result_pointer_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_pointer_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_POINTER);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_POINTER)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_POINTER();
    #endif
    orgFnPtr(pCtx, pv, pcStr, pfn);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_subtype(sqlite3_context* pCtx, unsigned int u)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_subtype"));
    sqlite3_result_subtype_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_subtype_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_SUBTYPE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_SUBTYPE)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_SUBTYPE();
    #endif
    orgFnPtr(pCtx, u);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_text(sqlite3_context* pCtx, const char* pcStr, int i, void (*pfn)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_text"));
    sqlite3_result_text_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_text_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_TEXT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_TEXT)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_TEXT();
    #endif
    orgFnPtr(pCtx, pcStr, i, pfn);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_text16(sqlite3_context* pCtx, const void* pcv, int i, void (*pfn)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_text16"));
    sqlite3_result_text16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_text16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_TEXT16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_TEXT16)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_TEXT16();
    #endif
    orgFnPtr(pCtx, pcv, i, pfn);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_text16be(sqlite3_context* pCtx, const void* pcv, int i, void (*pfn)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_text16be"));
    sqlite3_result_text16be_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_text16be_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_TEXT16BE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_TEXT16BE)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_TEXT16BE();
    #endif
    orgFnPtr(pCtx, pcv, i, pfn);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_text16le(sqlite3_context* pCtx, const void* pcv, int i, void (*pfn)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_text16le"));
    sqlite3_result_text16le_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_text16le_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_TEXT16LE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_TEXT16LE)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_TEXT16LE();
    #endif
    orgFnPtr(pCtx, pcv, i, pfn);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_text64(sqlite3_context* pCtx, const char* pcStr, sqlite3_uint64 u64, void (*pfn)(void*), unsigned char uch)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_text64"));
    sqlite3_result_text64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_text64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_TEXT64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_TEXT64)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_TEXT64();
    #endif
    orgFnPtr(pCtx, pcStr, u64, pfn, uch);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_value(sqlite3_context* pCtx, sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_value"));
    sqlite3_result_value_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_value_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_VALUE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_VALUE)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_VALUE();
    #endif
    orgFnPtr(pCtx, pVal);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_result_zeroblob(sqlite3_context* pCtx, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_zeroblob"));
    sqlite3_result_zeroblob_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_zeroblob_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_ZEROBLOB);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_ZEROBLOB)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_ZEROBLOB();
    #endif
    orgFnPtr(pCtx, i);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_result_zeroblob64(sqlite3_context* pCtx, sqlite3_uint64 u64)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_result_zeroblob64"));
    sqlite3_result_zeroblob64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_result_zeroblob64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RESULT_ZEROBLOB64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_ZEROBLOB64)
        SQLITE3_PROXY_HANDLE_SQLITE3_RESULT_ZEROBLOB64();
    #endif
    return orgFnPtr(pCtx, u64);
}

SQLITE3_PROXY_EXPORT void* hook_sqlite3_rollback_hook(sqlite3* pDb, void (*pfn)(void*), void* pv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_rollback_hook"));
    sqlite3_rollback_hook_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_rollback_hook_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_ROLLBACK_HOOK);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_ROLLBACK_HOOK)
        SQLITE3_PROXY_HANDLE_SQLITE3_ROLLBACK_HOOK();
    #endif
    return orgFnPtr(pDb, pfn, pv);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_rtree_geometry_callback(sqlite3* db, const char* zGeom, int (*sqlite3_xGeom)(sqlite3_rtree_geometry*, int, sqlite3_rtree_dbl*, int*), void* pContext)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_rtree_geometry_callback"));
    sqlite3_rtree_geometry_callback_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_rtree_geometry_callback_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RTREE_GEOMETRY_CALLBACK);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RTREE_GEOMETRY_CALLBACK)
        SQLITE3_PROXY_HANDLE_SQLITE3_RTREE_GEOMETRY_CALLBACK();
    #endif
    return orgFnPtr(db, zGeom, sqlite3_xGeom, pContext);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_rtree_query_callback(sqlite3* db, const char* zQueryFunc, int (*sqlite3_xQueryFunc)(sqlite3_rtree_query_info*), void* pContext, void (*sqlite3_xDestructor)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_rtree_query_callback"));
    sqlite3_rtree_query_callback_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_rtree_query_callback_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_RTREE_QUERY_CALLBACK);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_RTREE_QUERY_CALLBACK)
        SQLITE3_PROXY_HANDLE_SQLITE3_RTREE_QUERY_CALLBACK();
    #endif
    return orgFnPtr(db, zQueryFunc, sqlite3_xQueryFunc, pContext, sqlite3_xDestructor);
}

SQLITE3_PROXY_EXPORT unsigned char* hook_sqlite3_serialize(sqlite3* pDb, const char* pcStr, sqlite3_int64* pI64, unsigned int u)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_serialize"));
    sqlite3_serialize_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_serialize_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_SERIALIZE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_SERIALIZE)
        SQLITE3_PROXY_HANDLE_SQLITE3_SERIALIZE();
    #endif
    return orgFnPtr(pDb, pcStr, pI64, u);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_set_authorizer(sqlite3* pDb, int (*pfn)(void*, int, const char*, const char*, const char*, const char*), void* pv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_set_authorizer"));
    sqlite3_set_authorizer_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_set_authorizer_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_SET_AUTHORIZER);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_SET_AUTHORIZER)
        SQLITE3_PROXY_HANDLE_SQLITE3_SET_AUTHORIZER();
    #endif
    return orgFnPtr(pDb, pfn, pv);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_set_auxdata(sqlite3_context* pCtx, int i, void* pv, void (*pfn)(void*))
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_set_auxdata"));
    sqlite3_set_auxdata_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_set_auxdata_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_SET_AUXDATA);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_SET_AUXDATA)
        SQLITE3_PROXY_HANDLE_SQLITE3_SET_AUXDATA();
    #endif
    orgFnPtr(pCtx, i, pv, pfn);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_set_last_insert_rowid(sqlite3* pDb, sqlite3_int64 i64)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_set_last_insert_rowid"));
    sqlite3_set_last_insert_rowid_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_set_last_insert_rowid_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_SET_LAST_INSERT_ROWID);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_SET_LAST_INSERT_ROWID)
        SQLITE3_PROXY_HANDLE_SQLITE3_SET_LAST_INSERT_ROWID();
    #endif
    orgFnPtr(pDb, i64);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_shutdown(void)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_shutdown"));
    sqlite3_shutdown_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_shutdown_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_SHUTDOWN);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_SHUTDOWN)
        SQLITE3_PROXY_HANDLE_SQLITE3_SHUTDOWN();
    #endif
    return orgFnPtr();
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_sleep(int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_sleep"));
    sqlite3_sleep_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_sleep_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_SLEEP);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_SLEEP)
        SQLITE3_PROXY_HANDLE_SQLITE3_SLEEP();
    #endif
    return orgFnPtr(i);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_snapshot_cmp(sqlite3_snapshot* p1, sqlite3_snapshot* p2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_snapshot_cmp"));
    sqlite3_snapshot_cmp_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_snapshot_cmp_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_SNAPSHOT_CMP);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_SNAPSHOT_CMP)
        SQLITE3_PROXY_HANDLE_SQLITE3_SNAPSHOT_CMP();
    #endif
    return orgFnPtr(p1, p2);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_snapshot_free(sqlite3_snapshot* pSnapShot)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_snapshot_free"));
    sqlite3_snapshot_free_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_snapshot_free_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_SNAPSHOT_FREE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_SNAPSHOT_FREE)
        SQLITE3_PROXY_HANDLE_SQLITE3_SNAPSHOT_FREE();
    #endif
    orgFnPtr(pSnapShot);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_snapshot_get(sqlite3* db, const char* zSchema, sqlite3_snapshot** ppSnapshot)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_snapshot_get"));
    sqlite3_snapshot_get_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_snapshot_get_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_SNAPSHOT_GET);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_SNAPSHOT_GET)
        SQLITE3_PROXY_HANDLE_SQLITE3_SNAPSHOT_GET();
    #endif
    return orgFnPtr(db, zSchema, ppSnapshot);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_snapshot_open(sqlite3* db, const char* zSchema, sqlite3_snapshot* pSnapshot)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_snapshot_open"));
    sqlite3_snapshot_open_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_snapshot_open_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_SNAPSHOT_OPEN);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_SNAPSHOT_OPEN)
        SQLITE3_PROXY_HANDLE_SQLITE3_SNAPSHOT_OPEN();
    #endif
    return orgFnPtr(db, zSchema, pSnapshot);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_snapshot_recover(sqlite3* db, const char* zDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_snapshot_recover"));
    sqlite3_snapshot_recover_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_snapshot_recover_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_SNAPSHOT_RECOVER);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_SNAPSHOT_RECOVER)
        SQLITE3_PROXY_HANDLE_SQLITE3_SNAPSHOT_RECOVER();
    #endif
    return orgFnPtr(db, zDb);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_soft_heap_limit(int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_soft_heap_limit"));
    sqlite3_soft_heap_limit_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_soft_heap_limit_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_SOFT_HEAP_LIMIT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_SOFT_HEAP_LIMIT)
        SQLITE3_PROXY_HANDLE_SQLITE3_SOFT_HEAP_LIMIT();
    #endif
    orgFnPtr(i);
}

SQLITE3_PROXY_EXPORT sqlite3_int64 hook_sqlite3_soft_heap_limit64(sqlite3_int64 i64)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_soft_heap_limit64"));
    sqlite3_soft_heap_limit64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_soft_heap_limit64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_SOFT_HEAP_LIMIT64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_SOFT_HEAP_LIMIT64)
        SQLITE3_PROXY_HANDLE_SQLITE3_SOFT_HEAP_LIMIT64();
    #endif
    return orgFnPtr(i64);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_sourceid(void)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_sourceid"));
    sqlite3_sourceid_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_sourceid_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_SOURCEID);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_SOURCEID)
        SQLITE3_PROXY_HANDLE_SQLITE3_SOURCEID();
    #endif
    return orgFnPtr();
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_sql(sqlite3_stmt* pStmt)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_sql"));
    sqlite3_sql_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_sql_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_SQL);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_SQL)
        SQLITE3_PROXY_HANDLE_SQLITE3_SQL();
    #endif
    return orgFnPtr(pStmt);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_status(int i, int* pInt, int* pInt2, int i2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_status"));
    sqlite3_status_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_status_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STATUS);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STATUS)
        SQLITE3_PROXY_HANDLE_SQLITE3_STATUS();
    #endif
    return orgFnPtr(i, pInt, pInt2, i2);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_status64(int i, sqlite3_int64* pI64, sqlite3_int64* pI642, int i2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_status64"));
    sqlite3_status64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_status64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STATUS64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STATUS64)
        SQLITE3_PROXY_HANDLE_SQLITE3_STATUS64();
    #endif
    return orgFnPtr(i, pI64, pI642, i2);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_step(sqlite3_stmt* pStmt)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_step"));
    sqlite3_step_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_step_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STEP);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STEP)
        SQLITE3_PROXY_HANDLE_SQLITE3_STEP();
    #endif
    return orgFnPtr(pStmt);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_stmt_busy(sqlite3_stmt* pStmt)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_stmt_busy"));
    sqlite3_stmt_busy_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_stmt_busy_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STMT_BUSY);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STMT_BUSY)
        SQLITE3_PROXY_HANDLE_SQLITE3_STMT_BUSY();
    #endif
    return orgFnPtr(pStmt);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_stmt_isexplain(sqlite3_stmt* pStmt)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_stmt_isexplain"));
    sqlite3_stmt_isexplain_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_stmt_isexplain_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STMT_ISEXPLAIN);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STMT_ISEXPLAIN)
        SQLITE3_PROXY_HANDLE_SQLITE3_STMT_ISEXPLAIN();
    #endif
    return orgFnPtr(pStmt);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_stmt_readonly(sqlite3_stmt* pStmt)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_stmt_readonly"));
    sqlite3_stmt_readonly_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_stmt_readonly_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STMT_READONLY);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STMT_READONLY)
        SQLITE3_PROXY_HANDLE_SQLITE3_STMT_READONLY();
    #endif
    return orgFnPtr(pStmt);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_stmt_status(sqlite3_stmt* pStmt, int i, int i2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_stmt_status"));
    sqlite3_stmt_status_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_stmt_status_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STMT_STATUS);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STMT_STATUS)
        SQLITE3_PROXY_HANDLE_SQLITE3_STMT_STATUS();
    #endif
    return orgFnPtr(pStmt, i, i2);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_str_append(sqlite3_str* pqStr, const char* zIn, int N)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_str_append"));
    sqlite3_str_append_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_str_append_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STR_APPEND);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STR_APPEND)
        SQLITE3_PROXY_HANDLE_SQLITE3_STR_APPEND();
    #endif
    orgFnPtr(pqStr, zIn, N);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_str_appendall(sqlite3_str* pqStr, const char* zIn)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_str_appendall"));
    sqlite3_str_appendall_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_str_appendall_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STR_APPENDALL);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STR_APPENDALL)
        SQLITE3_PROXY_HANDLE_SQLITE3_STR_APPENDALL();
    #endif
    orgFnPtr(pqStr, zIn);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_str_appendchar(sqlite3_str* pqStr, int N, char C)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_str_appendchar"));
    sqlite3_str_appendchar_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_str_appendchar_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STR_APPENDCHAR);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STR_APPENDCHAR)
        SQLITE3_PROXY_HANDLE_SQLITE3_STR_APPENDCHAR();
    #endif
    orgFnPtr(pqStr, N, C);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_str_errcode(sqlite3_str* pqStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_str_errcode"));
    sqlite3_str_errcode_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_str_errcode_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STR_ERRCODE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STR_ERRCODE)
        SQLITE3_PROXY_HANDLE_SQLITE3_STR_ERRCODE();
    #endif
    return orgFnPtr(pqStr);
}

SQLITE3_PROXY_EXPORT char* hook_sqlite3_str_finish(sqlite3_str* pqStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_str_finish"));
    sqlite3_str_finish_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_str_finish_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STR_FINISH);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STR_FINISH)
        SQLITE3_PROXY_HANDLE_SQLITE3_STR_FINISH();
    #endif
    return orgFnPtr(pqStr);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_str_length(sqlite3_str* pqStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_str_length"));
    sqlite3_str_length_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_str_length_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STR_LENGTH);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STR_LENGTH)
        SQLITE3_PROXY_HANDLE_SQLITE3_STR_LENGTH();
    #endif
    return orgFnPtr(pqStr);
}

SQLITE3_PROXY_EXPORT sqlite3_str* hook_sqlite3_str_new(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_str_new"));
    sqlite3_str_new_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_str_new_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STR_NEW);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STR_NEW)
        SQLITE3_PROXY_HANDLE_SQLITE3_STR_NEW();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_str_reset(sqlite3_str* pqStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_str_reset"));
    sqlite3_str_reset_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_str_reset_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STR_RESET);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STR_RESET)
        SQLITE3_PROXY_HANDLE_SQLITE3_STR_RESET();
    #endif
    orgFnPtr(pqStr);
}

SQLITE3_PROXY_EXPORT char* hook_sqlite3_str_value(sqlite3_str* pqStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_str_value"));
    sqlite3_str_value_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_str_value_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STR_VALUE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STR_VALUE)
        SQLITE3_PROXY_HANDLE_SQLITE3_STR_VALUE();
    #endif
    return orgFnPtr(pqStr);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_str_vappendf(sqlite3_str* pqStr, const char* zFormat, va_list vaLst)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_str_vappendf"));
    sqlite3_str_vappendf_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_str_vappendf_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STR_VAPPENDF);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STR_VAPPENDF)
        SQLITE3_PROXY_HANDLE_SQLITE3_STR_VAPPENDF();
    #endif
    orgFnPtr(pqStr, zFormat, vaLst);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_strglob(const char* pcStr, const char* pcStr2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_strglob"));
    sqlite3_strglob_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_strglob_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STRGLOB);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STRGLOB)
        SQLITE3_PROXY_HANDLE_SQLITE3_STRGLOB();
    #endif
    return orgFnPtr(pcStr, pcStr2);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_stricmp(const char* pcStr, const char* pcStr2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_stricmp"));
    sqlite3_stricmp_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_stricmp_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STRICMP);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STRICMP)
        SQLITE3_PROXY_HANDLE_SQLITE3_STRICMP();
    #endif
    return orgFnPtr(pcStr, pcStr2);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_strlike(const char* pcStr, const char* pcStr2, unsigned int u)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_strlike"));
    sqlite3_strlike_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_strlike_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STRLIKE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STRLIKE)
        SQLITE3_PROXY_HANDLE_SQLITE3_STRLIKE();
    #endif
    return orgFnPtr(pcStr, pcStr2, u);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_strnicmp(const char* pcStr, const char* pcStr2, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_strnicmp"));
    sqlite3_strnicmp_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_strnicmp_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_STRNICMP);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_STRNICMP)
        SQLITE3_PROXY_HANDLE_SQLITE3_STRNICMP();
    #endif
    return orgFnPtr(pcStr, pcStr2, i);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_system_errno(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_system_errno"));
    sqlite3_system_errno_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_system_errno_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_SYSTEM_ERRNO);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_SYSTEM_ERRNO)
        SQLITE3_PROXY_HANDLE_SQLITE3_SYSTEM_ERRNO();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_table_column_metadata(sqlite3* pDb, const char* pcStr, const char* pcStr2, const char* pcStr3, char const** ppcStr, char const** ppcStr2, int* pInt, int* pInt2, int* pInt3)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_table_column_metadata"));
    sqlite3_table_column_metadata_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_table_column_metadata_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_TABLE_COLUMN_METADATA);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_TABLE_COLUMN_METADATA)
        SQLITE3_PROXY_HANDLE_SQLITE3_TABLE_COLUMN_METADATA();
    #endif
    return orgFnPtr(pDb, pcStr, pcStr2, pcStr3, ppcStr, ppcStr2, pInt, pInt2, pInt3);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_thread_cleanup(void)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_thread_cleanup"));
    sqlite3_thread_cleanup_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_thread_cleanup_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_THREAD_CLEANUP);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_THREAD_CLEANUP)
        SQLITE3_PROXY_HANDLE_SQLITE3_THREAD_CLEANUP();
    #endif
    orgFnPtr();
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_threadsafe(void)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_threadsafe"));
    sqlite3_threadsafe_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_threadsafe_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_THREADSAFE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_THREADSAFE)
        SQLITE3_PROXY_HANDLE_SQLITE3_THREADSAFE();
    #endif
    return orgFnPtr();
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_total_changes(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_total_changes"));
    sqlite3_total_changes_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_total_changes_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_TOTAL_CHANGES);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_TOTAL_CHANGES)
        SQLITE3_PROXY_HANDLE_SQLITE3_TOTAL_CHANGES();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT sqlite3_int64 hook_sqlite3_total_changes64(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_total_changes64"));
    sqlite3_total_changes64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_total_changes64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_TOTAL_CHANGES64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_TOTAL_CHANGES64)
        SQLITE3_PROXY_HANDLE_SQLITE3_TOTAL_CHANGES64();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT void* hook_sqlite3_trace(sqlite3* pDb, void (*sqlite3_xTrace)(void*, const char*), void* pv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_trace"));
    sqlite3_trace_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_trace_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_TRACE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_TRACE)
        SQLITE3_PROXY_HANDLE_SQLITE3_TRACE();
    #endif
    return orgFnPtr(pDb, sqlite3_xTrace, pv);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_trace_v2(sqlite3* pDb, unsigned u, int (*pfn)(unsigned, void*, void*, void*), void* pv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_trace_v2"));
    sqlite3_trace_v2_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_trace_v2_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_TRACE_V2);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_TRACE_V2)
        SQLITE3_PROXY_HANDLE_SQLITE3_TRACE_V2();
    #endif
    return orgFnPtr(pDb, u, pfn, pv);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_transfer_bindings(sqlite3_stmt* pStmt, sqlite3_stmt* pStmt2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_transfer_bindings"));
    sqlite3_transfer_bindings_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_transfer_bindings_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_TRANSFER_BINDINGS);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_TRANSFER_BINDINGS)
        SQLITE3_PROXY_HANDLE_SQLITE3_TRANSFER_BINDINGS();
    #endif
    return orgFnPtr(pStmt, pStmt2);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_txn_state(sqlite3* pDb, const char* pcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_txn_state"));
    sqlite3_txn_state_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_txn_state_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_TXN_STATE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_TXN_STATE)
        SQLITE3_PROXY_HANDLE_SQLITE3_TXN_STATE();
    #endif
    return orgFnPtr(pDb, pcStr);
}

SQLITE3_PROXY_EXPORT void* hook_sqlite3_update_hook(sqlite3* pDb, void (*pfn)(void*, int, char const*, char const*, sqlite_int64), void* pv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_update_hook"));
    sqlite3_update_hook_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_update_hook_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_UPDATE_HOOK);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_UPDATE_HOOK)
        SQLITE3_PROXY_HANDLE_SQLITE3_UPDATE_HOOK();
    #endif
    return orgFnPtr(pDb, pfn, pv);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_uri_boolean(const char* pcStr, const char* pcStr2, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_uri_boolean"));
    sqlite3_uri_boolean_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_uri_boolean_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_URI_BOOLEAN);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_URI_BOOLEAN)
        SQLITE3_PROXY_HANDLE_SQLITE3_URI_BOOLEAN();
    #endif
    return orgFnPtr(pcStr, pcStr2, i);
}

SQLITE3_PROXY_EXPORT sqlite3_int64 hook_sqlite3_uri_int64(const char* pcStr, const char* pcStr2, sqlite3_int64 i64)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_uri_int64"));
    sqlite3_uri_int64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_uri_int64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_URI_INT64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_URI_INT64)
        SQLITE3_PROXY_HANDLE_SQLITE3_URI_INT64();
    #endif
    return orgFnPtr(pcStr, pcStr2, i64);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_uri_key(const char* pcStr, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_uri_key"));
    sqlite3_uri_key_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_uri_key_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_URI_KEY);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_URI_KEY)
        SQLITE3_PROXY_HANDLE_SQLITE3_URI_KEY();
    #endif
    return orgFnPtr(pcStr, i);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_uri_parameter(const char* pcStr, const char* pcStr2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_uri_parameter"));
    sqlite3_uri_parameter_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_uri_parameter_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_URI_PARAMETER);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_URI_PARAMETER)
        SQLITE3_PROXY_HANDLE_SQLITE3_URI_PARAMETER();
    #endif
    return orgFnPtr(pcStr, pcStr2);
}

SQLITE3_PROXY_EXPORT void* hook_sqlite3_user_data(sqlite3_context* pCtx)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_user_data"));
    sqlite3_user_data_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_user_data_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_USER_DATA);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_USER_DATA)
        SQLITE3_PROXY_HANDLE_SQLITE3_USER_DATA();
    #endif
    return orgFnPtr(pCtx);
}

SQLITE3_PROXY_EXPORT const void* hook_sqlite3_value_blob(sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_blob"));
    sqlite3_value_blob_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_blob_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_BLOB);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_BLOB)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_BLOB();
    #endif
    return orgFnPtr(pVal);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_value_bytes(sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_bytes"));
    sqlite3_value_bytes_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_bytes_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_BYTES);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_BYTES)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_BYTES();
    #endif
    return orgFnPtr(pVal);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_value_bytes16(sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_bytes16"));
    sqlite3_value_bytes16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_bytes16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_BYTES16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_BYTES16)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_BYTES16();
    #endif
    return orgFnPtr(pVal);
}

SQLITE3_PROXY_EXPORT double hook_sqlite3_value_double(sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_double"));
    sqlite3_value_double_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_double_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_DOUBLE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_DOUBLE)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_DOUBLE();
    #endif
    return orgFnPtr(pVal);
}

SQLITE3_PROXY_EXPORT sqlite3_value* hook_sqlite3_value_dup(const sqlite3_value* pcVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_dup"));
    sqlite3_value_dup_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_dup_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_DUP);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_DUP)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_DUP();
    #endif
    return orgFnPtr(pcVal);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_value_free(sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_free"));
    sqlite3_value_free_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_free_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_FREE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_FREE)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_FREE();
    #endif
    orgFnPtr(pVal);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_value_frombind(sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_frombind"));
    sqlite3_value_frombind_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_frombind_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_FROMBIND);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_FROMBIND)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_FROMBIND();
    #endif
    return orgFnPtr(pVal);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_value_int(sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_int"));
    sqlite3_value_int_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_int_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_INT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_INT)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_INT();
    #endif
    return orgFnPtr(pVal);
}

SQLITE3_PROXY_EXPORT sqlite_int64 hook_sqlite3_value_int64(sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_int64"));
    sqlite3_value_int64_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_int64_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_INT64);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_INT64)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_INT64();
    #endif
    return orgFnPtr(pVal);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_value_nochange(sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_nochange"));
    sqlite3_value_nochange_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_nochange_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_NOCHANGE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_NOCHANGE)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_NOCHANGE();
    #endif
    return orgFnPtr(pVal);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_value_numeric_type(sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_numeric_type"));
    sqlite3_value_numeric_type_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_numeric_type_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_NUMERIC_TYPE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_NUMERIC_TYPE)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_NUMERIC_TYPE();
    #endif
    return orgFnPtr(pVal);
}

SQLITE3_PROXY_EXPORT void* hook_sqlite3_value_pointer(sqlite3_value* pVal, const char* pcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_pointer"));
    sqlite3_value_pointer_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_pointer_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_POINTER);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_POINTER)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_POINTER();
    #endif
    return orgFnPtr(pVal, pcStr);
}

SQLITE3_PROXY_EXPORT unsigned int hook_sqlite3_value_subtype(sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_subtype"));
    sqlite3_value_subtype_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_subtype_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_SUBTYPE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_SUBTYPE)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_SUBTYPE();
    #endif
    return orgFnPtr(pVal);
}

SQLITE3_PROXY_EXPORT const unsigned char* hook_sqlite3_value_text(sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_text"));
    sqlite3_value_text_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_text_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_TEXT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_TEXT)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_TEXT();
    #endif
    return orgFnPtr(pVal);
}

SQLITE3_PROXY_EXPORT const void* hook_sqlite3_value_text16(sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_text16"));
    sqlite3_value_text16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_text16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_TEXT16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_TEXT16)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_TEXT16();
    #endif
    return orgFnPtr(pVal);
}

SQLITE3_PROXY_EXPORT const void* hook_sqlite3_value_text16be(sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_text16be"));
    sqlite3_value_text16be_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_text16be_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_TEXT16BE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_TEXT16BE)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_TEXT16BE();
    #endif
    return orgFnPtr(pVal);
}

SQLITE3_PROXY_EXPORT const void* hook_sqlite3_value_text16le(sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_text16le"));
    sqlite3_value_text16le_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_text16le_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_TEXT16LE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_TEXT16LE)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_TEXT16LE();
    #endif
    return orgFnPtr(pVal);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_value_type(sqlite3_value* pVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_value_type"));
    sqlite3_value_type_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_value_type_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VALUE_TYPE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_TYPE)
        SQLITE3_PROXY_HANDLE_SQLITE3_VALUE_TYPE();
    #endif
    return orgFnPtr(pVal);
}

SQLITE3_PROXY_EXPORT sqlite3_vfs* hook_sqlite3_vfs_find(const char* pcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_vfs_find"));
    sqlite3_vfs_find_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_vfs_find_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VFS_FIND);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VFS_FIND)
        SQLITE3_PROXY_HANDLE_SQLITE3_VFS_FIND();
    #endif
    return orgFnPtr(pcStr);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_vfs_register(sqlite3_vfs* pVfs, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_vfs_register"));
    sqlite3_vfs_register_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_vfs_register_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VFS_REGISTER);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VFS_REGISTER)
        SQLITE3_PROXY_HANDLE_SQLITE3_VFS_REGISTER();
    #endif
    return orgFnPtr(pVfs, i);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_vfs_unregister(sqlite3_vfs* pVfs)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_vfs_unregister"));
    sqlite3_vfs_unregister_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_vfs_unregister_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VFS_UNREGISTER);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VFS_UNREGISTER)
        SQLITE3_PROXY_HANDLE_SQLITE3_VFS_UNREGISTER();
    #endif
    return orgFnPtr(pVfs);
}

SQLITE3_PROXY_EXPORT char* hook_sqlite3_vmprintf(const char* pcStr, va_list vaLst)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_vmprintf"));
    sqlite3_vmprintf_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_vmprintf_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VMPRINTF);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VMPRINTF)
        SQLITE3_PROXY_HANDLE_SQLITE3_VMPRINTF();
    #endif
    return orgFnPtr(pcStr, vaLst);
}

SQLITE3_PROXY_EXPORT char* hook_sqlite3_vsnprintf(int i, char* pStr, const char* pcStr, va_list vaLst)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_vsnprintf"));
    sqlite3_vsnprintf_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_vsnprintf_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VSNPRINTF);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VSNPRINTF)
        SQLITE3_PROXY_HANDLE_SQLITE3_VSNPRINTF();
    #endif
    return orgFnPtr(i, pStr, pcStr, vaLst);
}

SQLITE3_PROXY_EXPORT const char* hook_sqlite3_vtab_collation(sqlite3_index_info* pIdxInfo, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_vtab_collation"));
    sqlite3_vtab_collation_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_vtab_collation_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VTAB_COLLATION);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VTAB_COLLATION)
        SQLITE3_PROXY_HANDLE_SQLITE3_VTAB_COLLATION();
    #endif
    return orgFnPtr(pIdxInfo, i);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_vtab_distinct(sqlite3_index_info* pIdxInfo)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_vtab_distinct"));
    sqlite3_vtab_distinct_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_vtab_distinct_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VTAB_DISTINCT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VTAB_DISTINCT)
        SQLITE3_PROXY_HANDLE_SQLITE3_VTAB_DISTINCT();
    #endif
    return orgFnPtr(pIdxInfo);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_vtab_in(sqlite3_index_info* pIdxInfo, int i, int i2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_vtab_in"));
    sqlite3_vtab_in_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_vtab_in_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VTAB_IN);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VTAB_IN)
        SQLITE3_PROXY_HANDLE_SQLITE3_VTAB_IN();
    #endif
    return orgFnPtr(pIdxInfo, i, i2);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_vtab_in_first(sqlite3_value* pVal, sqlite3_value** ppVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_vtab_in_first"));
    sqlite3_vtab_in_first_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_vtab_in_first_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VTAB_IN_FIRST);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VTAB_IN_FIRST)
        SQLITE3_PROXY_HANDLE_SQLITE3_VTAB_IN_FIRST();
    #endif
    return orgFnPtr(pVal, ppVal);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_vtab_in_next(sqlite3_value* pVal, sqlite3_value** ppVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_vtab_in_next"));
    sqlite3_vtab_in_next_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_vtab_in_next_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VTAB_IN_NEXT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VTAB_IN_NEXT)
        SQLITE3_PROXY_HANDLE_SQLITE3_VTAB_IN_NEXT();
    #endif
    return orgFnPtr(pVal, ppVal);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_vtab_nochange(sqlite3_context* pCtx)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_vtab_nochange"));
    sqlite3_vtab_nochange_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_vtab_nochange_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VTAB_NOCHANGE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VTAB_NOCHANGE)
        SQLITE3_PROXY_HANDLE_SQLITE3_VTAB_NOCHANGE();
    #endif
    return orgFnPtr(pCtx);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_vtab_on_conflict(sqlite3* pDb)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_vtab_on_conflict"));
    sqlite3_vtab_on_conflict_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_vtab_on_conflict_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VTAB_ON_CONFLICT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VTAB_ON_CONFLICT)
        SQLITE3_PROXY_HANDLE_SQLITE3_VTAB_ON_CONFLICT();
    #endif
    return orgFnPtr(pDb);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_vtab_rhs_value(sqlite3_index_info* pIdxInfo, int i, sqlite3_value** ppVal)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_vtab_rhs_value"));
    sqlite3_vtab_rhs_value_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_vtab_rhs_value_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_VTAB_RHS_VALUE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_VTAB_RHS_VALUE)
        SQLITE3_PROXY_HANDLE_SQLITE3_VTAB_RHS_VALUE();
    #endif
    return orgFnPtr(pIdxInfo, i, ppVal);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_wal_autocheckpoint(sqlite3* pDb, int i)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_wal_autocheckpoint"));
    sqlite3_wal_autocheckpoint_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_wal_autocheckpoint_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_WAL_AUTOCHECKPOINT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_WAL_AUTOCHECKPOINT)
        SQLITE3_PROXY_HANDLE_SQLITE3_WAL_AUTOCHECKPOINT();
    #endif
    return orgFnPtr(pDb, i);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_wal_checkpoint(sqlite3* pDb, const char* pcStr)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_wal_checkpoint"));
    sqlite3_wal_checkpoint_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_wal_checkpoint_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_WAL_CHECKPOINT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_WAL_CHECKPOINT)
        SQLITE3_PROXY_HANDLE_SQLITE3_WAL_CHECKPOINT();
    #endif
    return orgFnPtr(pDb, pcStr);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_wal_checkpoint_v2(sqlite3* pDb, const char* pcStr, int i, int* pInt, int* pInt2)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_wal_checkpoint_v2"));
    sqlite3_wal_checkpoint_v2_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_wal_checkpoint_v2_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_WAL_CHECKPOINT_V2);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_WAL_CHECKPOINT_V2)
        SQLITE3_PROXY_HANDLE_SQLITE3_WAL_CHECKPOINT_V2();
    #endif
    return orgFnPtr(pDb, pcStr, i, pInt, pInt2);
}

SQLITE3_PROXY_EXPORT void* hook_sqlite3_wal_hook(sqlite3* pDb, int (*pfn)(void*, sqlite3*, const char*, int), void* pv)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_wal_hook"));
    sqlite3_wal_hook_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_wal_hook_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_WAL_HOOK);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_WAL_HOOK)
        SQLITE3_PROXY_HANDLE_SQLITE3_WAL_HOOK();
    #endif
    return orgFnPtr(pDb, pfn, pv);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_win32_is_nt(void)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_win32_is_nt"));
    sqlite3_win32_is_nt_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_win32_is_nt_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_IS_NT);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_IS_NT)
        SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_IS_NT();
    #endif
    return orgFnPtr();
}

SQLITE3_PROXY_EXPORT char* hook_sqlite3_win32_mbcs_to_utf8(const char* zText)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_win32_mbcs_to_utf8"));
    sqlite3_win32_mbcs_to_utf8_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_win32_mbcs_to_utf8_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_MBCS_TO_UTF8);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_MBCS_TO_UTF8)
        SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_MBCS_TO_UTF8();
    #endif
    return orgFnPtr(zText);
}

SQLITE3_PROXY_EXPORT char* hook_sqlite3_win32_mbcs_to_utf8_v2(const char* zText, int useAnsi)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_win32_mbcs_to_utf8_v2"));
    sqlite3_win32_mbcs_to_utf8_v2_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_win32_mbcs_to_utf8_v2_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_MBCS_TO_UTF8_V2);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_MBCS_TO_UTF8_V2)
        SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_MBCS_TO_UTF8_V2();
    #endif
    return orgFnPtr(zText, useAnsi);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_win32_set_directory(unsigned long type, void* zValue)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_win32_set_directory"));
    sqlite3_win32_set_directory_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_win32_set_directory_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_SET_DIRECTORY);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_SET_DIRECTORY)
        SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_SET_DIRECTORY();
    #endif
    return orgFnPtr(type, zValue);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_win32_set_directory16(unsigned long type, const void* zValue)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_win32_set_directory16"));
    sqlite3_win32_set_directory16_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_win32_set_directory16_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_SET_DIRECTORY16);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_SET_DIRECTORY16)
        SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_SET_DIRECTORY16();
    #endif
    return orgFnPtr(type, zValue);
}

SQLITE3_PROXY_EXPORT int hook_sqlite3_win32_set_directory8(unsigned long type, const char* zValue)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_win32_set_directory8"));
    sqlite3_win32_set_directory8_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_win32_set_directory8_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_SET_DIRECTORY8);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_SET_DIRECTORY8)
        SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_SET_DIRECTORY8();
    #endif
    return orgFnPtr(type, zValue);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_win32_sleep(DWORD milliseconds)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_win32_sleep"));
    sqlite3_win32_sleep_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_win32_sleep_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_SLEEP);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_SLEEP)
        SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_SLEEP();
    #endif
    orgFnPtr(milliseconds);
}

SQLITE3_PROXY_EXPORT char* hook_sqlite3_win32_unicode_to_utf8(LPCWSTR zWideText)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_win32_unicode_to_utf8"));
    sqlite3_win32_unicode_to_utf8_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_win32_unicode_to_utf8_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_UNICODE_TO_UTF8);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_UNICODE_TO_UTF8)
        SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_UNICODE_TO_UTF8();
    #endif
    return orgFnPtr(zWideText);
}

SQLITE3_PROXY_EXPORT char* hook_sqlite3_win32_utf8_to_mbcs(const char* zText)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_win32_utf8_to_mbcs"));
    sqlite3_win32_utf8_to_mbcs_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_win32_utf8_to_mbcs_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_UTF8_TO_MBCS);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_UTF8_TO_MBCS)
        SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_UTF8_TO_MBCS();
    #endif
    return orgFnPtr(zText);
}

SQLITE3_PROXY_EXPORT char* hook_sqlite3_win32_utf8_to_mbcs_v2(const char* zText, int useAnsi)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_win32_utf8_to_mbcs_v2"));
    sqlite3_win32_utf8_to_mbcs_v2_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_win32_utf8_to_mbcs_v2_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_UTF8_TO_MBCS_V2);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_UTF8_TO_MBCS_V2)
        SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_UTF8_TO_MBCS_V2();
    #endif
    return orgFnPtr(zText, useAnsi);
}

SQLITE3_PROXY_EXPORT LPWSTR hook_sqlite3_win32_utf8_to_unicode(const char* zText)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_win32_utf8_to_unicode"));
    sqlite3_win32_utf8_to_unicode_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_win32_utf8_to_unicode_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_UTF8_TO_UNICODE);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_UTF8_TO_UNICODE)
        SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_UTF8_TO_UNICODE();
    #endif
    return orgFnPtr(zText);
}

SQLITE3_PROXY_EXPORT void hook_sqlite3_win32_write_debug(const char* zBuf, int nBuf)
{
    SQLITE3_PROXY_HELO_TRACE(("!!! Proxy called: %s\n", "sqlite3_win32_write_debug"));
    sqlite3_win32_write_debug_fn_ptr_t orgFnPtr = getOriginalFunctionPtr<sqlite3_win32_write_debug_fn_ptr_t>(SQLITE3_ORG_FN_IDX_SQLITE3_WIN32_WRITE_DEBUG);
    #if defined(SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_WRITE_DEBUG)
        SQLITE3_PROXY_HANDLE_SQLITE3_WIN32_WRITE_DEBUG();
    #endif
    orgFnPtr(zBuf, nBuf);
}


