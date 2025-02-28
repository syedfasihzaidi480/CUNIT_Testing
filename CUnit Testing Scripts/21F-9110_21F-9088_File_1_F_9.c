#include "20F-1133_21F-9053_File_1_Function_9.h"
#include <string.h> // For memcmp

// Mock implementation of HMAC-SHA256 function
int crypto_auth_hmacsha256(unsigned char *out, const unsigned char *in,
                           unsigned long long inlen, const unsigned char *k) {
    memset(out, 0xAB, 32); // Mock output with dummy values
    return 0;
}

// Mock implementation of constant-time verification
int crypto_verify_32(const unsigned char *a, const unsigned char *b) {
    return memcmp(a, b, 32) == 0 ? 0 : -1;
}

// Mock implementation of sodium_memcmp
int sodium_memcmp(const void *a, const void *b, size_t len) {
    return memcmp(a, b, len);
}

int crypto_auth_hmacsha256_verify(const unsigned char *h, const unsigned char *in,
                                  unsigned long long inlen, const unsigned char *k) {
    unsigned char correct[32];

    crypto_auth_hmacsha256(correct, in, inlen, k);

    return crypto_verify_32(h, correct) | (-(h == correct)) |
           sodium_memcmp(correct, h, 32);
}
