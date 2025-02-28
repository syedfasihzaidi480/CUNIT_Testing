#ifndef CRYPTO_HASH_SHA256_H
#define CRYPTO_HASH_SHA256_H

#include <stdint.h>

// Struct for SHA-256 state
typedef struct {
    uint64_t count;
    uint32_t state[8];
    unsigned char buf[64];
} crypto_hash_sha256_state;

// Function prototype
int crypto_hash_sha256(unsigned char *out, const unsigned char *in, unsigned long long inlen);

// External function prototypes
int crypto_hash_sha256_init(crypto_hash_sha256_state *state);
int crypto_hash_sha256_update(crypto_hash_sha256_state *state, const unsigned char *in, unsigned long long inlen);
int crypto_hash_sha256_final(crypto_hash_sha256_state *state, unsigned char *out);

#endif
