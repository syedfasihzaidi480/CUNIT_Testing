#ifndef CRYPTO_AUTH_HMACSHA256_H
#define CRYPTO_AUTH_HMACSHA256_H

#include <stddef.h>

#define crypto_auth_hmacsha256_KEYBYTES 32  // Assuming a predefined key size

void crypto_auth_hmacsha256_keygen(unsigned char k[crypto_auth_hmacsha256_KEYBYTES]);

// Mock function for randombytes_buf (assuming no real implementation available)
void randombytes_buf(unsigned char *buf, size_t size);

#endif
