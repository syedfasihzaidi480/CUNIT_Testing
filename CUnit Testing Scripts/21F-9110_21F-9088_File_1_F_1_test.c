#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "20F-1133_21F-9053_File_1_Function_1.h"

// Test function for crypto_auth_hmacsha256_bytes
void test_crypto_auth_hmacsha256_bytes() {
    CU_ASSERT(crypto_auth_hmacsha256_bytes() == 32); // Assuming the expected return value
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("HMAC-SHA256 Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "HMAC-SHA256 Bytes Test", test_crypto_auth_hmacsha256_bytes);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
