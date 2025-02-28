#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "20F-1133_21F-9053_File_1_Function_5.h"
#include <string.h> // For memcmp

// Test function for crypto_auth_hmacsha256_init
void test_crypto_auth_hmacsha256_init() {
    crypto_auth_hmacsha256_state state;
    unsigned char key[64] = {0xAB}; // Sample key with a fixed byte pattern

    // Test with a short key
    CU_ASSERT(crypto_auth_hmacsha256_init(&state, key, 32) == 0);

    // Test with a long key (exceeding 64 bytes)
    unsigned char long_key[100];
    memset(long_key, 0xCD, sizeof(long_key));
    CU_ASSERT(crypto_auth_hmacsha256_init(&state, long_key, sizeof(long_key)) == 0);

    // Test with an empty key
    unsigned char empty_key[1] = {0};
    CU_ASSERT(crypto_auth_hmacsha256_init(&state, empty_key, 0) == 0);
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("HMAC-SHA256 Init Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "HMAC-SHA256 Init Test", test_crypto_auth_hmacsha256_init);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
