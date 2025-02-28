#include "21F-9110_21F-9088_File_2_F_5.h"

int crypto_hash_sha256_init(crypto_hash_sha256_state *state) {
    static const uint32_t sha256_initial_state[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    state->count = (uint64_t) 0U;
    memcpy(state->state, sha256_initial_state, sizeof sha256_initial_state);

    return 0;
}
