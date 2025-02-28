#ifndef BE32ENC_VECT_H
#define BE32ENC_VECT_H

#include <stddef.h>
#include <stdint.h>

// Mock macro for big-endian storage
#define STORE32_BE(dst, val)             \
    do {                                 \
        (dst)[0] = (unsigned char)((val) >> 24); \
        (dst)[1] = (unsigned char)((val) >> 16); \
        (dst)[2] = (unsigned char)((val) >> 8);  \
        (dst)[3] = (unsigned char)(val);         \
    } while (0)

// Function prototype
void be32enc_vect(unsigned char *dst, const uint32_t *src, size_t len);

#endif
