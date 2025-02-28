#ifndef SHA256_TRANSFORM_H
#define SHA256_TRANSFORM_H

#include <stddef.h>
#include <stdint.h>
#include <string.h>

// Function prototypes
void be32dec_vect(uint32_t *dst, const unsigned char *src, size_t len);
void SHA256_Transform(uint32_t state[8], const uint8_t block[64], uint32_t W[64], uint32_t S[8]);

// Mock definitions for RNDr and MSCH
#define RNDr(S, W, j, i) (S[j] += W[i + j])  // Simplified mock operation
#define MSCH(W, j, i) (W[i + j] ^= W[i])     // Simplified mock operation

#endif
