static
std::vector<SignaturePiece> code_signature_sqlite3_open

 = buildSignatureFromIdaSignatureString
 (
 /* .text:00007FFCCE138910 */  "40 53 "                                //  push    rbx
 /* .text:00007FFCCE138912 */  "55 "                                   //  push    rbp
 /* .text:00007FFCCE138913 */  "56 "                                   //  push    rsi
 /* .text:00007FFCCE138914 */  "57 "                                   //  push    rdi
 /* .text:00007FFCCE138915 */  "41 54 "                                //  push    r12
 /* .text:00007FFCCE138917 */  "41 55 "                                //  push    r13
 /* .text:00007FFCCE138919 */  "41 56 "                                //  push    r14
 /* .text:00007FFCCE13891B */  "41 57 "                                //  push    r15
 /* .text:00007FFCCE13891D */  "48 81 EC F8 00 00 00 "                 //  sub     rsp, 0F8h
 /* .text:00007FFCCE138924 *//* 48 8B 05 6D 43 67 00 */                //  mov     rax, cs:__security_cookie
                               "?  ?  ?  ?  ?  ?  ? "
 /* .text:00007FFCCE13892B */  "48 33 C4 "                             //  xor     rax, rsp
 /* .text:00007FFCCE13892E */  "48 89 84 24 E0 00 00 00 "              //  mov     [rsp+138h+var_58], rax
 /* .text:00007FFCCE138936 */  "44 8B A4 24 68 01 00 00 "              //  mov     r12d, [rsp+138h+arg_28]
 /* .text:00007FFCCE13893E */  "33 C0 "                                //  xor     eax, eax
 /* .text:00007FFCCE138940 */  "45 33 FF "                             //  xor     r15d, r15d
 /* .text:00007FFCCE138943 */  "4C 89 4C 24 48 "                       //  mov     [rsp+138h+var_F0], r9
 /* .text:00007FFCCE138948 */  "4C 89 44 24 58 "                       //  mov     [rsp+138h+var_E0], r8
 /* .text:00007FFCCE13894D */  "48 8B EA "                             //  mov     rbp, rdx
 /* .text:00007FFCCE138950 */  "48 89 4C 24 60 "                       //  mov     [rsp+138h+var_D8], rcx
 /* .text:00007FFCCE138955 */  "48 8B F1 "                             //  mov     rsi, rcx
 /* .text:00007FFCCE138958 */  "48 89 44 24 50 "                       //  mov     [rsp+138h+var_E8], rax
 /* .text:00007FFCCE13895D */  "48 85 D2 "                             //  test    rdx, rdx
 /* .text:00007FFCCE138960 */  "74 08 "                                //  jz      short loc_7FFCCE13896A
 /* .text:00007FFCCE138962 */  "38 02 "                                //  cmp     [rdx], al
 /* .text:00007FFCCE138964 */  "74 04 "                                //  jz      short loc_7FFCCE13896A
 /* .text:00007FFCCE138966 */  "33 DB "                                //  xor     ebx, ebx
 /* .text:00007FFCCE138968 */  "EB 0A "                                //  jmp     short loc_7FFCCE138974
 /* .text:00007FFCCE13896A */                          //; ---------------------------------------------------------------------------
 /* .text:00007FFCCE13896A */ 
 /* .text:00007FFCCE13896A */                          //loc_7FFCCE13896A:                       ; CODE XREF: sqlite3_open+50^j
 /* .text:00007FFCCE13896A */                          //                                        ; sqlite3_open+54^j
 /* .text:00007FFCCE13896A */  "BB 01 00 00 00 "                       //  mov     ebx, 1
 /* .text:00007FFCCE13896F */  "48 85 ED "                             //  test    rbp, rbp
 /* .text:00007FFCCE138972 */  "74 29 "                                //  jz      short loc_7FFCCE13899D
 /* .text:00007FFCCE138974 */ 
#if 0
 /* .text:00007FFCCE138974 */                          //loc_7FFCCE138974:                       ; CODE XREF: sqlite3_open+58^j
 /* .text:00007FFCCE138974 */  48 8D 15 AD EE 5D 00                  //  lea     rdx, aMemory    ; ":memory:"
 /* .text:00007FFCCE13897B */  48 8B CD                              //  mov     rcx, rbp        ; Str1
 /* .text:00007FFCCE13897E */  E8 DD 60 3E 00                        //  call    strcmp
 /* .text:00007FFCCE138983 */  85 C0                                 //  test    eax, eax
 /* .text:00007FFCCE138985 */  74 16                                 //  jz      short loc_7FFCCE13899D
 /* .text:00007FFCCE138987 */  85 DB                                 //  test    ebx, ebx
 /* .text:00007FFCCE138989 */  75 12                                 //  jnz     short loc_7FFCCE13899D
 /* .text:00007FFCCE13898B */  45 84 E4                              //  test    r12b, r12b
 /* .text:00007FFCCE13898E */  78 0D                                 //  js      short loc_7FFCCE13899D
 /* .text:00007FFCCE138990 */  44 8B AC 24 60 01 00 00               //  mov     r13d, [rsp+138h+arg_20]
 /* .text:00007FFCCE138998 */  45 33 F6                              //  xor     r14d, r14d
 /* .text:00007FFCCE13899B */  EB 12                                 //  jmp     short loc_7FFCCE1389AF
 /* .text:00007FFCCE13899D */                          //; ---------------------------------------------------------------------------
 /* .text:00007FFCCE13899D */ 
 /* .text:00007FFCCE13899D */                          //loc_7FFCCE13899D:                       ; CODE XREF: sqlite3_open+62^j
 /* .text:00007FFCCE13899D */                          //                                        ; sqlite3_open+75^j ...
 /* .text:00007FFCCE13899D */  44 8B AC 24 60 01 00 00               //  mov     r13d, [rsp+138h+arg_20]
 /* .text:00007FFCCE1389A5 */  41 BE 01 00 00 00                     //  mov     r14d, 1
 /* .text:00007FFCCE1389AB */  41 83 CD 02                           //  or      r13d, 2
 /* .text:00007FFCCE1389AF */ 
 /* .text:00007FFCCE1389AF */                          //loc_7FFCCE1389AF:                       ; CODE XREF: sqlite3_open+8B^j
 /* .text:00007FFCCE1389AF */  44 89 74 24 40                        //  mov     [rsp+138h+var_F8], r14d
 /* .text:00007FFCCE1389B4 */  41 0F BA E4 08                        //  bt      r12d, 8
 /* .text:00007FFCCE1389B9 */  73 13                                 //  jnb     short loc_7FFCCE1389CE
 /* .text:00007FFCCE1389BB */  45 85 F6                              //  test    r14d, r14d
 /* .text:00007FFCCE1389BE */  75 04                                 //  jnz     short loc_7FFCCE1389C4
 /* .text:00007FFCCE1389C0 */  85 DB                                 //  test    ebx, ebx
 /* .text:00007FFCCE1389C2 */  74 0A                                 //  jz      short loc_7FFCCE1389CE
 /* .text:00007FFCCE1389C4 */ 
 /* .text:00007FFCCE1389C4 */                          //loc_7FFCCE1389C4:                       ; CODE XREF: sqlite3_open+AE^j
 /* .text:00007FFCCE1389C4 */  41 0F BA F4 08                        //  btr     r12d, 8
 /* .text:00007FFCCE1389C9 */  41 0F BA EC 09                        //  bts     r12d, 9
 /* .text:00007FFCCE1389CE */ 
 /* .text:00007FFCCE1389CE */                          //loc_7FFCCE1389CE:                       ; CODE XREF: sqlite3_open+A9^j
 /* .text:00007FFCCE1389CE */                          //                                        ; sqlite3_open+B2^j
 /* .text:00007FFCCE1389CE */  B9 48 00 00 00                        //  mov     ecx, 48h ; 'H'
 /* .text:00007FFCCE1389D3 */  E8 A8 8E FE FF                        //  call    sub_7FFCCE121880
 /* .text:00007FFCCE1389D8 */  48 8B F8                              //  mov     rdi, rax
 /* .text:00007FFCCE1389DB */  48 85 C0                              //  test    rax, rax
 /* .text:00007FFCCE1389DE */  0F 84 99 00 00 00                     //  jz      loc_7FFCCE138A7D
 /* .text:00007FFCCE1389E4 */  0F 57 C0                              //  xorps   xmm0, xmm0
 /* .text:00007FFCCE1389E7 */  33 C0                                 //  xor     eax, eax
 /* .text:00007FFCCE1389E9 */  0F 11 07                              //  movups  xmmword ptr [rdi], xmm0
 /* .text:00007FFCCE1389EC */  0F 11 47 10                           //  movups  xmmword ptr [rdi+10h], xmm0
 /* .text:00007FFCCE1389F0 */  0F 11 47 20                           //  movups  xmmword ptr [rdi+20h], xmm0
 /* .text:00007FFCCE1389F4 */  0F 11 47 30                           //  movups  xmmword ptr [rdi+30h], xmm0
 /* .text:00007FFCCE1389F8 */  48 89 47 40                           //  mov     [rdi+40h], rax
 /* .text:00007FFCCE1389FC */  48 8B 44 24 58                        //  mov     rax, [rsp+138h+var_E0]
 /* .text:00007FFCCE138A01 */  48 89 07                              //  mov     [rdi], rax
 /* .text:00007FFCCE138A04 */  48 89 7F 30                           //  mov     [rdi+30h], rdi
 /* .text:00007FFCCE138A08 */  C7 47 38 01 00 00 00                  //  mov     dword ptr [rdi+38h], 1
 /* .text:00007FFCCE138A0F */  85 DB                                 //  test    ebx, ebx
 /* .text:00007FFCCE138A11 */  0F 85 27 02 00 00                     //  jnz     loc_7FFCCE138C3E
 /* .text:00007FFCCE138A17 */  45 85 F6                              //  test    r14d, r14d
 /* .text:00007FFCCE138A1A */  74 0A                                 //  jz      short loc_7FFCCE138A26
 /* .text:00007FFCCE138A1C */  41 F6 C4 40                           //  test    r12b, 40h
 /* .text:00007FFCCE138A20 */  0F 84 18 02 00 00                     //  jz      loc_7FFCCE138C3E
 /* .text:00007FFCCE138A26 */ 
 /* .text:00007FFCCE138A26 */                          //loc_7FFCCE138A26:                       ; CODE XREF: sqlite3_open+10A^j
 /* .text:00007FFCCE138A26 */  41 0F BA E4 11                        //  bt      r12d, 11h
 /* .text:00007FFCCE138A2B */  0F 83 0D 02 00 00                     //  jnb     loc_7FFCCE138C3E
 /* .text:00007FFCCE138A31 */  48 85 ED                              //  test    rbp, rbp
 /* .text:00007FFCCE138A34 */  75 04                                 //  jnz     short loc_7FFCCE138A3A
 /* .text:00007FFCCE138A36 */  33 C9                                 //  xor     ecx, ecx
 /* .text:00007FFCCE138A38 */  EB 16                                 //  jmp     short loc_7FFCCE138A50
 /* .text:00007FFCCE138A3A */                          //; ---------------------------------------------------------------------------
 /* .text:00007FFCCE138A3A */ 
 /* .text:00007FFCCE138A3A */                          //loc_7FFCCE138A3A:                       ; CODE XREF: sqlite3_open+124^j
 /* .text:00007FFCCE138A3A */  48 C7 C1 FF FF FF FF                  //  mov     rcx, 0FFFFFFFFFFFFFFFFh
 /* .text:00007FFCCE138A41 */ 
 /* .text:00007FFCCE138A41 */                          //loc_7FFCCE138A41:                       ; CODE XREF: sqlite3_open+138vj
 /* .text:00007FFCCE138A41 */  48 FF C1                              //  inc     rcx
 /* .text:00007FFCCE138A44 */  44 38 3C 29                           //  cmp     [rcx+rbp], r15b
 /* .text:00007FFCCE138A48 */  75 F7                                 //  jnz     short loc_7FFCCE138A41
 /* .text:00007FFCCE138A4A */  81 E1 FF FF FF 3F                     //  and     ecx, 3FFFFFFFh
 /* .text:00007FFCCE138A50 */ 
 /* .text:00007FFCCE138A50 */                          //loc_7FFCCE138A50:                       ; CODE XREF: sqlite3_open+128^j
 /* .text:00007FFCCE138A50 */  8B 46 08                              //  mov     eax, [rsi+8]
 /* .text:00007FFCCE138A53 */  8D 59 01                              //  lea     ebx, [rcx+1]
 /* .text:00007FFCCE138A56 */  8D 70 01                              //  lea     esi, [rax+1]
 /* .text:00007FFCCE138A59 */  3B F3                                 //  cmp     esi, ebx
 /* .text:00007FFCCE138A5B */  0F 4F C8                              //  cmovg   ecx, eax
 /* .text:00007FFCCE138A5E */  48 63 C9                              //  movsxd  rcx, ecx
 /* .text:00007FFCCE138A61 */  48 FF C1                              //  inc     rcx
 /* .text:00007FFCCE138A64 */  E8 17 8E FE FF                        //  call    sub_7FFCCE121880
 /* .text:00007FFCCE138A69 */  C6 47 11 01                           //  mov     byte ptr [rdi+11h], 1
 /* .text:00007FFCCE138A6D */  4C 8B F0                              //  mov     r14, rax
 /* .text:00007FFCCE138A70 */  48 85 C0                              //  test    rax, rax
 /* .text:00007FFCCE138A73 */  75 31                                 //  jnz     short loc_7FFCCE138AA6
 /* .text:00007FFCCE138A75 */  48 8B CF                              //  mov     rcx, rdi
 /* .text:00007FFCCE138A78 */  E8 A3 8E FE FF                        //  call    sub_7FFCCE121920
 /* .text:00007FFCCE138A7D */ 
 /* .text:00007FFCCE138A7D */                          //loc_7FFCCE138A7D:                       ; CODE XREF: sqlite3_open+CE^j
 /* .text:00007FFCCE138A7D */  B8 07 00 00 00                        //  mov     eax, 7
 /* .text:00007FFCCE138A82 */ 
 /* .text:00007FFCCE138A82 */                          //loc_7FFCCE138A82:                       ; CODE XREF: sqlite3_open+203vj
 /* .text:00007FFCCE138A82 */                          //                                        ; sqlite3_open+527vj ...
 /* .text:00007FFCCE138A82 */  48 8B 8C 24 E0 00 00 00               //  mov     rcx, [rsp+138h+var_58]
 /* .text:00007FFCCE138A8A */  48 33 CC                              //  xor     rcx, rsp
 /* .text:00007FFCCE138A8D */  E8 EE 4F 3E 00                        //  call    RORifROL8
 /* .text:00007FFCCE138A92 */  48 81 C4 F8 00 00 00                  //  add     rsp, 0F8h
 /* .text:00007FFCCE138A99 */  41 5F                                 //  pop     r15
 /* .text:00007FFCCE138A9B */  41 5E                                 //  pop     r14
 /* .text:00007FFCCE138A9D */  41 5D                                 //  pop     r13
 /* .text:00007FFCCE138A9F */  41 5C                                 //  pop     r12
 /* .text:00007FFCCE138AA1 */  5F                                    //  pop     rdi
 /* .text:00007FFCCE138AA2 */  5E                                    //  pop     rsi
 /* .text:00007FFCCE138AA3 */  5D                                    //  pop     rbp
 /* .text:00007FFCCE138AA4 */  5B                                    //  pop     rbx
 /* .text:00007FFCCE138AA5 */  C3                                    //  retn
#endif
 );