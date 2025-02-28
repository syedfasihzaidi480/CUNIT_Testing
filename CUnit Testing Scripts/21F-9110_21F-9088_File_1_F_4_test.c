#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "20F-1133_21F-9053_File_1_Function_4.h"
#include <string.h> // For memcmp

// Test function for crypto_auth_hmacsha256_keygen
void test_crypto_auth_hmacsha256_keygen() {
    unsigned char key1[crypto_auth_hmacsha256_KEYBYTES] = {0};
    unsigned char key2[crypto_auth_hmacsha256_KEYBYTES] = {0};

    crypto_auth_hmacsha256_keygen(key1);
    crypto_auth_hmacsha256_keygen(key2);

    // Check that the keys are not all zeros (meaning they were generated)
    int is_nonzero = 0;
    for (size_t i = 0; i < crypto_auth_hmacsha256_KEYBYTES; i++) {
        if (key1[i] != 0) {
            is_nonzero = 1;
            break;
        }
    }
    CU_ASSERT(is_nonzero);

    // Ensure that two successive calls produce different keys (not always guaranteed but likely)
    CU_ASSERT(memcmp(key1, key2, crypto_auth_hmacsha256_KEYBYTES) != 0);
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("HMAC-SHA256 Key Generation Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "HMAC-SHA256 Key Generation Test", test_crypto_auth_hmacsha256_keygen);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
