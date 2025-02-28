#ifndef CRYPTO_AUTH_HMACSHA256_H
#define CRYPTO_AUTH_HMACSHA256_H

#include <stddef.h>
#include <string.h> // For memset

// Mock structure definitions for hashing contexts
typedef struct {
    unsigned char opaque[32]; // Placeholder for SHA-256 context
} crypto_hash_sha256_state;

typedef struct {
    crypto_hash_sha256_state ictx;
    crypto_hash_sha256_state octx;
} crypto_auth_hmacsha256_state;

int crypto_auth_hmacsha256_init(crypto_auth_hmacsha256_state *state,
                                const unsigned char *key, size_t keylen);

// Mock function declarations for hashing
void crypto_hash_sha256_init(crypto_hash_sha256_state *state);
void crypto_hash_sha256_update(crypto_hash_sha256_state *state, const unsigned char *input, size_t length);
void crypto_hash_sha256_final(crypto_hash_sha256_state *state, unsigned char *output);
void sodium_memzero(void *ptr, size_t len);

#endif
