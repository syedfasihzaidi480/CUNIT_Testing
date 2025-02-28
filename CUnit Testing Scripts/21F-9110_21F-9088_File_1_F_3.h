#ifndef CRYPTO_AUTH_HMACSHA256_H
#define CRYPTO_AUTH_HMACSHA256_H

#include <stddef.h>

typedef struct {
    unsigned char opaque[64]; // Assuming a placeholder structure size
} crypto_auth_hmacsha256_state;

size_t crypto_auth_hmacsha256_statebytes(void);

#endif
