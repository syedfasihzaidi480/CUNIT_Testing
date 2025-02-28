#include "21F-9110_21F-9088_File_2_F_1.h"

void be32enc_vect(unsigned char *dst, const uint32_t *src, size_t len) {
    size_t i;

    for (i = 0; i < len / 4; i++) {
        STORE32_BE(dst + i * 4, src[i]);
    }
}
