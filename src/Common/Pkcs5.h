/*
 Legal Notice: Some portions of the source code contained in this file were
 derived from the source code of TrueCrypt 7.1a, which is
 Copyright (c) 2003-2012 TrueCrypt Developers Association and which is
 governed by the TrueCrypt License 3.0, also from the source code of
 Encryption for the Masses 2.02a, which is Copyright (c) 1998-2000 Paul Le Roux
 and which is governed by the 'License Agreement for Encryption for the Masses'
 Modifications and additions to the original source code (contained in this file)
 and all other portions of this file are Copyright (c) 2013-2017 IDRIX
 and are governed by the Apache License 2.0 the full text of which is
 contained in the file License.txt included in VeraCrypt binary and source
 code distribution packages. */

#ifndef TC_HEADER_PKCS5
#define TC_HEADER_PKCS5

#include "Tcdefs.h"

#if defined(__cplusplus)
extern "C"
{
#endif
/* output written to input_digest which must be at lease 32 bytes long */
void hmac_blake2s (char *key, int keylen, char *input_digest, int len);
void derive_key_blake2s (char *pwd, int pwd_len, char *salt, int salt_len, uint32 iterations, char *dk, int dklen);

/* output written to input_digest which must be at lease 64 bytes long */
void hmac_blake512 (char *key, int keylen, char *input_digest, int len);
void derive_key_blake512 (char *pwd, int pwd_len, char *salt, int salt_len, uint32 iterations, char *dk, int dklen);

/* output written to d which must be at lease 32 bytes long */
void hmac_sha256 (char *k, int lk, char *d, int ld);
void derive_key_sha256 (char *pwd, int pwd_len, char *salt, int salt_len, uint32 iterations, char *dk, int dklen);

#ifndef TC_WINDOWS_BOOT
/* output written to d which must be at lease 64 bytes long */
void hmac_sha512 (char *k, int lk, char *d, int ld);
void derive_key_sha512 (char *pwd, int pwd_len, char *salt, int salt_len, uint32 iterations, char *dk, int dklen);

/* output written to d which must be at lease 64 bytes long */
void hmac_whirlpool (char *k, int lk, char *d, int ld);
void derive_key_whirlpool (char *pwd, int pwd_len, char *salt, int salt_len, uint32 iterations, char *dk, int dklen);

void hmac_streebog (char *k, int32 lk, char *d, int32 ld);
void derive_key_streebog (char *pwd, int pwd_len, char *salt, int salt_len, uint32 iterations, char *dk, int dklen);

int get_pkcs5_iteration_count (int pkcs5_prf_id, int pim, BOOL bBoot);
wchar_t *get_pkcs5_prf_name (int pkcs5_prf_id);

/* check if given PRF supported.*/
typedef enum
{
   PRF_BOOT_NO = 0,
   PRF_BOOT_MBR,
   PRF_BOOT_GPT
} PRF_BOOT_TYPE;

int is_pkcs5_prf_supported (int pkcs5_prf_id, PRF_BOOT_TYPE bootType);
#endif

#if defined(__cplusplus)
}
#endif

#endif // TC_HEADER_PKCS5
