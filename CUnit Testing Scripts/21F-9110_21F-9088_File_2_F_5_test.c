#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "21F-9110_21F-9088_File_2_F_5.h"

// Test function for crypto_hash_sha256_init
void test_crypto_hash_sha256_init() {
    crypto_hash_sha256_state state;

    // Initialize state
    int result = crypto_hash_sha256_init(&state);

    // Verify return value is 0
    CU_ASSERT(result == 0);

    // Verify count is initialized to 0
    CU_ASSERT(state.count == 0U);

    // Verify state is correctly initialized
    CU_ASSERT(memcmp(state.state, sha256_initial_state, sizeof(sha256_initial_state)) == 0);
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("SHA256 Init Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "SHA256 Init Test", test_crypto_hash_sha256_init);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
