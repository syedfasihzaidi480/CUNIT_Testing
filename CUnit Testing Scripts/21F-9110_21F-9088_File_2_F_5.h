#ifndef CRYPTO_HASH_SHA256_INIT_H
#define CRYPTO_HASH_SHA256_INIT_H

#include <stdint.h>
#include <string.h>

// SHA-256 initial state constants
static const uint32_t sha256_initial_state[8] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

// Struct for SHA-256 state
typedef struct {
    uint64_t count;
    uint32_t state[8];
} crypto_hash_sha256_state;

// Function prototype
int crypto_hash_sha256_init(crypto_hash_sha256_state *state);

#endif
