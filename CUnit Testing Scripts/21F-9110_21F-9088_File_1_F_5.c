#include "20F-1133_21F-9053_File_1_Function_5.h"

// Mock implementations for SHA-256 functions
void crypto_hash_sha256_init(crypto_hash_sha256_state *state) {
    memset(state->opaque, 0, sizeof(state->opaque));
}

void crypto_hash_sha256_update(crypto_hash_sha256_state *state, const unsigned char *input, size_t length) {
    // Mock update function - no real implementation
}

void crypto_hash_sha256_final(crypto_hash_sha256_state *state, unsigned char *output) {
    memset(output, 0, 32); // Mock output
}

void sodium_memzero(void *ptr, size_t len) {
    memset(ptr, 0, len);
}

int crypto_auth_hmacsha256_init(crypto_auth_hmacsha256_state *state,
                                const unsigned char *key, size_t keylen) {
    unsigned char pad[64];
    unsigned char khash[32];
    size_t        i;

    if (keylen > 64) {
        crypto_hash_sha256_init(&state->ictx);
        crypto_hash_sha256_update(&state->ictx, key, keylen);
        crypto_hash_sha256_final(&state->ictx, khash);
        key    = khash;
        keylen = 32;
    }

    crypto_hash_sha256_init(&state->ictx);
    memset(pad, 0x36, 64);
    for (i = 0; i < keylen; i++) {
        pad[i] ^= key[i];
    }
    crypto_hash_sha256_update(&state->ictx, pad, 64);

    crypto_hash_sha256_init(&state->octx);
    memset(pad, 0x5c, 64);
    for (i = 0; i < keylen; i++) {
        pad[i] ^= key[i];
    }
    crypto_hash_sha256_update(&state->octx, pad, 64);

    sodium_memzero(pad, sizeof pad);
    sodium_memzero(khash, sizeof khash);

    return 0;
}
