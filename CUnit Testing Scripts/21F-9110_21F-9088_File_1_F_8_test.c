#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "20F-1133_21F-9053_File_1_Function_8.h"
#include <string.h> // For memcmp

// Test function for crypto_auth_hmacsha256
void test_crypto_auth_hmacsha256() {
    unsigned char output1[32];
    unsigned char output2[32];
    unsigned char key[crypto_auth_hmacsha256_KEYBYTES] = {0xAB}; // Sample key
    unsigned char message[] = "Test Message";

    // Run HMAC-SHA256 function and check if it returns success
    CU_ASSERT(crypto_auth_hmacsha256(output1, message, sizeof(message) - 1, key) == 0);

    // Run it again with the same input and check if the output is consistent
    CU_ASSERT(crypto_auth_hmacsha256(output2, message, sizeof(message) - 1, key) == 0);
    CU_ASSERT(memcmp(output1, output2, 32) == 0);

    // Test with an empty input
    unsigned char empty_message[] = "";
    CU_ASSERT(crypto_auth_hmacsha256(output1, empty_message, 0, key) == 0);

    // Test with a long input
    unsigned char long_message[1024];
    memset(long_message, 0xCD, sizeof(long_message));
    CU_ASSERT(crypto_auth_hmacsha256(output1, long_message, sizeof(long_message), key) == 0);
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("HMAC-SHA256 Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "HMAC-SHA256 Test", test_crypto_auth_hmacsha256);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
