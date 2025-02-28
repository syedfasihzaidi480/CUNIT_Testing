#include "21F-9110_21F-9088_File_3_F_1.h"
#include <unistd.h>   // for read()
#include <stdio.h>    // for BUFSIZ
#include <stdint.h>   // for uint32_t

#define CRC(crc, byte) (crc = (crc >> 8) ^ crc_table[(crc ^ (byte)) & 0xFF])

static uint32_t crc32_total = 0;
static uint32_t crc_table[256] = { /* Precomputed CRC32 Table (not shown for brevity) */ };

int crc32(int fd, uint32_t *cval, uint32_t *clen) {
    uint32_t crc = ~0;
    char buf[BUFSIZ], *p;
    int len = 0, nr;

    crc32_total = ~crc32_total;
    while ((nr = read(fd, buf, sizeof(buf))) > 0) {
        for (len += nr, p = buf; nr--; ++p) {
            CRC(crc, *p);
            CRC(crc32_total, *p);
        }
    }
    if (nr < 0) {
        return 1; // Error reading file
    }

    *clen = len;
    *cval = ~crc;
    crc32_total = ~crc32_total;
    return 0;
}
