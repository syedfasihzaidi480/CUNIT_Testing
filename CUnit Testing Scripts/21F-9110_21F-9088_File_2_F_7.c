#include "20F-1133_21F-9053_File_2_Function_7.h"

int crypto_hash_sha256_final(crypto_hash_sha256_state *state, unsigned char *out) {
    uint32_t tmp32[64 + 8];

    SHA256_Pad(state, tmp32);
    be32enc_vect(out, state->state, 32);

    memset(tmp32, 0, sizeof tmp32);
    memset(state, 0, sizeof *state);

    return 0;
}
