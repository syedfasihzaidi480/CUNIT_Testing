#include "21F-9110_21F-9088_File_1_F_2.h"

#define crypto_auth_hmacsha256_KEYBYTES 32  // Assuming a predefined constant

size_t crypto_auth_hmacsha256_keybytes(void) {
    return crypto_auth_hmacsha256_KEYBYTES;
}
