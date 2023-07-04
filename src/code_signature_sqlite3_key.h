static
std::vector<MatchPiece> code_signature_sqlite3_key =
{ 
  // .text:00007FFCCE1EC2A0 48 89 5C 24 08                          mov     [rsp+arg_0], rbx
  // .text:00007FFCCE1EC2A5 48 89 6C 24 10                          mov     [rsp+arg_8], rbp
  // .text:00007FFCCE1EC2AA 48 89 74 24 18                          mov     [rsp+arg_10], rsi
  // .text:00007FFCCE1EC2AF 57                                      push    rdi
  // .text:00007FFCCE1EC2B0 48 83 EC 20                             sub     rsp, 20h
  // .text:00007FFCCE1EC2B4 83 3D 59 C0 5C 00 00                    cmp     cs:dword_7FFCCE7B8314, 0
  
  { 0, { 0x48, 0x89, 0x5C, 0x24, 0x08 // mov     [rsp+arg_0], rbx
       , 0x48, 0x89, 0x6C, 0x24, 0x10 // mov     [rsp+arg_8], rbp
       , 0x48, 0x89, 0x74, 0x24, 0x18 // mov     [rsp+arg_10], rsi
       , 0x57                         // push    rdi
       , 0x48, 0x83, 0xEC, 0x20       // sub     rsp, 20h
       }
  }

// Я тут хз, какие байти в инструкции зависят от адреса загрузки, может и никакие, но пока пропустим её целиком
, { 7, {} } // 83 3D 59 C0 5C 00 00   cmp     cs:dword_7FFCCE7B8314, 0

  // .text:00007FFCCE1EC2BB 41 8B F1                                mov     esi, r9d
  // .text:00007FFCCE1EC2BE 49 8B E8                                mov     rbp, r8
  // .text:00007FFCCE1EC2C1 48 8B FA                                mov     rdi, rdx
  // .text:00007FFCCE1EC2C4 48 8B D9                                mov     rbx, rcx
  // .text:00007FFCCE1EC2C7 75 07                                   jnz     short loc_7FFCCE1EC2D0
  // .text:00007FFCCE1EC2C9 B8 15 00 00 00                          mov     eax, 15h
  // .text:00007FFCCE1EC2CE EB 72                                   jmp     short loc_7FFCCE1EC342

  // .text:00007FFCCE1EC2D0                         ; ---------------------------------------------------------------------------
  // .text:00007FFCCE1EC2D0                         loc_7FFCCE1EC2D0:                       ; CODE XREF: sqlite3_key+27^j
  // .text:00007FFCCE1EC2D0 48 8B 49 18                             mov     rcx, [rcx+18h]
  // .text:00007FFCCE1EC2D4 48 85 C9                                test    rcx, rcx
  // .text:00007FFCCE1EC2D7 74 0D                                   jz      short loc_7FFCCE1EC2E6


, { 0, { 0x41, 0x8B, 0xF1             // mov     esi, r9d
       , 0x49, 0x8B, 0xE8             // mov     rbp, r8
       , 0x48, 0x8B, 0xFA             // mov     rdi, rdx
       , 0x48, 0x8B, 0xD9             // mov     rbx, rcx
       , 0x75, 0x07                   // jnz     short loc_7FFCCE1EC2D0
       , 0xB8, 0x15, 0x00, 0x00, 0x00 // mov     eax, 15h
       , 0xEB, 0x72                   // jmp     short loc_7FFCCE1EC342
       , 0x48, 0x8B, 0x49, 0x18       // mov     rcx, [rcx+18h]
       , 0x48, 0x85, 0xC9             // test    rcx, rcx
       , 0x74, 0x0D                   // jz      short loc_7FFCCE1EC2E6
       }
  }

  // .text:00007FFCCE1EC2D9 48 8B 05 00 BD 5C 00                    mov     rax, cs:EnterCriticalSectionAddr
  // .text:00007FFCCE1EC2E0 FF 15 72 2F 42 00                       call    cs:__guard_dispatch_icall_fptr
, { 7+6, {} }

// .text:00007FFCCE1EC2D0                         ; ---------------------------------------------------------------------------
// .text:00007FFCCE1EC2E6                         loc_7FFCCE1EC2E6:                       ; CODE XREF: sqlite3_key+37^j
// .text:00007FFCCE1EC2E6 80 7B 69 00                             cmp     byte ptr [rbx+69h], 0
// .text:00007FFCCE1EC2EA 75 08                                   jnz     short loc_7FFCCE1EC2F4
// .text:00007FFCCE1EC2EC 48 8B CB                                mov     rcx, rbx

, { 0, { 0x80, 0x7B, 0x69, 0x00       // cmp     byte ptr [rbx+69h], 0
       , 0x75, 0x08                   // jnz     short loc_7FFCCE1EC2F4
       , 0x48, 0x8B, 0xCB             // mov     rcx, rbx
       }
  }

// .text:00007FFCCE1EC2EF E8 1C A6 F4 FF                          call    sub_7FFCCE136910
, { 5, {} }

// .text:00007FFCCE1EC2F4                         loc_7FFCCE1EC2F4:                       ; CODE XREF: sqlite3_key+4A^j
// .text:00007FFCCE1EC2F4 48 8B D7                                mov     rdx, rdi
// .text:00007FFCCE1EC2F7 48 8B CB                                mov     rcx, rbx
, { 0, { 0x48, 0x8B, 0xD7             // mov     rdx, rdi
       , 0x48, 0x8B, 0xCB             // mov     rcx, rbx
       }
  }

// .text:00007FFCCE1EC2FA E8 F1 FE FF FF                          call    sqlcipher_find_db_index
, { 5, {} }


// .text:00007FFCCE1EC2FF 85 C0                                   test    eax, eax
// .text:00007FFCCE1EC301 79 07                                   jns     short loc_7FFCCE1EC30A
// .text:00007FFCCE1EC303 BF 01 00 00 00                          mov     edi, 1
// .text:00007FFCCE1EC308 EB 12                                   jmp     short loc_7FFCCE1EC31C
, { 0, { 0x85, 0xC0                   // test    eax, eax
       , 0x79, 0x07                   // jns     short loc_7FFCCE1EC30A
       , 0xBF, 0x01, 0x00, 0x00, 00   // mov     edi, 1
       , 0xEB, 0x12                   // jmp     short loc_7FFCCE1EC31C
       }
  }

// .text:00007FFCCE1EC30A                         ; ---------------------------------------------------------------------------
// .text:00007FFCCE1EC30A
// .text:00007FFCCE1EC30A                         loc_7FFCCE1EC30A:                       ; CODE XREF: sqlite3_key+61^j
// .text:00007FFCCE1EC30A 44 8B CE                                mov     r9d, esi
// .text:00007FFCCE1EC30D 4C 8B C5                                mov     r8, rbp
// .text:00007FFCCE1EC310 8B D0                                   mov     edx, eax
// .text:00007FFCCE1EC312 48 8B CB                                mov     rcx, rbx
, { 0, { 0x44, 0x8B, 0xCE             // mov     r9d, esi
       , 0x4C, 0x8B, 0xC5             // mov     r8, rbp
       , 0x8B, 0xD0                   // mov     edx, eax
       , 0x48, 0x8B, 0xCB             // mov     rcx, rbx
       }
  }


// .text:00007FFCCE1EC315 E8 76 FD FF FF                          call    sqlcipherCodecAttach
// .text:00007FFCCE1EC31A 8B F8                                   mov     edi, eax
// .text:00007FFCCE1EC31C
// .text:00007FFCCE1EC31C                         loc_7FFCCE1EC31C:                       ; CODE XREF: sqlite3_key+68^j
// .text:00007FFCCE1EC31C 80 7B 69 00                             cmp     byte ptr [rbx+69h], 0
// .text:00007FFCCE1EC320 75 08                                   jnz     short loc_7FFCCE1EC32A
// .text:00007FFCCE1EC322 48 8B CB                                mov     rcx, rbx
// .text:00007FFCCE1EC325 E8 56 A6 F4 FF                          call    sub_7FFCCE136980
// .text:00007FFCCE1EC32A
// .text:00007FFCCE1EC32A                         loc_7FFCCE1EC32A:                       ; CODE XREF: sqlite3_key+80^j
// .text:00007FFCCE1EC32A 48 8B 4B 18                             mov     rcx, [rbx+18h]
// .text:00007FFCCE1EC32E 48 85 C9                                test    rcx, rcx
// .text:00007FFCCE1EC331 74 0D                                   jz      short loc_7FFCCE1EC340
// .text:00007FFCCE1EC333 48 8B 05 B6 BC 5C 00                    mov     rax, qword ptr cs:LeaveCriticalSectionAddr
// .text:00007FFCCE1EC33A FF 15 18 2F 42 00                       call    cs:__guard_dispatch_icall_fptr
// .text:00007FFCCE1EC340
// .text:00007FFCCE1EC340                         loc_7FFCCE1EC340:                       ; CODE XREF: sqlite3_key+91^j
// .text:00007FFCCE1EC340 8B C7                                   mov     eax, edi
// .text:00007FFCCE1EC342
// .text:00007FFCCE1EC342                         loc_7FFCCE1EC342:                       ; CODE XREF: sqlite3_key+2E^j
// .text:00007FFCCE1EC342 48 8B 5C 24 30                          mov     rbx, [rsp+28h+arg_0]
// .text:00007FFCCE1EC347 48 8B 6C 24 38                          mov     rbp, [rsp+28h+arg_8]
// .text:00007FFCCE1EC34C 48 8B 74 24 40                          mov     rsi, [rsp+28h+arg_10]
// .text:00007FFCCE1EC351 48 83 C4 20                             add     rsp, 20h
// .text:00007FFCCE1EC355 5F                                      pop     rdi
// .text:00007FFCCE1EC356 C3                                      retn
// .text:00007FFCCE1EC356                         sqlite3_key     endp



};
