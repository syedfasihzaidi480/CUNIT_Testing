#ifndef CRYPTO_AUTH_HMACSHA256_H
#define CRYPTO_AUTH_HMACSHA256_H

#include <stddef.h>

// Mock structure for SHA-256 state
typedef struct {
    unsigned char opaque[32]; // Placeholder for SHA-256 context
} crypto_hash_sha256_state;

typedef struct {
    crypto_hash_sha256_state ictx;
    crypto_hash_sha256_state octx;
} crypto_auth_hmacsha256_state;

// Function prototypes
int crypto_auth_hmacsha256_verify(const unsigned char *h, const unsigned char *in,
                                  unsigned long long inlen, const unsigned char *k);
int crypto_auth_hmacsha256(unsigned char *out, const unsigned char *in,
                           unsigned long long inlen, const unsigned char *k);
int crypto_verify_32(const unsigned char *a, const unsigned char *b);
int sodium_memcmp(const void *a, const void *b, size_t len);

#define crypto_auth_hmacsha256_KEYBYTES 32

#endif
