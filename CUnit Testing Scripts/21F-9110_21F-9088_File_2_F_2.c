#include "21F-9110_21F-9088_File_2_F_2.h"

void be32dec_vect(uint32_t *dst, const unsigned char *src, size_t len) {
    size_t i;

    for (i = 0; i < len / 4; i++) {
        dst[i] = LOAD32_BE(src + i * 4);
    }
}
