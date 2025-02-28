#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "21F-9110_21F-9088_File_1_F_6.h"

// Test function for crypto_auth_hmacsha256_update
void test_crypto_auth_hmacsha256_update() {
    crypto_auth_hmacsha256_state state;
    unsigned char data1[] = "Test data";
    unsigned char data2[] = "";

    // Test with normal input
    CU_ASSERT(crypto_auth_hmacsha256_update(&state, data1, sizeof(data1) - 1) == 0);

    // Test with empty input
    CU_ASSERT(crypto_auth_hmacsha256_update(&state, data2, 0) == 0);

    // Test with large input
    unsigned char large_data[1024];
    CU_ASSERT(crypto_auth_hmacsha256_update(&state, large_data, sizeof(large_data)) == 0);
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("HMAC-SHA256 Update Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "HMAC-SHA256 Update Test", test_crypto_auth_hmacsha256_update);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
