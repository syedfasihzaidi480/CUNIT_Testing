#ifndef CRYPTO_HASH_SHA256_UPDATE_H
#define CRYPTO_HASH_SHA256_UPDATE_H

#include <stdint.h>
#include <string.h>

// Struct for SHA-256 state
typedef struct {
    uint64_t count;
    uint32_t state[8];
    unsigned char buf[64];
} crypto_hash_sha256_state;

// Function prototype
int crypto_hash_sha256_update(crypto_hash_sha256_state *state,
                              const unsigned char *in, unsigned long long inlen);

// External function used in the implementation
void SHA256_Transform(uint32_t state[8], const uint8_t block[64],
                      uint32_t W[64], uint32_t S[8]);

#endif
