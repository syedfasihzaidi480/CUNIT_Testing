#include "20F-1133_21F-9053_File_2_Function_1.h"

void be32enc_vect(unsigned char *dst, const uint32_t *src, size_t len) {
    size_t i;

    for (i = 0; i < len / 4; i++) {
        STORE32_BE(dst + i * 4, src[i]);
    }
}
