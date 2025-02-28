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
int crypto_auth_hmacsha256(unsigned char *out, const unsigned char *in,
                           unsigned long long inlen, const unsigned char *k);
int crypto_auth_hmacsha256_init(crypto_auth_hmacsha256_state *state,
                                const unsigned char *key, size_t keylen);
int crypto_auth_hmacsha256_update(crypto_auth_hmacsha256_state *state,
                                  const unsigned char *in, unsigned long long inlen);
int crypto_auth_hmacsha256_final(crypto_auth_hmacsha256_state *state, unsigned char *out);

#define crypto_auth_hmacsha256_KEYBYTES 32

#endif
