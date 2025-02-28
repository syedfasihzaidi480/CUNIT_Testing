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

int crypto_auth_hmacsha256_update(crypto_auth_hmacsha256_state *state,
                                  const unsigned char *in, unsigned long long inlen);

// Mock function declarations for SHA-256 operations
void crypto_hash_sha256_update(crypto_hash_sha256_state *state, const unsigned char *input, size_t length);

#endif
