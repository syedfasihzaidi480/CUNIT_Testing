#ifndef CRYPTO_HASH_SHA256_FINAL_H
#define CRYPTO_HASH_SHA256_FINAL_H

#include <stdint.h>
#include <string.h>

// Struct for SHA-256 state
typedef struct {
    uint64_t count;
    uint32_t state[8];
    unsigned char buf[64];
} crypto_hash_sha256_state;

// Function prototype
int crypto_hash_sha256_final(crypto_hash_sha256_state *state, unsigned char *out);

// External functions used in the implementation
void SHA256_Pad(crypto_hash_sha256_state *state, uint32_t tmp32[64 + 8]);
void be32enc_vect(unsigned char *dst, const uint32_t *src, size_t len);

#endif
