#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "20F-1133_21F-9053_File_1_Function_9.h"
#include <string.h> // For memset

// Test function for crypto_auth_hmacsha256_verify
void test_crypto_auth_hmacsha256_verify() {
    unsigned char key[crypto_auth_hmacsha256_KEYBYTES] = {0xAB}; // Sample key
    unsigned char message[] = "Test Message";
    unsigned char correct_hmac[32];
    unsigned char incorrect_hmac[32] = {0xCD}; // Incorrect HMAC

    // Generate correct HMAC
    crypto_auth_hmacsha256(correct_hmac, message, sizeof(message) - 1, key);

    // Test verification with correct HMAC
    CU_ASSERT(crypto_auth_hmacsha256_verify(correct_hmac, message, sizeof(message) - 1, key) == 0);

    // Test verification with incorrect HMAC
    CU_ASSERT(crypto_auth_hmacsha256_verify(incorrect_hmac, message, sizeof(message) - 1, key) != 0);

    // Test with empty message
    unsigned char empty_message[] = "";
    unsigned char empty_hmac[32];
    crypto_auth_hmacsha256(empty_hmac, empty_message, 0, key);
    CU_ASSERT(crypto_auth_hmacsha256_verify(empty_hmac, empty_message, 0, key) == 0);
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("HMAC-SHA256 Verify Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "HMAC-SHA256 Verify Test", test_crypto_auth_hmacsha256_verify);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
