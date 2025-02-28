#ifndef SHA256_PAD_H
#define SHA256_PAD_H

#include <stddef.h>
#include <stdint.h>
#include <string.h>

// Mock macro for acquiring fence (normally used for memory barriers)
#define ACQUIRE_FENCE ((void)0)

// Mock macro for big-endian storage of 64-bit integers
#define STORE64_BE(dst, val)                     \
    do {                                         \
        (dst)[0] = (uint8_t)((val) >> 56);       \
        (dst)[1] = (uint8_t)((val) >> 48);       \
        (dst)[2] = (uint8_t)((val) >> 40);       \
        (dst)[3] = (uint8_t)((val) >> 32);       \
        (dst)[4] = (uint8_t)((val) >> 24);       \
        (dst)[5] = (uint8_t)((val) >> 16);       \
        (dst)[6] = (uint8_t)((val) >> 8);        \
        (dst)[7] = (uint8_t)((val));             \
    } while (0)

// Mock padding array (actual values should be 0x80 followed by 0x00 bytes)
static const uint8_t PAD[64] = {0x80, 0};

// Mock struct for SHA-256 state
typedef struct {
    uint64_t count;
    uint8_t buf[64];
    uint32_t state[8];
} crypto_hash_sha256_state;

// Function prototypes
void SHA256_Transform(uint32_t state[8], const uint8_t block[64], uint32_t W[64], uint32_t S[8]);
void SHA256_Pad(crypto_hash_sha256_state *state, uint32_t tmp32[64 + 8]);

#endif
