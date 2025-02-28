#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "21F-9110_21F-9088_File_1_F_3.h"

// Test function for crypto_auth_hmacsha256_statebytes
void test_crypto_auth_hmacsha256_statebytes() {
    CU_ASSERT(crypto_auth_hmacsha256_statebytes() == sizeof(crypto_auth_hmacsha256_state));
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("HMAC-SHA256 State Bytes Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "HMAC-SHA256 State Bytes Test", test_crypto_auth_hmacsha256_statebytes);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
