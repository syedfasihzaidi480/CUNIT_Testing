#include "20F-1133_21F-9053_File_1_Function_7.h"
#include <string.h> // For memset

// Mock implementation of SHA-256 final function
void crypto_hash_sha256_final(crypto_hash_sha256_state *state, unsigned char *output) {
    memset(output, 0xAB, 32); // Mock output with dummy data
}

// Mock implementation of SHA-256 update function
void crypto_hash_sha256_update(crypto_hash_sha256_state *state, const unsigned char *input, size_t length) {
    // No real implementation, just a placeholder
}

// Mock implementation of sodium_memzero
void sodium_memzero(void *ptr, size_t len) {
    memset(ptr, 0, len);
}

int crypto_auth_hmacsha256_final(crypto_auth_hmacsha256_state *state, unsigned char *out) {
    unsigned char ihash[32];

    crypto_hash_sha256_final(&state->ictx, ihash);
    crypto_hash_sha256_update(&state->octx, ihash, 32);
    crypto_hash_sha256_final(&state->octx, out);

    sodium_memzero(ihash, sizeof ihash);

    return 0;
}
