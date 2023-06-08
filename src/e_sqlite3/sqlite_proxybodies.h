PROXY_EXPORT void* sqlite3_aggregate_context(sqlite3_context* pCtx, int nBytes)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_aggregate_context));
    sqlite3_aggregate_context_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_aggregate_context_fnptr_t>(ORG_SQLITE3_FN_IDX_AGGREGATE_CONTEXT);
    return pfn(pCtx, nBytes);
}

PROXY_EXPORT int sqlite3_aggregate_count(sqlite3_context* pCtx)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_aggregate_count));
    sqlite3_aggregate_count_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_aggregate_count_fnptr_t>(ORG_SQLITE3_FN_IDX_AGGREGATE_COUNT);
    return pfn(pCtx);
}

PROXY_EXPORT int sqlite3_auto_extension(void (*pfn)(void))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_auto_extension));
    sqlite3_auto_extension_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_auto_extension_fnptr_t>(ORG_SQLITE3_FN_IDX_AUTO_EXTENSION);
    return pfn(pfn);
}

PROXY_EXPORT int sqlite3_autovacuum_pages(sqlite3* pDb, unsigned int (*pfn)(void*, const char*, unsigned, unsigned, unsigned), void* pv, void (*pfn2)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_autovacuum_pages));
    sqlite3_autovacuum_pages_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_autovacuum_pages_fnptr_t>(ORG_SQLITE3_FN_IDX_AUTOVACUUM_PAGES);
    return pfn(pDb, pfn, pv, pfn2);
}

PROXY_EXPORT int sqlite3_backup_finish(sqlite3_backup* pBckp)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_backup_finish));
    sqlite3_backup_finish_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_backup_finish_fnptr_t>(ORG_SQLITE3_FN_IDX_BACKUP_FINISH);
    return pfn(pBckp);
}

PROXY_EXPORT sqlite3_backup* sqlite3_backup_init(sqlite3* pDb, const char* pcStr, sqlite3* pDb2, const char* pcStr2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_backup_init));
    sqlite3_backup_init_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_backup_init_fnptr_t>(ORG_SQLITE3_FN_IDX_BACKUP_INIT);
    return pfn(pDb, pcStr, pDb2, pcStr2);
}

PROXY_EXPORT int sqlite3_backup_pagecount(sqlite3_backup* pBckp)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_backup_pagecount));
    sqlite3_backup_pagecount_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_backup_pagecount_fnptr_t>(ORG_SQLITE3_FN_IDX_BACKUP_PAGECOUNT);
    return pfn(pBckp);
}

PROXY_EXPORT int sqlite3_backup_remaining(sqlite3_backup* pBckp)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_backup_remaining));
    sqlite3_backup_remaining_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_backup_remaining_fnptr_t>(ORG_SQLITE3_FN_IDX_BACKUP_REMAINING);
    return pfn(pBckp);
}

PROXY_EXPORT int sqlite3_backup_step(sqlite3_backup* pBckp, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_backup_step));
    sqlite3_backup_step_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_backup_step_fnptr_t>(ORG_SQLITE3_FN_IDX_BACKUP_STEP);
    return pfn(pBckp, i);
}

PROXY_EXPORT int sqlite3_bind_blob(sqlite3_stmt* pStmt, int i, const void* pcv, int n, void (*pfn)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_bind_blob));
    sqlite3_bind_blob_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_bind_blob_fnptr_t>(ORG_SQLITE3_FN_IDX_BIND_BLOB);
    return pfn(pStmt, i, pcv, n, pfn);
}

PROXY_EXPORT int sqlite3_bind_blob64(sqlite3_stmt* pStmt, int i, const void* pcv, sqlite3_uint64 u64, void (*pfn)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_bind_blob64));
    sqlite3_bind_blob64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_bind_blob64_fnptr_t>(ORG_SQLITE3_FN_IDX_BIND_BLOB64);
    return pfn(pStmt, i, pcv, u64, pfn);
}

PROXY_EXPORT int sqlite3_bind_double(sqlite3_stmt* pStmt, int i, double dbl)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_bind_double));
    sqlite3_bind_double_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_bind_double_fnptr_t>(ORG_SQLITE3_FN_IDX_BIND_DOUBLE);
    return pfn(pStmt, i, dbl);
}

PROXY_EXPORT int sqlite3_bind_int(sqlite3_stmt* pStmt, int i, int i2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_bind_int));
    sqlite3_bind_int_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_bind_int_fnptr_t>(ORG_SQLITE3_FN_IDX_BIND_INT);
    return pfn(pStmt, i, i2);
}

PROXY_EXPORT int sqlite3_bind_int64(sqlite3_stmt* pStmt, int i, sqlite_int64 i64)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_bind_int64));
    sqlite3_bind_int64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_bind_int64_fnptr_t>(ORG_SQLITE3_FN_IDX_BIND_INT64);
    return pfn(pStmt, i, i64);
}

PROXY_EXPORT int sqlite3_bind_null(sqlite3_stmt* pStmt, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_bind_null));
    sqlite3_bind_null_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_bind_null_fnptr_t>(ORG_SQLITE3_FN_IDX_BIND_NULL);
    return pfn(pStmt, i);
}

PROXY_EXPORT int sqlite3_bind_parameter_count(sqlite3_stmt* pStmt)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_bind_parameter_count));
    sqlite3_bind_parameter_count_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_bind_parameter_count_fnptr_t>(ORG_SQLITE3_FN_IDX_BIND_PARAMETER_COUNT);
    return pfn(pStmt);
}

PROXY_EXPORT int sqlite3_bind_parameter_index(sqlite3_stmt* pStmt, const char* zName)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_bind_parameter_index));
    sqlite3_bind_parameter_index_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_bind_parameter_index_fnptr_t>(ORG_SQLITE3_FN_IDX_BIND_PARAMETER_INDEX);
    return pfn(pStmt, zName);
}

PROXY_EXPORT const char* sqlite3_bind_parameter_name(sqlite3_stmt* pStmt, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_bind_parameter_name));
    sqlite3_bind_parameter_name_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_bind_parameter_name_fnptr_t>(ORG_SQLITE3_FN_IDX_BIND_PARAMETER_NAME);
    return pfn(pStmt, i);
}

PROXY_EXPORT int sqlite3_bind_pointer(sqlite3_stmt* pStmt, int i, void* pv, const char* pcStr, void (*pfn)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_bind_pointer));
    sqlite3_bind_pointer_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_bind_pointer_fnptr_t>(ORG_SQLITE3_FN_IDX_BIND_POINTER);
    return pfn(pStmt, i, pv, pcStr, pfn);
}

PROXY_EXPORT int sqlite3_bind_text(sqlite3_stmt* pStmt, int i, const char* pcStr, int n, void (*pfn)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_bind_text));
    sqlite3_bind_text_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_bind_text_fnptr_t>(ORG_SQLITE3_FN_IDX_BIND_TEXT);
    return pfn(pStmt, i, pcStr, n, pfn);
}

PROXY_EXPORT int sqlite3_bind_text16(sqlite3_stmt* pStmt, int i, const void* pcv, int i2, void (*pfn)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_bind_text16));
    sqlite3_bind_text16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_bind_text16_fnptr_t>(ORG_SQLITE3_FN_IDX_BIND_TEXT16);
    return pfn(pStmt, i, pcv, i2, pfn);
}

PROXY_EXPORT int sqlite3_bind_text64(sqlite3_stmt* pStmt, int i, const char* pcStr, sqlite3_uint64 u64, void (*pfn)(void*), unsigned char)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_bind_text64));
    sqlite3_bind_text64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_bind_text64_fnptr_t>(ORG_SQLITE3_FN_IDX_BIND_TEXT64);
    return pfn(pStmt, i, pcStr, u64, pfn, char);
}

PROXY_EXPORT int sqlite3_bind_value(sqlite3_stmt* pStmt, int i, const sqlite3_value* pcVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_bind_value));
    sqlite3_bind_value_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_bind_value_fnptr_t>(ORG_SQLITE3_FN_IDX_BIND_VALUE);
    return pfn(pStmt, i, pcVal);
}

PROXY_EXPORT int sqlite3_bind_zeroblob(sqlite3_stmt* pStmt, int i, int i2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_bind_zeroblob));
    sqlite3_bind_zeroblob_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_bind_zeroblob_fnptr_t>(ORG_SQLITE3_FN_IDX_BIND_ZEROBLOB);
    return pfn(pStmt, i, i2);
}

PROXY_EXPORT int sqlite3_bind_zeroblob64(sqlite3_stmt* pStmt, int i, sqlite3_uint64 u64)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_bind_zeroblob64));
    sqlite3_bind_zeroblob64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_bind_zeroblob64_fnptr_t>(ORG_SQLITE3_FN_IDX_BIND_ZEROBLOB64);
    return pfn(pStmt, i, u64);
}

PROXY_EXPORT int sqlite3_blob_bytes(sqlite3_blob* pBlob)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_blob_bytes));
    sqlite3_blob_bytes_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_blob_bytes_fnptr_t>(ORG_SQLITE3_FN_IDX_BLOB_BYTES);
    return pfn(pBlob);
}

PROXY_EXPORT int sqlite3_blob_close(sqlite3_blob* pBlob)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_blob_close));
    sqlite3_blob_close_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_blob_close_fnptr_t>(ORG_SQLITE3_FN_IDX_BLOB_CLOSE);
    return pfn(pBlob);
}

PROXY_EXPORT int sqlite3_blob_open(sqlite3* pDb, const char* pcStr, const char* pcStr2, const char* pcStr3, sqlite3_int64 i64, int i, sqlite3_blob** ppBlob)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_blob_open));
    sqlite3_blob_open_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_blob_open_fnptr_t>(ORG_SQLITE3_FN_IDX_BLOB_OPEN);
    return pfn(pDb, pcStr, pcStr2, pcStr3, i64, i, ppBlob);
}

PROXY_EXPORT int sqlite3_blob_read(sqlite3_blob* pBlob, void* pv, int i, int i2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_blob_read));
    sqlite3_blob_read_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_blob_read_fnptr_t>(ORG_SQLITE3_FN_IDX_BLOB_READ);
    return pfn(pBlob, pv, i, i2);
}

PROXY_EXPORT int sqlite3_blob_reopen(sqlite3_blob* pBlob, sqlite3_int64 i64)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_blob_reopen));
    sqlite3_blob_reopen_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_blob_reopen_fnptr_t>(ORG_SQLITE3_FN_IDX_BLOB_REOPEN);
    return pfn(pBlob, i64);
}

PROXY_EXPORT int sqlite3_blob_write(sqlite3_blob* pBlob, const void* pcv, int i, int i2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_blob_write));
    sqlite3_blob_write_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_blob_write_fnptr_t>(ORG_SQLITE3_FN_IDX_BLOB_WRITE);
    return pfn(pBlob, pcv, i, i2);
}

PROXY_EXPORT int sqlite3_busy_handler(sqlite3* pDb, int (*pfn)(void*, int), void* pv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_busy_handler));
    sqlite3_busy_handler_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_busy_handler_fnptr_t>(ORG_SQLITE3_FN_IDX_BUSY_HANDLER);
    return pfn(pDb, pfn, pv);
}

PROXY_EXPORT int sqlite3_busy_timeout(sqlite3* pDb, int ms)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_busy_timeout));
    sqlite3_busy_timeout_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_busy_timeout_fnptr_t>(ORG_SQLITE3_FN_IDX_BUSY_TIMEOUT);
    return pfn(pDb, ms);
}

PROXY_EXPORT int sqlite3_cancel_auto_extension(void (*pfn)(void))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_cancel_auto_extension));
    sqlite3_cancel_auto_extension_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_cancel_auto_extension_fnptr_t>(ORG_SQLITE3_FN_IDX_CANCEL_AUTO_EXTENSION);
    return pfn(pfn);
}

PROXY_EXPORT int sqlite3_changes(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_changes));
    sqlite3_changes_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_changes_fnptr_t>(ORG_SQLITE3_FN_IDX_CHANGES);
    return pfn(pDb);
}

PROXY_EXPORT sqlite3_int64 sqlite3_changes64(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_changes64));
    sqlite3_changes64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_changes64_fnptr_t>(ORG_SQLITE3_FN_IDX_CHANGES64);
    return pfn(pDb);
}

PROXY_EXPORT int sqlite3_clear_bindings(sqlite3_stmt* pStmt)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_clear_bindings));
    sqlite3_clear_bindings_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_clear_bindings_fnptr_t>(ORG_SQLITE3_FN_IDX_CLEAR_BINDINGS);
    return pfn(pStmt);
}

PROXY_EXPORT int sqlite3_close(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_close));
    sqlite3_close_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_close_fnptr_t>(ORG_SQLITE3_FN_IDX_CLOSE);
    return pfn(pDb);
}

PROXY_EXPORT int sqlite3_close_v2(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_close_v2));
    sqlite3_close_v2_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_close_v2_fnptr_t>(ORG_SQLITE3_FN_IDX_CLOSE_V2);
    return pfn(pDb);
}

PROXY_EXPORT int sqlite3_collation_needed(sqlite3* pDb, void* pv, void (*pfn)(void*, sqlite3*, int, const char*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_collation_needed));
    sqlite3_collation_needed_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_collation_needed_fnptr_t>(ORG_SQLITE3_FN_IDX_COLLATION_NEEDED);
    return pfn(pDb, pv, pfn);
}

PROXY_EXPORT int sqlite3_collation_needed16(sqlite3* pDb, void* pv, void (*pfn)(void*, sqlite3*, int, const void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_collation_needed16));
    sqlite3_collation_needed16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_collation_needed16_fnptr_t>(ORG_SQLITE3_FN_IDX_COLLATION_NEEDED16);
    return pfn(pDb, pv, pfn);
}

PROXY_EXPORT const void* sqlite3_column_blob(sqlite3_stmt* pStmt, int iCol)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_blob));
    sqlite3_column_blob_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_blob_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_BLOB);
    return pfn(pStmt, iCol);
}

PROXY_EXPORT int sqlite3_column_bytes(sqlite3_stmt* pStmt, int iCol)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_bytes));
    sqlite3_column_bytes_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_bytes_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_BYTES);
    return pfn(pStmt, iCol);
}

PROXY_EXPORT int sqlite3_column_bytes16(sqlite3_stmt* pStmt, int iCol)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_bytes16));
    sqlite3_column_bytes16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_bytes16_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_BYTES16);
    return pfn(pStmt, iCol);
}

PROXY_EXPORT int sqlite3_column_count(sqlite3_stmt* pStmt)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_count));
    sqlite3_column_count_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_count_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_COUNT);
    return pfn(pStmt);
}

PROXY_EXPORT const char* sqlite3_column_database_name(sqlite3_stmt* pStmt, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_database_name));
    sqlite3_column_database_name_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_database_name_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_DATABASE_NAME);
    return pfn(pStmt, i);
}

PROXY_EXPORT const void* sqlite3_column_database_name16(sqlite3_stmt* pStmt, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_database_name16));
    sqlite3_column_database_name16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_database_name16_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_DATABASE_NAME16);
    return pfn(pStmt, i);
}

PROXY_EXPORT const char* sqlite3_column_decltype(sqlite3_stmt* pStmt, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_decltype));
    sqlite3_column_decltype_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_decltype_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_DECLTYPE);
    return pfn(pStmt, i);
}

PROXY_EXPORT const void* sqlite3_column_decltype16(sqlite3_stmt* pStmt, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_decltype16));
    sqlite3_column_decltype16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_decltype16_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_DECLTYPE16);
    return pfn(pStmt, i);
}

PROXY_EXPORT double sqlite3_column_double(sqlite3_stmt* pStmt, int iCol)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_double));
    sqlite3_column_double_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_double_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_DOUBLE);
    return pfn(pStmt, iCol);
}

PROXY_EXPORT int sqlite3_column_int(sqlite3_stmt* pStmt, int iCol)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_int));
    sqlite3_column_int_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_int_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_INT);
    return pfn(pStmt, iCol);
}

PROXY_EXPORT sqlite_int64 sqlite3_column_int64(sqlite3_stmt* pStmt, int iCol)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_int64));
    sqlite3_column_int64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_int64_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_INT64);
    return pfn(pStmt, iCol);
}

PROXY_EXPORT const char* sqlite3_column_name(sqlite3_stmt* pStmt, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_name));
    sqlite3_column_name_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_name_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_NAME);
    return pfn(pStmt, i);
}

PROXY_EXPORT const void* sqlite3_column_name16(sqlite3_stmt* pStmt, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_name16));
    sqlite3_column_name16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_name16_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_NAME16);
    return pfn(pStmt, i);
}

PROXY_EXPORT const char* sqlite3_column_origin_name(sqlite3_stmt* pStmt, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_origin_name));
    sqlite3_column_origin_name_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_origin_name_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_ORIGIN_NAME);
    return pfn(pStmt, i);
}

PROXY_EXPORT const void* sqlite3_column_origin_name16(sqlite3_stmt* pStmt, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_origin_name16));
    sqlite3_column_origin_name16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_origin_name16_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_ORIGIN_NAME16);
    return pfn(pStmt, i);
}

PROXY_EXPORT const char* sqlite3_column_table_name(sqlite3_stmt* pStmt, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_table_name));
    sqlite3_column_table_name_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_table_name_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_TABLE_NAME);
    return pfn(pStmt, i);
}

PROXY_EXPORT const void* sqlite3_column_table_name16(sqlite3_stmt* pStmt, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_table_name16));
    sqlite3_column_table_name16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_table_name16_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_TABLE_NAME16);
    return pfn(pStmt, i);
}

PROXY_EXPORT const unsigned char* sqlite3_column_text(sqlite3_stmt* pStmt, int iCol)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_text));
    sqlite3_column_text_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_text_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_TEXT);
    return pfn(pStmt, iCol);
}

PROXY_EXPORT const void* sqlite3_column_text16(sqlite3_stmt* pStmt, int iCol)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_text16));
    sqlite3_column_text16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_text16_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_TEXT16);
    return pfn(pStmt, iCol);
}

PROXY_EXPORT int sqlite3_column_type(sqlite3_stmt* pStmt, int iCol)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_type));
    sqlite3_column_type_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_type_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_TYPE);
    return pfn(pStmt, iCol);
}

PROXY_EXPORT sqlite3_value* sqlite3_column_value(sqlite3_stmt* pStmt, int iCol)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_column_value));
    sqlite3_column_value_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_column_value_fnptr_t>(ORG_SQLITE3_FN_IDX_COLUMN_VALUE);
    return pfn(pStmt, iCol);
}

PROXY_EXPORT void* sqlite3_commit_hook(sqlite3* pDb, int (*pfn)(void*), void* pv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_commit_hook));
    sqlite3_commit_hook_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_commit_hook_fnptr_t>(ORG_SQLITE3_FN_IDX_COMMIT_HOOK);
    return pfn(pDb, pfn, pv);
}

PROXY_EXPORT const char* sqlite3_compileoption_get(int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_compileoption_get));
    sqlite3_compileoption_get_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_compileoption_get_fnptr_t>(ORG_SQLITE3_FN_IDX_COMPILEOPTION_GET);
    return pfn(i);
}

PROXY_EXPORT int sqlite3_compileoption_used(const char* pcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_compileoption_used));
    sqlite3_compileoption_used_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_compileoption_used_fnptr_t>(ORG_SQLITE3_FN_IDX_COMPILEOPTION_USED);
    return pfn(pcStr);
}

PROXY_EXPORT int sqlite3_complete(const char* sql)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_complete));
    sqlite3_complete_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_complete_fnptr_t>(ORG_SQLITE3_FN_IDX_COMPLETE);
    return pfn(sql);
}

PROXY_EXPORT int sqlite3_complete16(const void* sql)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_complete16));
    sqlite3_complete16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_complete16_fnptr_t>(ORG_SQLITE3_FN_IDX_COMPLETE16);
    return pfn(sql);
}

PROXY_EXPORT int sqlite3_config(int i, ...)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_config));
    PROXY_SQLITE3_CONFIG_IMPL();
}

PROXY_EXPORT sqlite3* sqlite3_context_db_handle(sqlite3_context* pCtx)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_context_db_handle));
    sqlite3_context_db_handle_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_context_db_handle_fnptr_t>(ORG_SQLITE3_FN_IDX_CONTEXT_DB_HANDLE);
    return pfn(pCtx);
}

PROXY_EXPORT int sqlite3_create_collation(sqlite3* pDb, const char* pcStr, int i, void* pv, int (*pfn)(void*, int, const void*, int, const void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_create_collation));
    sqlite3_create_collation_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_create_collation_fnptr_t>(ORG_SQLITE3_FN_IDX_CREATE_COLLATION);
    return pfn(pDb, pcStr, i, pv, pfn);
}

PROXY_EXPORT int sqlite3_create_collation_v2(sqlite3* pDb, const char* pcStr, int i, void* pv, int (*pfn)(void*, int, const void*, int, const void*), void (*pfn2)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_create_collation_v2));
    sqlite3_create_collation_v2_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_create_collation_v2_fnptr_t>(ORG_SQLITE3_FN_IDX_CREATE_COLLATION_V2);
    return pfn(pDb, pcStr, i, pv, pfn, pfn2);
}

PROXY_EXPORT int sqlite3_create_collation16(sqlite3* pDb, const void* pcv, int i, void* pv, int (*pfn)(void*, int, const void*, int, const void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_create_collation16));
    sqlite3_create_collation16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_create_collation16_fnptr_t>(ORG_SQLITE3_FN_IDX_CREATE_COLLATION16);
    return pfn(pDb, pcv, i, pv, pfn);
}

PROXY_EXPORT const char* sqlite3_create_filename(const char* pcStr, const char* pcStr2, const char* pcStr3, int i, const char** ppcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_create_filename));
    sqlite3_create_filename_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_create_filename_fnptr_t>(ORG_SQLITE3_FN_IDX_CREATE_FILENAME);
    return pfn(pcStr, pcStr2, pcStr3, i, ppcStr);
}

PROXY_EXPORT int sqlite3_create_function(sqlite3* pDb, const char* pcStr, int i, int i2, void* pv, void (*xFunc)(sqlite3_context*, int, sqlite3_value**), void (*xStep)(sqlite3_context*, int, sqlite3_value**), void (*xFinal)(sqlite3_context*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_create_function));
    sqlite3_create_function_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_create_function_fnptr_t>(ORG_SQLITE3_FN_IDX_CREATE_FUNCTION);
    return pfn(pDb, pcStr, i, i2, pv, xFunc, xStep, xFinal);
}

PROXY_EXPORT int sqlite3_create_function_v2(sqlite3* pDb, const char* pcStr, int i, int i2, void* pv, void (*xFunc)(sqlite3_context*, int, sqlite3_value**), void (*xStep)(sqlite3_context*, int, sqlite3_value**), void (*xFinal)(sqlite3_context*), void (*xDestroy)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_create_function_v2));
    sqlite3_create_function_v2_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_create_function_v2_fnptr_t>(ORG_SQLITE3_FN_IDX_CREATE_FUNCTION_V2);
    return pfn(pDb, pcStr, i, i2, pv, xFunc, xStep, xFinal, xDestroy);
}

PROXY_EXPORT int sqlite3_create_function16(sqlite3* pDb, const void* pcv, int i, int i2, void* pv, void (*xFunc)(sqlite3_context*, int, sqlite3_value**), void (*xStep)(sqlite3_context*, int, sqlite3_value**), void (*xFinal)(sqlite3_context*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_create_function16));
    sqlite3_create_function16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_create_function16_fnptr_t>(ORG_SQLITE3_FN_IDX_CREATE_FUNCTION16);
    return pfn(pDb, pcv, i, i2, pv, xFunc, xStep, xFinal);
}

PROXY_EXPORT int sqlite3_create_module(sqlite3* pDb, const char* pcStr, const sqlite3_module* pcMod, void* pv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_create_module));
    sqlite3_create_module_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_create_module_fnptr_t>(ORG_SQLITE3_FN_IDX_CREATE_MODULE);
    return pfn(pDb, pcStr, pcMod, pv);
}

PROXY_EXPORT int sqlite3_create_module_v2(sqlite3* pDb, const char* pcStr, const sqlite3_module* pcMod, void* pv, void (*xDestroy)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_create_module_v2));
    sqlite3_create_module_v2_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_create_module_v2_fnptr_t>(ORG_SQLITE3_FN_IDX_CREATE_MODULE_V2);
    return pfn(pDb, pcStr, pcMod, pv, xDestroy);
}

PROXY_EXPORT int sqlite3_create_window_function(sqlite3* pDb, const char* pcStr, int i, int i2, void* pv, void (*xStep)(sqlite3_context*, int, sqlite3_value**), void (*xFinal)(sqlite3_context*), void (*xValue)(sqlite3_context*), void (*xInv)(sqlite3_context*, int, sqlite3_value**), void (*xDestroy)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_create_window_function));
    sqlite3_create_window_function_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_create_window_function_fnptr_t>(ORG_SQLITE3_FN_IDX_CREATE_WINDOW_FUNCTION);
    return pfn(pDb, pcStr, i, i2, pv, xStep, xFinal, xValue, xInv, xDestroy);
}

PROXY_EXPORT int sqlite3_data_count(sqlite3_stmt* pStmt)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_data_count));
    sqlite3_data_count_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_data_count_fnptr_t>(ORG_SQLITE3_FN_IDX_DATA_COUNT);
    return pfn(pStmt);
}

PROXY_EXPORT PROXY_SQLITE3_DATA_DIRECTORY_DATA(sqlite3_data_directory);

PROXY_EXPORT sqlite3_file* sqlite3_database_file_object(const char* pcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_database_file_object));
    sqlite3_database_file_object_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_database_file_object_fnptr_t>(ORG_SQLITE3_FN_IDX_DATABASE_FILE_OBJECT);
    return pfn(pcStr);
}

PROXY_EXPORT int sqlite3_db_cacheflush(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_db_cacheflush));
    sqlite3_db_cacheflush_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_db_cacheflush_fnptr_t>(ORG_SQLITE3_FN_IDX_DB_CACHEFLUSH);
    return pfn(pDb);
}

PROXY_EXPORT int sqlite3_db_config(sqlite3* pDb, int i, ...)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_db_config));
    PROXY_SQLITE3_DB_CONFIG_IMPL();
}

PROXY_EXPORT const char* sqlite3_db_filename(sqlite3* pDb, const char* pcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_db_filename));
    sqlite3_db_filename_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_db_filename_fnptr_t>(ORG_SQLITE3_FN_IDX_DB_FILENAME);
    return pfn(pDb, pcStr);
}

PROXY_EXPORT sqlite3* sqlite3_db_handle(sqlite3_stmt* pStmt)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_db_handle));
    sqlite3_db_handle_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_db_handle_fnptr_t>(ORG_SQLITE3_FN_IDX_DB_HANDLE);
    return pfn(pStmt);
}

PROXY_EXPORT sqlite3_mutex* sqlite3_db_mutex(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_db_mutex));
    sqlite3_db_mutex_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_db_mutex_fnptr_t>(ORG_SQLITE3_FN_IDX_DB_MUTEX);
    return pfn(pDb);
}

PROXY_EXPORT int sqlite3_db_readonly(sqlite3* pDb, const char* pcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_db_readonly));
    sqlite3_db_readonly_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_db_readonly_fnptr_t>(ORG_SQLITE3_FN_IDX_DB_READONLY);
    return pfn(pDb, pcStr);
}

PROXY_EXPORT int sqlite3_db_release_memory(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_db_release_memory));
    sqlite3_db_release_memory_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_db_release_memory_fnptr_t>(ORG_SQLITE3_FN_IDX_DB_RELEASE_MEMORY);
    return pfn(pDb);
}

PROXY_EXPORT int sqlite3_db_status(sqlite3* pDb, int i, int* pInt, int* pInt2, int i2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_db_status));
    sqlite3_db_status_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_db_status_fnptr_t>(ORG_SQLITE3_FN_IDX_DB_STATUS);
    return pfn(pDb, i, pInt, pInt2, i2);
}

PROXY_EXPORT int sqlite3_declare_vtab(sqlite3* pDb, const char* pcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_declare_vtab));
    sqlite3_declare_vtab_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_declare_vtab_fnptr_t>(ORG_SQLITE3_FN_IDX_DECLARE_VTAB);
    return pfn(pDb, pcStr);
}

PROXY_EXPORT int sqlite3_deserialize(sqlite3* pDb, const char* pcStr, unsigned char* pBytes, sqlite3_int64 i64, sqlite3_int64 i642, unsigned u)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_deserialize));
    sqlite3_deserialize_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_deserialize_fnptr_t>(ORG_SQLITE3_FN_IDX_DESERIALIZE);
    return pfn(pDb, pcStr, pBytes, i64, i642, u);
}

PROXY_EXPORT int sqlite3_drop_modules(sqlite3* pDb, const char** ppcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_drop_modules));
    sqlite3_drop_modules_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_drop_modules_fnptr_t>(ORG_SQLITE3_FN_IDX_DROP_MODULES);
    return pfn(pDb, ppcStr);
}

PROXY_EXPORT int sqlite3_enable_load_extension(sqlite3* db, int onoff)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_enable_load_extension));
    sqlite3_enable_load_extension_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_enable_load_extension_fnptr_t>(ORG_SQLITE3_FN_IDX_ENABLE_LOAD_EXTENSION);
    return pfn(db, onoff);
}

PROXY_EXPORT int sqlite3_enable_shared_cache(int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_enable_shared_cache));
    sqlite3_enable_shared_cache_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_enable_shared_cache_fnptr_t>(ORG_SQLITE3_FN_IDX_ENABLE_SHARED_CACHE);
    return pfn(i);
}

PROXY_EXPORT int sqlite3_errcode(sqlite3* db)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_errcode));
    sqlite3_errcode_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_errcode_fnptr_t>(ORG_SQLITE3_FN_IDX_ERRCODE);
    return pfn(db);
}

PROXY_EXPORT const char* sqlite3_errmsg(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_errmsg));
    sqlite3_errmsg_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_errmsg_fnptr_t>(ORG_SQLITE3_FN_IDX_ERRMSG);
    return pfn(pDb);
}

PROXY_EXPORT const void* sqlite3_errmsg16(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_errmsg16));
    sqlite3_errmsg16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_errmsg16_fnptr_t>(ORG_SQLITE3_FN_IDX_ERRMSG16);
    return pfn(pDb);
}

PROXY_EXPORT int sqlite3_error_offset(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_error_offset));
    sqlite3_error_offset_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_error_offset_fnptr_t>(ORG_SQLITE3_FN_IDX_ERROR_OFFSET);
    return pfn(pDb);
}

PROXY_EXPORT const char* sqlite3_errstr(int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_errstr));
    sqlite3_errstr_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_errstr_fnptr_t>(ORG_SQLITE3_FN_IDX_ERRSTR);
    return pfn(i);
}

PROXY_EXPORT int sqlite3_exec(sqlite3* pDb, const char* pcStr, sqlite3_callback cbk, void* pv, char** ppStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_exec));
    sqlite3_exec_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_exec_fnptr_t>(ORG_SQLITE3_FN_IDX_EXEC);
    return pfn(pDb, pcStr, cbk, pv, ppStr);
}

PROXY_EXPORT char* sqlite3_expanded_sql(sqlite3_stmt* pStmt)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_expanded_sql));
    sqlite3_expanded_sql_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_expanded_sql_fnptr_t>(ORG_SQLITE3_FN_IDX_EXPANDED_SQL);
    return pfn(pStmt);
}

PROXY_EXPORT int sqlite3_expired(sqlite3_stmt* pStmt)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_expired));
    sqlite3_expired_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_expired_fnptr_t>(ORG_SQLITE3_FN_IDX_EXPIRED);
    return pfn(pStmt);
}

PROXY_EXPORT int sqlite3_extended_errcode(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_extended_errcode));
    sqlite3_extended_errcode_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_extended_errcode_fnptr_t>(ORG_SQLITE3_FN_IDX_EXTENDED_ERRCODE);
    return pfn(pDb);
}

PROXY_EXPORT int sqlite3_extended_result_codes(sqlite3* pDb, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_extended_result_codes));
    sqlite3_extended_result_codes_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_extended_result_codes_fnptr_t>(ORG_SQLITE3_FN_IDX_EXTENDED_RESULT_CODES);
    return pfn(pDb, i);
}

PROXY_EXPORT int sqlite3_file_control(sqlite3* pDb, const char* pcStr, int i, void* pv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_file_control));
    sqlite3_file_control_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_file_control_fnptr_t>(ORG_SQLITE3_FN_IDX_FILE_CONTROL);
    return pfn(pDb, pcStr, i, pv);
}

PROXY_EXPORT const char* sqlite3_filename_database(const char* pcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_filename_database));
    sqlite3_filename_database_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_filename_database_fnptr_t>(ORG_SQLITE3_FN_IDX_FILENAME_DATABASE);
    return pfn(pcStr);
}

PROXY_EXPORT const char* sqlite3_filename_journal(const char* pcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_filename_journal));
    sqlite3_filename_journal_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_filename_journal_fnptr_t>(ORG_SQLITE3_FN_IDX_FILENAME_JOURNAL);
    return pfn(pcStr);
}

PROXY_EXPORT const char* sqlite3_filename_wal(const char* pcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_filename_wal));
    sqlite3_filename_wal_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_filename_wal_fnptr_t>(ORG_SQLITE3_FN_IDX_FILENAME_WAL);
    return pfn(pcStr);
}

PROXY_EXPORT int sqlite3_finalize(sqlite3_stmt* pStmt)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_finalize));
    sqlite3_finalize_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_finalize_fnptr_t>(ORG_SQLITE3_FN_IDX_FINALIZE);
    return pfn(pStmt);
}

PROXY_EXPORT void sqlite3_free(void* pv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_free));
    sqlite3_free_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_free_fnptr_t>(ORG_SQLITE3_FN_IDX_FREE);
    return pfn(pv);
}

PROXY_EXPORT void sqlite3_free_filename(const char* pcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_free_filename));
    sqlite3_free_filename_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_free_filename_fnptr_t>(ORG_SQLITE3_FN_IDX_FREE_FILENAME);
    return pfn(pcStr);
}

PROXY_EXPORT void sqlite3_free_table(char** result)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_free_table));
    sqlite3_free_table_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_free_table_fnptr_t>(ORG_SQLITE3_FN_IDX_FREE_TABLE);
    return pfn(result);
}

PROXY_EXPORT int sqlite3_get_autocommit(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_get_autocommit));
    sqlite3_get_autocommit_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_get_autocommit_fnptr_t>(ORG_SQLITE3_FN_IDX_GET_AUTOCOMMIT);
    return pfn(pDb);
}

PROXY_EXPORT void* sqlite3_get_auxdata(sqlite3_context* pCtx, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_get_auxdata));
    sqlite3_get_auxdata_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_get_auxdata_fnptr_t>(ORG_SQLITE3_FN_IDX_GET_AUXDATA);
    return pfn(pCtx, i);
}

PROXY_EXPORT int sqlite3_get_table(sqlite3* pDb, const char* pcStr, char*** pppStr, int* pInt, int* pInt2, char** ppStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_get_table));
    sqlite3_get_table_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_get_table_fnptr_t>(ORG_SQLITE3_FN_IDX_GET_TABLE);
    return pfn(pDb, pcStr, pppStr, pInt, pInt2, ppStr);
}

PROXY_EXPORT int sqlite3_global_recover(void)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_global_recover));
    sqlite3_global_recover_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_global_recover_fnptr_t>(ORG_SQLITE3_FN_IDX_GLOBAL_RECOVER);
    return pfn();
}

PROXY_EXPORT sqlite3_int64 sqlite3_hard_heap_limit64(sqlite3_int64 i64)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_hard_heap_limit64));
    sqlite3_hard_heap_limit64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_hard_heap_limit64_fnptr_t>(ORG_SQLITE3_FN_IDX_HARD_HEAP_LIMIT64);
    return pfn(i64);
}

PROXY_EXPORT int sqlite3_initialize(void)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_initialize));
    sqlite3_initialize_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_initialize_fnptr_t>(ORG_SQLITE3_FN_IDX_INITIALIZE);
    return pfn();
}

PROXY_EXPORT void sqlite3_interrupt(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_interrupt));
    sqlite3_interrupt_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_interrupt_fnptr_t>(ORG_SQLITE3_FN_IDX_INTERRUPT);
    return pfn(pDb);
}

PROXY_EXPORT int sqlite3_key(sqlite3* db, const void* pKey, int nKey)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_key));
    sqlite3_key_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_key_fnptr_t>(ORG_SQLITE3_FN_IDX_KEY);
    return pfn(db, pKey, nKey);
}

PROXY_EXPORT int sqlite3_key_v2(sqlite3* db, const char* zDbName, const void* pKey, int nKey)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_key_v2));
    sqlite3_key_v2_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_key_v2_fnptr_t>(ORG_SQLITE3_FN_IDX_KEY_V2);
    return pfn(db, zDbName, pKey, nKey);
}

PROXY_EXPORT int sqlite3_keyword_check(const char* pcStr, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_keyword_check));
    sqlite3_keyword_check_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_keyword_check_fnptr_t>(ORG_SQLITE3_FN_IDX_KEYWORD_CHECK);
    return pfn(pcStr, i);
}

PROXY_EXPORT int sqlite3_keyword_count(void)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_keyword_count));
    sqlite3_keyword_count_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_keyword_count_fnptr_t>(ORG_SQLITE3_FN_IDX_KEYWORD_COUNT);
    return pfn();
}

PROXY_EXPORT int sqlite3_keyword_name(int i, const char** ppcStr, int* pInt)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_keyword_name));
    sqlite3_keyword_name_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_keyword_name_fnptr_t>(ORG_SQLITE3_FN_IDX_KEYWORD_NAME);
    return pfn(i, ppcStr, pInt);
}

PROXY_EXPORT sqlite_int64 sqlite3_last_insert_rowid(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_last_insert_rowid));
    sqlite3_last_insert_rowid_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_last_insert_rowid_fnptr_t>(ORG_SQLITE3_FN_IDX_LAST_INSERT_ROWID);
    return pfn(pDb);
}

PROXY_EXPORT const char* sqlite3_libversion(void)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_libversion));
    sqlite3_libversion_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_libversion_fnptr_t>(ORG_SQLITE3_FN_IDX_LIBVERSION);
    return pfn();
}

PROXY_EXPORT int sqlite3_libversion_number(void)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_libversion_number));
    sqlite3_libversion_number_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_libversion_number_fnptr_t>(ORG_SQLITE3_FN_IDX_LIBVERSION_NUMBER);
    return pfn();
}

PROXY_EXPORT int sqlite3_limit(sqlite3* pDb, int i, int i2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_limit));
    sqlite3_limit_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_limit_fnptr_t>(ORG_SQLITE3_FN_IDX_LIMIT);
    return pfn(pDb, i, i2);
}

PROXY_EXPORT int sqlite3_load_extension(sqlite3* pDb, const char* pcStr, const char* pcStr2, char** ppStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_load_extension));
    sqlite3_load_extension_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_load_extension_fnptr_t>(ORG_SQLITE3_FN_IDX_LOAD_EXTENSION);
    return pfn(pDb, pcStr, pcStr2, ppStr);
}

PROXY_EXPORT void sqlite3_log(int i, const char* pcStr, ...)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_log));
    PROXY_SQLITE3_LOG_IMPL();
}

PROXY_EXPORT void* sqlite3_malloc(int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_malloc));
    sqlite3_malloc_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_malloc_fnptr_t>(ORG_SQLITE3_FN_IDX_MALLOC);
    return pfn(i);
}

PROXY_EXPORT void* sqlite3_malloc64(sqlite3_uint64 u64)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_malloc64));
    sqlite3_malloc64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_malloc64_fnptr_t>(ORG_SQLITE3_FN_IDX_MALLOC64);
    return pfn(u64);
}

PROXY_EXPORT int sqlite3_memory_alarm(void (*pfn)(void*, sqlite3_int64, int), void* pv, sqlite3_int64 i64)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_memory_alarm));
    sqlite3_memory_alarm_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_memory_alarm_fnptr_t>(ORG_SQLITE3_FN_IDX_MEMORY_ALARM);
    return pfn(pfn, pv, i64);
}

PROXY_EXPORT sqlite3_int64 sqlite3_memory_highwater(int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_memory_highwater));
    sqlite3_memory_highwater_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_memory_highwater_fnptr_t>(ORG_SQLITE3_FN_IDX_MEMORY_HIGHWATER);
    return pfn(i);
}

PROXY_EXPORT sqlite3_int64 sqlite3_memory_used(void)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_memory_used));
    sqlite3_memory_used_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_memory_used_fnptr_t>(ORG_SQLITE3_FN_IDX_MEMORY_USED);
    return pfn();
}

PROXY_EXPORT char* sqlite3_mprintf(const char* pcStr, ...)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_mprintf));
    PROXY_SQLITE3_MPRINTF_IMPL();
}

PROXY_EXPORT sqlite3_uint64 sqlite3_msize(void* pv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_msize));
    sqlite3_msize_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_msize_fnptr_t>(ORG_SQLITE3_FN_IDX_MSIZE);
    return pfn(pv);
}

PROXY_EXPORT sqlite3_mutex* sqlite3_mutex_alloc(int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_mutex_alloc));
    sqlite3_mutex_alloc_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_mutex_alloc_fnptr_t>(ORG_SQLITE3_FN_IDX_MUTEX_ALLOC);
    return pfn(i);
}

PROXY_EXPORT void sqlite3_mutex_enter(sqlite3_mutex* pMutex)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_mutex_enter));
    sqlite3_mutex_enter_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_mutex_enter_fnptr_t>(ORG_SQLITE3_FN_IDX_MUTEX_ENTER);
    return pfn(pMutex);
}

PROXY_EXPORT void sqlite3_mutex_free(sqlite3_mutex* pMutex)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_mutex_free));
    sqlite3_mutex_free_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_mutex_free_fnptr_t>(ORG_SQLITE3_FN_IDX_MUTEX_FREE);
    return pfn(pMutex);
}

PROXY_EXPORT void sqlite3_mutex_leave(sqlite3_mutex* pMutex)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_mutex_leave));
    sqlite3_mutex_leave_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_mutex_leave_fnptr_t>(ORG_SQLITE3_FN_IDX_MUTEX_LEAVE);
    return pfn(pMutex);
}

PROXY_EXPORT int sqlite3_mutex_try(sqlite3_mutex* pMutex)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_mutex_try));
    sqlite3_mutex_try_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_mutex_try_fnptr_t>(ORG_SQLITE3_FN_IDX_MUTEX_TRY);
    return pfn(pMutex);
}

PROXY_EXPORT sqlite3_stmt* sqlite3_next_stmt(sqlite3* pDb, sqlite3_stmt* pStmt)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_next_stmt));
    sqlite3_next_stmt_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_next_stmt_fnptr_t>(ORG_SQLITE3_FN_IDX_NEXT_STMT);
    return pfn(pDb, pStmt);
}

PROXY_EXPORT int sqlite3_open(const char* pcStr, sqlite3** ppDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_open));
    sqlite3_open_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_open_fnptr_t>(ORG_SQLITE3_FN_IDX_OPEN);
    return pfn(pcStr, ppDb);
}

PROXY_EXPORT int sqlite3_open_v2(const char* pcStr, sqlite3** ppDb, int i, const char* pcStr2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_open_v2));
    sqlite3_open_v2_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_open_v2_fnptr_t>(ORG_SQLITE3_FN_IDX_OPEN_V2);
    return pfn(pcStr, ppDb, i, pcStr2);
}

PROXY_EXPORT int sqlite3_open16(const void* pcv, sqlite3** ppDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_open16));
    sqlite3_open16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_open16_fnptr_t>(ORG_SQLITE3_FN_IDX_OPEN16);
    return pfn(pcv, ppDb);
}

PROXY_EXPORT int sqlite3_os_end(void)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_os_end));
    sqlite3_os_end_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_os_end_fnptr_t>(ORG_SQLITE3_FN_IDX_OS_END);
    return pfn();
}

PROXY_EXPORT int sqlite3_os_init(void)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_os_init));
    sqlite3_os_init_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_os_init_fnptr_t>(ORG_SQLITE3_FN_IDX_OS_INIT);
    return pfn();
}

PROXY_EXPORT int sqlite3_overload_function(sqlite3* pDb, const char* zFuncName, int nArg)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_overload_function));
    sqlite3_overload_function_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_overload_function_fnptr_t>(ORG_SQLITE3_FN_IDX_OVERLOAD_FUNCTION);
    return pfn(pDb, zFuncName, nArg);
}

PROXY_EXPORT int sqlite3_prepare(sqlite3* pDb, const char* pcStr, int i, sqlite3_stmt** ppStmt, const char** ppcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_prepare));
    sqlite3_prepare_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_prepare_fnptr_t>(ORG_SQLITE3_FN_IDX_PREPARE);
    return pfn(pDb, pcStr, i, ppStmt, ppcStr);
}

PROXY_EXPORT int sqlite3_prepare_v2(sqlite3* pDb, const char* pcStr, int i, sqlite3_stmt** ppStmt, const char** ppcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_prepare_v2));
    sqlite3_prepare_v2_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_prepare_v2_fnptr_t>(ORG_SQLITE3_FN_IDX_PREPARE_V2);
    return pfn(pDb, pcStr, i, ppStmt, ppcStr);
}

PROXY_EXPORT int sqlite3_prepare_v3(sqlite3* pDb, const char* pcStr, int i, unsigned int, sqlite3_stmt** ppStmt, const char** ppcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_prepare_v3));
    sqlite3_prepare_v3_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_prepare_v3_fnptr_t>(ORG_SQLITE3_FN_IDX_PREPARE_V3);
    return pfn(pDb, pcStr, i, int, ppStmt, ppcStr);
}

PROXY_EXPORT int sqlite3_prepare16(sqlite3* pDb, const void* pcv, int i, sqlite3_stmt** ppStmt, const void** ppcv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_prepare16));
    sqlite3_prepare16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_prepare16_fnptr_t>(ORG_SQLITE3_FN_IDX_PREPARE16);
    return pfn(pDb, pcv, i, ppStmt, ppcv);
}

PROXY_EXPORT int sqlite3_prepare16_v2(sqlite3* pDb, const void* pcv, int i, sqlite3_stmt** ppStmt, const void** ppcv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_prepare16_v2));
    sqlite3_prepare16_v2_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_prepare16_v2_fnptr_t>(ORG_SQLITE3_FN_IDX_PREPARE16_V2);
    return pfn(pDb, pcv, i, ppStmt, ppcv);
}

PROXY_EXPORT int sqlite3_prepare16_v3(sqlite3* pDb, const void* pcv, int i, unsigned int, sqlite3_stmt** ppStmt, const void** ppcv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_prepare16_v3));
    sqlite3_prepare16_v3_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_prepare16_v3_fnptr_t>(ORG_SQLITE3_FN_IDX_PREPARE16_V3);
    return pfn(pDb, pcv, i, int, ppStmt, ppcv);
}

PROXY_EXPORT void* sqlite3_profile(sqlite3* pDb, void (*pfn)(void*, const char*, sqlite_uint64), void* pv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_profile));
    sqlite3_profile_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_profile_fnptr_t>(ORG_SQLITE3_FN_IDX_PROFILE);
    return pfn(pDb, pfn, pv);
}

PROXY_EXPORT void sqlite3_progress_handler(sqlite3* pDb, int i, int (*pfn)(void*), void* pv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_progress_handler));
    sqlite3_progress_handler_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_progress_handler_fnptr_t>(ORG_SQLITE3_FN_IDX_PROGRESS_HANDLER);
    return pfn(pDb, i, pfn, pv);
}

PROXY_EXPORT void sqlite3_randomness(int i, void* pv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_randomness));
    sqlite3_randomness_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_randomness_fnptr_t>(ORG_SQLITE3_FN_IDX_RANDOMNESS);
    return pfn(i, pv);
}

PROXY_EXPORT void* sqlite3_realloc(void* pv, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_realloc));
    sqlite3_realloc_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_realloc_fnptr_t>(ORG_SQLITE3_FN_IDX_REALLOC);
    return pfn(pv, i);
}

PROXY_EXPORT void* sqlite3_realloc64(void* pv, sqlite3_uint64 u64)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_realloc64));
    sqlite3_realloc64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_realloc64_fnptr_t>(ORG_SQLITE3_FN_IDX_REALLOC64);
    return pfn(pv, u64);
}

PROXY_EXPORT int sqlite3_rekey(sqlite3* db, const void* pKey, int nKey)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_rekey));
    sqlite3_rekey_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_rekey_fnptr_t>(ORG_SQLITE3_FN_IDX_REKEY);
    return pfn(db, pKey, nKey);
}

PROXY_EXPORT int sqlite3_rekey_v2(sqlite3* db, const char* zDbName, const void* pKey, int nKey)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_rekey_v2));
    sqlite3_rekey_v2_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_rekey_v2_fnptr_t>(ORG_SQLITE3_FN_IDX_REKEY_V2);
    return pfn(db, zDbName, pKey, nKey);
}

PROXY_EXPORT int sqlite3_release_memory(int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_release_memory));
    sqlite3_release_memory_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_release_memory_fnptr_t>(ORG_SQLITE3_FN_IDX_RELEASE_MEMORY);
    return pfn(i);
}

PROXY_EXPORT int sqlite3_reset(sqlite3_stmt* pStmt)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_reset));
    sqlite3_reset_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_reset_fnptr_t>(ORG_SQLITE3_FN_IDX_RESET);
    return pfn(pStmt);
}

PROXY_EXPORT void sqlite3_reset_auto_extension(void)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_reset_auto_extension));
    sqlite3_reset_auto_extension_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_reset_auto_extension_fnptr_t>(ORG_SQLITE3_FN_IDX_RESET_AUTO_EXTENSION);
    return pfn();
}

PROXY_EXPORT void sqlite3_result_blob(sqlite3_context* pCtx, const void* pcv, int i, void (*pfn)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_blob));
    sqlite3_result_blob_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_blob_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_BLOB);
    return pfn(pCtx, pcv, i, pfn);
}

PROXY_EXPORT void sqlite3_result_blob64(sqlite3_context* pCtx, const void* pcv, sqlite3_uint64 u64, void (*pfn)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_blob64));
    sqlite3_result_blob64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_blob64_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_BLOB64);
    return pfn(pCtx, pcv, u64, pfn);
}

PROXY_EXPORT void sqlite3_result_double(sqlite3_context* pCtx, double dbl)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_double));
    sqlite3_result_double_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_double_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_DOUBLE);
    return pfn(pCtx, dbl);
}

PROXY_EXPORT void sqlite3_result_error(sqlite3_context* pCtx, const char* pcStr, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_error));
    sqlite3_result_error_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_error_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_ERROR);
    return pfn(pCtx, pcStr, i);
}

PROXY_EXPORT void sqlite3_result_error_code(sqlite3_context* pCtx, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_error_code));
    sqlite3_result_error_code_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_error_code_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_ERROR_CODE);
    return pfn(pCtx, i);
}

PROXY_EXPORT void sqlite3_result_error_nomem(sqlite3_context* pCtx)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_error_nomem));
    sqlite3_result_error_nomem_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_error_nomem_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_ERROR_NOMEM);
    return pfn(pCtx);
}

PROXY_EXPORT void sqlite3_result_error_toobig(sqlite3_context* pCtx)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_error_toobig));
    sqlite3_result_error_toobig_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_error_toobig_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_ERROR_TOOBIG);
    return pfn(pCtx);
}

PROXY_EXPORT void sqlite3_result_error16(sqlite3_context* pCtx, const void* pcv, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_error16));
    sqlite3_result_error16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_error16_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_ERROR16);
    return pfn(pCtx, pcv, i);
}

PROXY_EXPORT void sqlite3_result_int(sqlite3_context* pCtx, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_int));
    sqlite3_result_int_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_int_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_INT);
    return pfn(pCtx, i);
}

PROXY_EXPORT void sqlite3_result_int64(sqlite3_context* pCtx, sqlite_int64 i64)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_int64));
    sqlite3_result_int64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_int64_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_INT64);
    return pfn(pCtx, i64);
}

PROXY_EXPORT void sqlite3_result_null(sqlite3_context* pCtx)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_null));
    sqlite3_result_null_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_null_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_NULL);
    return pfn(pCtx);
}

PROXY_EXPORT void sqlite3_result_pointer(sqlite3_context* pCtx, void* pv, const char* pcStr, void (*pfn)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_pointer));
    sqlite3_result_pointer_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_pointer_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_POINTER);
    return pfn(pCtx, pv, pcStr, pfn);
}

PROXY_EXPORT void sqlite3_result_subtype(sqlite3_context* pCtx, unsigned int)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_subtype));
    sqlite3_result_subtype_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_subtype_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_SUBTYPE);
    return pfn(pCtx, int);
}

PROXY_EXPORT void sqlite3_result_text(sqlite3_context* pCtx, const char* pcStr, int i, void (*pfn)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_text));
    sqlite3_result_text_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_text_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_TEXT);
    return pfn(pCtx, pcStr, i, pfn);
}

PROXY_EXPORT void sqlite3_result_text16(sqlite3_context* pCtx, const void* pcv, int i, void (*pfn)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_text16));
    sqlite3_result_text16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_text16_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_TEXT16);
    return pfn(pCtx, pcv, i, pfn);
}

PROXY_EXPORT void sqlite3_result_text16be(sqlite3_context* pCtx, const void* pcv, int i, void (*pfn)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_text16be));
    sqlite3_result_text16be_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_text16be_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_TEXT16BE);
    return pfn(pCtx, pcv, i, pfn);
}

PROXY_EXPORT void sqlite3_result_text16le(sqlite3_context* pCtx, const void* pcv, int i, void (*pfn)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_text16le));
    sqlite3_result_text16le_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_text16le_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_TEXT16LE);
    return pfn(pCtx, pcv, i, pfn);
}

PROXY_EXPORT void sqlite3_result_text64(sqlite3_context* pCtx, const char* pcStr, sqlite3_uint64 u64, void (*pfn)(void*), unsigned char)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_text64));
    sqlite3_result_text64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_text64_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_TEXT64);
    return pfn(pCtx, pcStr, u64, pfn, char);
}

PROXY_EXPORT void sqlite3_result_value(sqlite3_context* pCtx, sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_value));
    sqlite3_result_value_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_value_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_VALUE);
    return pfn(pCtx, pVal);
}

PROXY_EXPORT void sqlite3_result_zeroblob(sqlite3_context* pCtx, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_zeroblob));
    sqlite3_result_zeroblob_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_zeroblob_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_ZEROBLOB);
    return pfn(pCtx, i);
}

PROXY_EXPORT int sqlite3_result_zeroblob64(sqlite3_context* pCtx, sqlite3_uint64 u64)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_result_zeroblob64));
    sqlite3_result_zeroblob64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_result_zeroblob64_fnptr_t>(ORG_SQLITE3_FN_IDX_RESULT_ZEROBLOB64);
    return pfn(pCtx, u64);
}

PROXY_EXPORT void* sqlite3_rollback_hook(sqlite3* pDb, void (*pfn)(void*), void* pv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_rollback_hook));
    sqlite3_rollback_hook_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_rollback_hook_fnptr_t>(ORG_SQLITE3_FN_IDX_ROLLBACK_HOOK);
    return pfn(pDb, pfn, pv);
}

PROXY_EXPORT int sqlite3_rtree_geometry_callback(sqlite3* db, const char* zGeom, int (*xGeom)(sqlite3_rtree_geometry*, int, sqlite3_rtree_dbl*, int*), void* pContext)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_rtree_geometry_callback));
    sqlite3_rtree_geometry_callback_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_rtree_geometry_callback_fnptr_t>(ORG_SQLITE3_FN_IDX_RTREE_GEOMETRY_CALLBACK);
    return pfn(db, zGeom, xGeom, pContext);
}

PROXY_EXPORT int sqlite3_rtree_query_callback(sqlite3* db, const char* zQueryFunc, int (*xQueryFunc)(sqlite3_rtree_query_info*), void* pContext, void (*xDestructor)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_rtree_query_callback));
    sqlite3_rtree_query_callback_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_rtree_query_callback_fnptr_t>(ORG_SQLITE3_FN_IDX_RTREE_QUERY_CALLBACK);
    return pfn(db, zQueryFunc, xQueryFunc, pContext, xDestructor);
}

PROXY_EXPORT unsigned char* sqlite3_serialize(sqlite3* pDb, const char* pcStr, sqlite3_int64* pI64, unsigned int)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_serialize));
    sqlite3_serialize_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_serialize_fnptr_t>(ORG_SQLITE3_FN_IDX_SERIALIZE);
    return pfn(pDb, pcStr, pI64, int);
}

PROXY_EXPORT int sqlite3_set_authorizer(sqlite3* pDb, int (*pfn)(void*, int, const char*, const char*, const char*, const char*), void* pv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_set_authorizer));
    sqlite3_set_authorizer_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_set_authorizer_fnptr_t>(ORG_SQLITE3_FN_IDX_SET_AUTHORIZER);
    return pfn(pDb, pfn, pv);
}

PROXY_EXPORT void sqlite3_set_auxdata(sqlite3_context* pCtx, int i, void* pv, void (*pfn)(void*))
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_set_auxdata));
    sqlite3_set_auxdata_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_set_auxdata_fnptr_t>(ORG_SQLITE3_FN_IDX_SET_AUXDATA);
    return pfn(pCtx, i, pv, pfn);
}

PROXY_EXPORT void sqlite3_set_last_insert_rowid(sqlite3* pDb, sqlite3_int64 i64)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_set_last_insert_rowid));
    sqlite3_set_last_insert_rowid_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_set_last_insert_rowid_fnptr_t>(ORG_SQLITE3_FN_IDX_SET_LAST_INSERT_ROWID);
    return pfn(pDb, i64);
}

PROXY_EXPORT int sqlite3_shutdown(void)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_shutdown));
    sqlite3_shutdown_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_shutdown_fnptr_t>(ORG_SQLITE3_FN_IDX_SHUTDOWN);
    return pfn();
}

PROXY_EXPORT int sqlite3_sleep(int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_sleep));
    sqlite3_sleep_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_sleep_fnptr_t>(ORG_SQLITE3_FN_IDX_SLEEP);
    return pfn(i);
}

PROXY_EXPORT int sqlite3_snapshot_cmp(sqlite3_snapshot* p1, sqlite3_snapshot* p2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_snapshot_cmp));
    sqlite3_snapshot_cmp_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_snapshot_cmp_fnptr_t>(ORG_SQLITE3_FN_IDX_SNAPSHOT_CMP);
    return pfn(p1, p2);
}

PROXY_EXPORT void sqlite3_snapshot_free(sqlite3_snapshot* arg)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_snapshot_free));
    sqlite3_snapshot_free_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_snapshot_free_fnptr_t>(ORG_SQLITE3_FN_IDX_SNAPSHOT_FREE);
    return pfn(arg);
}

PROXY_EXPORT int sqlite3_snapshot_get(sqlite3* db, const char* zSchema, sqlite3_snapshot** ppSnapshot)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_snapshot_get));
    sqlite3_snapshot_get_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_snapshot_get_fnptr_t>(ORG_SQLITE3_FN_IDX_SNAPSHOT_GET);
    return pfn(db, zSchema, ppSnapshot);
}

PROXY_EXPORT int sqlite3_snapshot_open(sqlite3* db, const char* zSchema, sqlite3_snapshot* pSnapshot)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_snapshot_open));
    sqlite3_snapshot_open_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_snapshot_open_fnptr_t>(ORG_SQLITE3_FN_IDX_SNAPSHOT_OPEN);
    return pfn(db, zSchema, pSnapshot);
}

PROXY_EXPORT int sqlite3_snapshot_recover(sqlite3* db, const char* zDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_snapshot_recover));
    sqlite3_snapshot_recover_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_snapshot_recover_fnptr_t>(ORG_SQLITE3_FN_IDX_SNAPSHOT_RECOVER);
    return pfn(db, zDb);
}

PROXY_EXPORT char* sqlite3_snprintf(int i, char* pStr, const char* pcStr, ...)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_snprintf));
    PROXY_SQLITE3_SNPRINTF_IMPL();
}

PROXY_EXPORT void sqlite3_soft_heap_limit(int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_soft_heap_limit));
    sqlite3_soft_heap_limit_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_soft_heap_limit_fnptr_t>(ORG_SQLITE3_FN_IDX_SOFT_HEAP_LIMIT);
    return pfn(i);
}

PROXY_EXPORT sqlite3_int64 sqlite3_soft_heap_limit64(sqlite3_int64 i64)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_soft_heap_limit64));
    sqlite3_soft_heap_limit64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_soft_heap_limit64_fnptr_t>(ORG_SQLITE3_FN_IDX_SOFT_HEAP_LIMIT64);
    return pfn(i64);
}

PROXY_EXPORT const char* sqlite3_sourceid(void)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_sourceid));
    sqlite3_sourceid_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_sourceid_fnptr_t>(ORG_SQLITE3_FN_IDX_SOURCEID);
    return pfn();
}

PROXY_EXPORT const char* sqlite3_sql(sqlite3_stmt* pStmt)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_sql));
    sqlite3_sql_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_sql_fnptr_t>(ORG_SQLITE3_FN_IDX_SQL);
    return pfn(pStmt);
}

PROXY_EXPORT int sqlite3_status(int i, int* pInt, int* pInt2, int i2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_status));
    sqlite3_status_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_status_fnptr_t>(ORG_SQLITE3_FN_IDX_STATUS);
    return pfn(i, pInt, pInt2, i2);
}

PROXY_EXPORT int sqlite3_status64(int i, sqlite3_int64* pI64, sqlite3_int64* pI642, int i2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_status64));
    sqlite3_status64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_status64_fnptr_t>(ORG_SQLITE3_FN_IDX_STATUS64);
    return pfn(i, pI64, pI642, i2);
}

PROXY_EXPORT int sqlite3_step(sqlite3_stmt* pStmt)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_step));
    sqlite3_step_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_step_fnptr_t>(ORG_SQLITE3_FN_IDX_STEP);
    return pfn(pStmt);
}

PROXY_EXPORT int sqlite3_stmt_busy(sqlite3_stmt* pStmt)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_stmt_busy));
    sqlite3_stmt_busy_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_stmt_busy_fnptr_t>(ORG_SQLITE3_FN_IDX_STMT_BUSY);
    return pfn(pStmt);
}

PROXY_EXPORT int sqlite3_stmt_isexplain(sqlite3_stmt* pStmt)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_stmt_isexplain));
    sqlite3_stmt_isexplain_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_stmt_isexplain_fnptr_t>(ORG_SQLITE3_FN_IDX_STMT_ISEXPLAIN);
    return pfn(pStmt);
}

PROXY_EXPORT int sqlite3_stmt_readonly(sqlite3_stmt* pStmt)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_stmt_readonly));
    sqlite3_stmt_readonly_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_stmt_readonly_fnptr_t>(ORG_SQLITE3_FN_IDX_STMT_READONLY);
    return pfn(pStmt);
}

PROXY_EXPORT int sqlite3_stmt_status(sqlite3_stmt* pStmt, int i, int i2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_stmt_status));
    sqlite3_stmt_status_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_stmt_status_fnptr_t>(ORG_SQLITE3_FN_IDX_STMT_STATUS);
    return pfn(pStmt, i, i2);
}

PROXY_EXPORT void sqlite3_str_append(sqlite3_str* pqStr, const char* zIn, int N)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_str_append));
    sqlite3_str_append_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_str_append_fnptr_t>(ORG_SQLITE3_FN_IDX_STR_APPEND);
    return pfn(pqStr, zIn, N);
}

PROXY_EXPORT void sqlite3_str_appendall(sqlite3_str* pqStr, const char* zIn)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_str_appendall));
    sqlite3_str_appendall_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_str_appendall_fnptr_t>(ORG_SQLITE3_FN_IDX_STR_APPENDALL);
    return pfn(pqStr, zIn);
}

PROXY_EXPORT void sqlite3_str_appendchar(sqlite3_str* pqStr, int N, char C)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_str_appendchar));
    sqlite3_str_appendchar_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_str_appendchar_fnptr_t>(ORG_SQLITE3_FN_IDX_STR_APPENDCHAR);
    return pfn(pqStr, N, C);
}

PROXY_EXPORT void sqlite3_str_appendf(sqlite3_str* pqStr, const char* zFormat, ...)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_str_appendf));
    PROXY_SQLITE3_STR_APPENDF_IMPL();
}

PROXY_EXPORT int sqlite3_str_errcode(sqlite3_str* pqStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_str_errcode));
    sqlite3_str_errcode_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_str_errcode_fnptr_t>(ORG_SQLITE3_FN_IDX_STR_ERRCODE);
    return pfn(pqStr);
}

PROXY_EXPORT char* sqlite3_str_finish(sqlite3_str* pqStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_str_finish));
    sqlite3_str_finish_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_str_finish_fnptr_t>(ORG_SQLITE3_FN_IDX_STR_FINISH);
    return pfn(pqStr);
}

PROXY_EXPORT int sqlite3_str_length(sqlite3_str* pqStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_str_length));
    sqlite3_str_length_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_str_length_fnptr_t>(ORG_SQLITE3_FN_IDX_STR_LENGTH);
    return pfn(pqStr);
}

PROXY_EXPORT sqlite3_str* sqlite3_str_new(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_str_new));
    sqlite3_str_new_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_str_new_fnptr_t>(ORG_SQLITE3_FN_IDX_STR_NEW);
    return pfn(pDb);
}

PROXY_EXPORT void sqlite3_str_reset(sqlite3_str* pqStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_str_reset));
    sqlite3_str_reset_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_str_reset_fnptr_t>(ORG_SQLITE3_FN_IDX_STR_RESET);
    return pfn(pqStr);
}

PROXY_EXPORT char* sqlite3_str_value(sqlite3_str* pqStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_str_value));
    sqlite3_str_value_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_str_value_fnptr_t>(ORG_SQLITE3_FN_IDX_STR_VALUE);
    return pfn(pqStr);
}

PROXY_EXPORT void sqlite3_str_vappendf(sqlite3_str* pqStr, const char* zFormat, va_list vaLst)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_str_vappendf));
    sqlite3_str_vappendf_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_str_vappendf_fnptr_t>(ORG_SQLITE3_FN_IDX_STR_VAPPENDF);
    return pfn(pqStr, zFormat, vaLst);
}

PROXY_EXPORT int sqlite3_strglob(const char* pcStr, const char* pcStr2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_strglob));
    sqlite3_strglob_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_strglob_fnptr_t>(ORG_SQLITE3_FN_IDX_STRGLOB);
    return pfn(pcStr, pcStr2);
}

PROXY_EXPORT int sqlite3_stricmp(const char* pcStr, const char* pcStr2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_stricmp));
    sqlite3_stricmp_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_stricmp_fnptr_t>(ORG_SQLITE3_FN_IDX_STRICMP);
    return pfn(pcStr, pcStr2);
}

PROXY_EXPORT int sqlite3_strlike(const char* pcStr, const char* pcStr2, unsigned int)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_strlike));
    sqlite3_strlike_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_strlike_fnptr_t>(ORG_SQLITE3_FN_IDX_STRLIKE);
    return pfn(pcStr, pcStr2, int);
}

PROXY_EXPORT int sqlite3_strnicmp(const char* pcStr, const char* pcStr2, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_strnicmp));
    sqlite3_strnicmp_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_strnicmp_fnptr_t>(ORG_SQLITE3_FN_IDX_STRNICMP);
    return pfn(pcStr, pcStr2, i);
}

PROXY_EXPORT int sqlite3_system_errno(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_system_errno));
    sqlite3_system_errno_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_system_errno_fnptr_t>(ORG_SQLITE3_FN_IDX_SYSTEM_ERRNO);
    return pfn(pDb);
}

PROXY_EXPORT int sqlite3_table_column_metadata(sqlite3* pDb, const char* pcStr, const char* pcStr2, const char* pcStr3, char const** ppcStr, char const** ppcStr2, int* pInt, int* pInt2, int* pInt3)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_table_column_metadata));
    sqlite3_table_column_metadata_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_table_column_metadata_fnptr_t>(ORG_SQLITE3_FN_IDX_TABLE_COLUMN_METADATA);
    return pfn(pDb, pcStr, pcStr2, pcStr3, ppcStr, ppcStr2, pInt, pInt2, pInt3);
}

PROXY_EXPORT PROXY_SQLITE3_TEMP_DIRECTORY_DATA(sqlite3_temp_directory);

PROXY_EXPORT int sqlite3_test_control(int i, ...)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_test_control));
    PROXY_SQLITE3_TEST_CONTROL_IMPL();
}

PROXY_EXPORT void sqlite3_thread_cleanup(void)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_thread_cleanup));
    sqlite3_thread_cleanup_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_thread_cleanup_fnptr_t>(ORG_SQLITE3_FN_IDX_THREAD_CLEANUP);
    return pfn();
}

PROXY_EXPORT int sqlite3_threadsafe(void)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_threadsafe));
    sqlite3_threadsafe_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_threadsafe_fnptr_t>(ORG_SQLITE3_FN_IDX_THREADSAFE);
    return pfn();
}

PROXY_EXPORT int sqlite3_total_changes(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_total_changes));
    sqlite3_total_changes_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_total_changes_fnptr_t>(ORG_SQLITE3_FN_IDX_TOTAL_CHANGES);
    return pfn(pDb);
}

PROXY_EXPORT sqlite3_int64 sqlite3_total_changes64(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_total_changes64));
    sqlite3_total_changes64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_total_changes64_fnptr_t>(ORG_SQLITE3_FN_IDX_TOTAL_CHANGES64);
    return pfn(pDb);
}

PROXY_EXPORT void* sqlite3_trace(sqlite3* pDb, void (*xTrace)(void*, const char*), void* pv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_trace));
    sqlite3_trace_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_trace_fnptr_t>(ORG_SQLITE3_FN_IDX_TRACE);
    return pfn(pDb, xTrace, pv);
}

PROXY_EXPORT int sqlite3_trace_v2(sqlite3* pDb, unsigned u, int (*pfn)(unsigned, void*, void*, void*), void* pv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_trace_v2));
    sqlite3_trace_v2_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_trace_v2_fnptr_t>(ORG_SQLITE3_FN_IDX_TRACE_V2);
    return pfn(pDb, u, pfn, pv);
}

PROXY_EXPORT int sqlite3_transfer_bindings(sqlite3_stmt* pStmt, sqlite3_stmt* pStmt2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_transfer_bindings));
    sqlite3_transfer_bindings_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_transfer_bindings_fnptr_t>(ORG_SQLITE3_FN_IDX_TRANSFER_BINDINGS);
    return pfn(pStmt, pStmt2);
}

PROXY_EXPORT int sqlite3_txn_state(sqlite3* pDb, const char* pcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_txn_state));
    sqlite3_txn_state_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_txn_state_fnptr_t>(ORG_SQLITE3_FN_IDX_TXN_STATE);
    return pfn(pDb, pcStr);
}

PROXY_EXPORT void* sqlite3_update_hook(sqlite3* pDb, void (*pfn)(void*, int, char const*, char const*, sqlite_int64), void* pv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_update_hook));
    sqlite3_update_hook_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_update_hook_fnptr_t>(ORG_SQLITE3_FN_IDX_UPDATE_HOOK);
    return pfn(pDb, pfn, pv);
}

PROXY_EXPORT int sqlite3_uri_boolean(const char* pcStr, const char* pcStr2, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_uri_boolean));
    sqlite3_uri_boolean_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_uri_boolean_fnptr_t>(ORG_SQLITE3_FN_IDX_URI_BOOLEAN);
    return pfn(pcStr, pcStr2, i);
}

PROXY_EXPORT sqlite3_int64 sqlite3_uri_int64(const char* pcStr, const char* pcStr2, sqlite3_int64 i64)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_uri_int64));
    sqlite3_uri_int64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_uri_int64_fnptr_t>(ORG_SQLITE3_FN_IDX_URI_INT64);
    return pfn(pcStr, pcStr2, i64);
}

PROXY_EXPORT const char* sqlite3_uri_key(const char* pcStr, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_uri_key));
    sqlite3_uri_key_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_uri_key_fnptr_t>(ORG_SQLITE3_FN_IDX_URI_KEY);
    return pfn(pcStr, i);
}

PROXY_EXPORT const char* sqlite3_uri_parameter(const char* pcStr, const char* pcStr2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_uri_parameter));
    sqlite3_uri_parameter_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_uri_parameter_fnptr_t>(ORG_SQLITE3_FN_IDX_URI_PARAMETER);
    return pfn(pcStr, pcStr2);
}

PROXY_EXPORT void* sqlite3_user_data(sqlite3_context* pCtx)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_user_data));
    sqlite3_user_data_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_user_data_fnptr_t>(ORG_SQLITE3_FN_IDX_USER_DATA);
    return pfn(pCtx);
}

PROXY_EXPORT const void* sqlite3_value_blob(sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_blob));
    sqlite3_value_blob_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_blob_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_BLOB);
    return pfn(pVal);
}

PROXY_EXPORT int sqlite3_value_bytes(sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_bytes));
    sqlite3_value_bytes_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_bytes_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_BYTES);
    return pfn(pVal);
}

PROXY_EXPORT int sqlite3_value_bytes16(sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_bytes16));
    sqlite3_value_bytes16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_bytes16_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_BYTES16);
    return pfn(pVal);
}

PROXY_EXPORT double sqlite3_value_double(sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_double));
    sqlite3_value_double_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_double_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_DOUBLE);
    return pfn(pVal);
}

PROXY_EXPORT sqlite3_value* sqlite3_value_dup(const sqlite3_value* pcVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_dup));
    sqlite3_value_dup_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_dup_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_DUP);
    return pfn(pcVal);
}

PROXY_EXPORT void sqlite3_value_free(sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_free));
    sqlite3_value_free_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_free_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_FREE);
    return pfn(pVal);
}

PROXY_EXPORT int sqlite3_value_frombind(sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_frombind));
    sqlite3_value_frombind_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_frombind_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_FROMBIND);
    return pfn(pVal);
}

PROXY_EXPORT int sqlite3_value_int(sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_int));
    sqlite3_value_int_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_int_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_INT);
    return pfn(pVal);
}

PROXY_EXPORT sqlite_int64 sqlite3_value_int64(sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_int64));
    sqlite3_value_int64_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_int64_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_INT64);
    return pfn(pVal);
}

PROXY_EXPORT int sqlite3_value_nochange(sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_nochange));
    sqlite3_value_nochange_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_nochange_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_NOCHANGE);
    return pfn(pVal);
}

PROXY_EXPORT int sqlite3_value_numeric_type(sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_numeric_type));
    sqlite3_value_numeric_type_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_numeric_type_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_NUMERIC_TYPE);
    return pfn(pVal);
}

PROXY_EXPORT void* sqlite3_value_pointer(sqlite3_value* pVal, const char* pcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_pointer));
    sqlite3_value_pointer_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_pointer_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_POINTER);
    return pfn(pVal, pcStr);
}

PROXY_EXPORT unsigned int sqlite3_value_subtype(sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_subtype));
    sqlite3_value_subtype_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_subtype_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_SUBTYPE);
    return pfn(pVal);
}

PROXY_EXPORT const unsigned char* sqlite3_value_text(sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_text));
    sqlite3_value_text_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_text_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_TEXT);
    return pfn(pVal);
}

PROXY_EXPORT const void* sqlite3_value_text16(sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_text16));
    sqlite3_value_text16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_text16_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_TEXT16);
    return pfn(pVal);
}

PROXY_EXPORT const void* sqlite3_value_text16be(sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_text16be));
    sqlite3_value_text16be_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_text16be_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_TEXT16BE);
    return pfn(pVal);
}

PROXY_EXPORT const void* sqlite3_value_text16le(sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_text16le));
    sqlite3_value_text16le_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_text16le_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_TEXT16LE);
    return pfn(pVal);
}

PROXY_EXPORT int sqlite3_value_type(sqlite3_value* pVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_value_type));
    sqlite3_value_type_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_value_type_fnptr_t>(ORG_SQLITE3_FN_IDX_VALUE_TYPE);
    return pfn(pVal);
}

PROXY_EXPORT PROXY_SQLITE3_VERSION_DATA(sqlite3_version);

PROXY_EXPORT sqlite3_vfs* sqlite3_vfs_find(const char* pcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_vfs_find));
    sqlite3_vfs_find_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_vfs_find_fnptr_t>(ORG_SQLITE3_FN_IDX_VFS_FIND);
    return pfn(pcStr);
}

PROXY_EXPORT int sqlite3_vfs_register(sqlite3_vfs* pVfs, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_vfs_register));
    sqlite3_vfs_register_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_vfs_register_fnptr_t>(ORG_SQLITE3_FN_IDX_VFS_REGISTER);
    return pfn(pVfs, i);
}

PROXY_EXPORT int sqlite3_vfs_unregister(sqlite3_vfs* pVfs)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_vfs_unregister));
    sqlite3_vfs_unregister_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_vfs_unregister_fnptr_t>(ORG_SQLITE3_FN_IDX_VFS_UNREGISTER);
    return pfn(pVfs);
}

PROXY_EXPORT char* sqlite3_vmprintf(const char* pcStr, va_list vaLst)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_vmprintf));
    sqlite3_vmprintf_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_vmprintf_fnptr_t>(ORG_SQLITE3_FN_IDX_VMPRINTF);
    return pfn(pcStr, vaLst);
}

PROXY_EXPORT char* sqlite3_vsnprintf(int i, char* pStr, const char* pcStr, va_list vaLst)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_vsnprintf));
    sqlite3_vsnprintf_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_vsnprintf_fnptr_t>(ORG_SQLITE3_FN_IDX_VSNPRINTF);
    return pfn(i, pStr, pcStr, vaLst);
}

PROXY_EXPORT const char* sqlite3_vtab_collation(sqlite3_index_info* pIdxInfo, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_vtab_collation));
    sqlite3_vtab_collation_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_vtab_collation_fnptr_t>(ORG_SQLITE3_FN_IDX_VTAB_COLLATION);
    return pfn(pIdxInfo, i);
}

PROXY_EXPORT int sqlite3_vtab_config(sqlite3* pDb, int op, ...)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_vtab_config));
    PROXY_SQLITE3_VTAB_CONFIG_IMPL();
}

PROXY_EXPORT int sqlite3_vtab_distinct(sqlite3_index_info* pIdxInfo)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_vtab_distinct));
    sqlite3_vtab_distinct_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_vtab_distinct_fnptr_t>(ORG_SQLITE3_FN_IDX_VTAB_DISTINCT);
    return pfn(pIdxInfo);
}

PROXY_EXPORT int sqlite3_vtab_in(sqlite3_index_info* pIdxInfo, int i, int i2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_vtab_in));
    sqlite3_vtab_in_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_vtab_in_fnptr_t>(ORG_SQLITE3_FN_IDX_VTAB_IN);
    return pfn(pIdxInfo, i, i2);
}

PROXY_EXPORT int sqlite3_vtab_in_first(sqlite3_value* pVal, sqlite3_value** ppVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_vtab_in_first));
    sqlite3_vtab_in_first_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_vtab_in_first_fnptr_t>(ORG_SQLITE3_FN_IDX_VTAB_IN_FIRST);
    return pfn(pVal, ppVal);
}

PROXY_EXPORT int sqlite3_vtab_in_next(sqlite3_value* pVal, sqlite3_value** ppVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_vtab_in_next));
    sqlite3_vtab_in_next_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_vtab_in_next_fnptr_t>(ORG_SQLITE3_FN_IDX_VTAB_IN_NEXT);
    return pfn(pVal, ppVal);
}

PROXY_EXPORT int sqlite3_vtab_nochange(sqlite3_context* pCtx)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_vtab_nochange));
    sqlite3_vtab_nochange_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_vtab_nochange_fnptr_t>(ORG_SQLITE3_FN_IDX_VTAB_NOCHANGE);
    return pfn(pCtx);
}

PROXY_EXPORT int sqlite3_vtab_on_conflict(sqlite3* pDb)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_vtab_on_conflict));
    sqlite3_vtab_on_conflict_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_vtab_on_conflict_fnptr_t>(ORG_SQLITE3_FN_IDX_VTAB_ON_CONFLICT);
    return pfn(pDb);
}

PROXY_EXPORT int sqlite3_vtab_rhs_value(sqlite3_index_info* pIdxInfo, int i, sqlite3_value** ppVal)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_vtab_rhs_value));
    sqlite3_vtab_rhs_value_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_vtab_rhs_value_fnptr_t>(ORG_SQLITE3_FN_IDX_VTAB_RHS_VALUE);
    return pfn(pIdxInfo, i, ppVal);
}

PROXY_EXPORT int sqlite3_wal_autocheckpoint(sqlite3* pDb, int i)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_wal_autocheckpoint));
    sqlite3_wal_autocheckpoint_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_wal_autocheckpoint_fnptr_t>(ORG_SQLITE3_FN_IDX_WAL_AUTOCHECKPOINT);
    return pfn(pDb, i);
}

PROXY_EXPORT int sqlite3_wal_checkpoint(sqlite3* pDb, const char* pcStr)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_wal_checkpoint));
    sqlite3_wal_checkpoint_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_wal_checkpoint_fnptr_t>(ORG_SQLITE3_FN_IDX_WAL_CHECKPOINT);
    return pfn(pDb, pcStr);
}

PROXY_EXPORT int sqlite3_wal_checkpoint_v2(sqlite3* pDb, const char* pcStr, int i, int* pInt, int* pInt2)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_wal_checkpoint_v2));
    sqlite3_wal_checkpoint_v2_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_wal_checkpoint_v2_fnptr_t>(ORG_SQLITE3_FN_IDX_WAL_CHECKPOINT_V2);
    return pfn(pDb, pcStr, i, pInt, pInt2);
}

PROXY_EXPORT void* sqlite3_wal_hook(sqlite3* pDb, int (*pfn)(void*, sqlite3*, const char*, int), void* pv)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_wal_hook));
    sqlite3_wal_hook_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_wal_hook_fnptr_t>(ORG_SQLITE3_FN_IDX_WAL_HOOK);
    return pfn(pDb, pfn, pv);
}

PROXY_EXPORT int sqlite3_win32_is_nt(void)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_win32_is_nt));
    sqlite3_win32_is_nt_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_win32_is_nt_fnptr_t>(ORG_SQLITE3_FN_IDX_WIN32_IS_NT);
    return pfn();
}

PROXY_EXPORT char* sqlite3_win32_mbcs_to_utf8(const char* zText)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_win32_mbcs_to_utf8));
    sqlite3_win32_mbcs_to_utf8_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_win32_mbcs_to_utf8_fnptr_t>(ORG_SQLITE3_FN_IDX_WIN32_MBCS_TO_UTF8);
    return pfn(zText);
}

PROXY_EXPORT char* sqlite3_win32_mbcs_to_utf8_v2(const char* zText, int useAnsi)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_win32_mbcs_to_utf8_v2));
    sqlite3_win32_mbcs_to_utf8_v2_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_win32_mbcs_to_utf8_v2_fnptr_t>(ORG_SQLITE3_FN_IDX_WIN32_MBCS_TO_UTF8_V2);
    return pfn(zText, useAnsi);
}

PROXY_EXPORT int sqlite3_win32_set_directory(unsigned long type, void* zValue)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_win32_set_directory));
    sqlite3_win32_set_directory_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_win32_set_directory_fnptr_t>(ORG_SQLITE3_FN_IDX_WIN32_SET_DIRECTORY);
    return pfn(type, zValue);
}

PROXY_EXPORT int sqlite3_win32_set_directory16(unsigned long type, const void* zValue)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_win32_set_directory16));
    sqlite3_win32_set_directory16_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_win32_set_directory16_fnptr_t>(ORG_SQLITE3_FN_IDX_WIN32_SET_DIRECTORY16);
    return pfn(type, zValue);
}

PROXY_EXPORT int sqlite3_win32_set_directory8(unsigned long type, const char* zValue)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_win32_set_directory8));
    sqlite3_win32_set_directory8_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_win32_set_directory8_fnptr_t>(ORG_SQLITE3_FN_IDX_WIN32_SET_DIRECTORY8);
    return pfn(type, zValue);
}

PROXY_EXPORT void sqlite3_win32_sleep(DWORD milliseconds)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_win32_sleep));
    sqlite3_win32_sleep_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_win32_sleep_fnptr_t>(ORG_SQLITE3_FN_IDX_WIN32_SLEEP);
    return pfn(milliseconds);
}

PROXY_EXPORT char* sqlite3_win32_unicode_to_utf8(LPCWSTR zWideText)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_win32_unicode_to_utf8));
    sqlite3_win32_unicode_to_utf8_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_win32_unicode_to_utf8_fnptr_t>(ORG_SQLITE3_FN_IDX_WIN32_UNICODE_TO_UTF8);
    return pfn(zWideText);
}

PROXY_EXPORT char* sqlite3_win32_utf8_to_mbcs(const char* zText)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_win32_utf8_to_mbcs));
    sqlite3_win32_utf8_to_mbcs_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_win32_utf8_to_mbcs_fnptr_t>(ORG_SQLITE3_FN_IDX_WIN32_UTF8_TO_MBCS);
    return pfn(zText);
}

PROXY_EXPORT char* sqlite3_win32_utf8_to_mbcs_v2(const char* zText, int useAnsi)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_win32_utf8_to_mbcs_v2));
    sqlite3_win32_utf8_to_mbcs_v2_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_win32_utf8_to_mbcs_v2_fnptr_t>(ORG_SQLITE3_FN_IDX_WIN32_UTF8_TO_MBCS_V2);
    return pfn(zText, useAnsi);
}

PROXY_EXPORT LPWSTR sqlite3_win32_utf8_to_unicode(const char* zText)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_win32_utf8_to_unicode));
    sqlite3_win32_utf8_to_unicode_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_win32_utf8_to_unicode_fnptr_t>(ORG_SQLITE3_FN_IDX_WIN32_UTF8_TO_UNICODE);
    return pfn(zText);
}

PROXY_EXPORT void sqlite3_win32_write_debug(const char* zBuf, int nBuf)
{
    WHATSAPP_TRACE(("Proxy called: %s\n", sqlite3_win32_write_debug));
    sqlite3_win32_write_debug_fnptr_t pfn = getOriginalFunctionPtr<sqlite3_win32_write_debug_fnptr_t>(ORG_SQLITE3_FN_IDX_WIN32_WRITE_DEBUG);
    return pfn(zBuf, nBuf);
}

