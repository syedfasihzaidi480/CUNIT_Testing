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

int crypto_auth_hmacsha256_final(crypto_auth_hmacsha256_state *state, unsigned char *out);

// Mock function declarations for SHA-256 operations
void crypto_hash_sha256_final(crypto_hash_sha256_state *state, unsigned char *output);
void crypto_hash_sha256_update(crypto_hash_sha256_state *state, const unsigned char *input, size_t length);
void sodium_memzero(void *ptr, size_t len);

#endif
