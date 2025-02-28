#include "21F-9110_21F-9088_File_1_F_4.h"
#include <stdlib.h> // For rand()

// Mock implementation of randombytes_buf for testing
void randombytes_buf(unsigned char *buf, size_t size) {
    for (size_t i = 0; i < size; i++) {
        buf[i] = (unsigned char)(rand() % 256); // Fill with random bytes
    }
}

void crypto_auth_hmacsha256_keygen(unsigned char k[crypto_auth_hmacsha256_KEYBYTES]) {
    randombytes_buf(k, crypto_auth_hmacsha256_KEYBYTES);
}
