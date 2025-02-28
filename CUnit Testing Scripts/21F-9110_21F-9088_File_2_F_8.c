#include "21F-9110_21F-9088_File_2_F_8.h"

int crypto_hash_sha256(unsigned char *out, const unsigned char *in, unsigned long long inlen) {
    crypto_hash_sha256_state state;

    crypto_hash_sha256_init(&state);
    crypto_hash_sha256_update(&state, in, inlen);
    crypto_hash_sha256_final(&state, out);

    return 0;
}
