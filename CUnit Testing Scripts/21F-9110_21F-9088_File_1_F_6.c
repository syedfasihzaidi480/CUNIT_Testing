#include "21F-9110_21F-9088_File_1_F_6.h"

// Mock implementation of SHA-256 update function
void crypto_hash_sha256_update(crypto_hash_sha256_state *state, const unsigned char *input, size_t length) {
    // No real implementation, just a placeholder
}

int crypto_auth_hmacsha256_update(crypto_auth_hmacsha256_state *state,
                                  const unsigned char *in, unsigned long long inlen) {
    crypto_hash_sha256_update(&state->ictx, in, inlen);
    return 0;
}
