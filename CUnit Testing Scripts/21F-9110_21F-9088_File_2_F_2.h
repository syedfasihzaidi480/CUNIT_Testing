#ifndef BE32DEC_VECT_H
#define BE32DEC_VECT_H

#include <stddef.h>
#include <stdint.h>

// Mock macro for big-endian loading
#define LOAD32_BE(src) (                    \
    ((uint32_t)(src)[0] << 24) |           \
    ((uint32_t)(src)[1] << 16) |           \
    ((uint32_t)(src)[2] << 8)  |           \
    ((uint32_t)(src)[3]))

// Function prototype
void be32dec_vect(uint32_t *dst, const unsigned char *src, size_t len);

#endif
