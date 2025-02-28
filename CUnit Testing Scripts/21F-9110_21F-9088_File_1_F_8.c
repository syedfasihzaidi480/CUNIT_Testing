#include "21F-9110_21F-9088_File_1_F_8.h"
#include <string.h> // For memset

// Mock implementations of related functions
int crypto_auth_hmacsha256_init(crypto_auth_hmacsha256_state *state,
                                const unsigned char *key, size_t keylen) {
    // Mock initialization
    memset(state, 0, sizeof(crypto_auth_hmacsha256_state));
    return 0;
}

int crypto_auth_hmacsha256_update(crypto_auth_hmacsha256_state *state,
                                  const unsigned char *in, unsigned long long inlen) {
    // Mock update function
    return 0;
}

int crypto_auth_hmacsha256_final(crypto_auth_hmacsha256_state *state, unsigned char *out) {
    memset(out, 0xAB, 32); // Mock output with dummy values
    return 0;
}

int crypto_auth_hmacsha256(unsigned char *out, const unsigned char *in,
                           unsigned long long inlen, const unsigned char *k) {
    crypto_auth_hmacsha256_state state;

    crypto_auth_hmacsha256_init(&state, k, crypto_auth_hmacsha256_KEYBYTES);
    crypto_auth_hmacsha256_update(&state, in, inlen);
    crypto_auth_hmacsha256_final(&state, out);

    return 0;
}
