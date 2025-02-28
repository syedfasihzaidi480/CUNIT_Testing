#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "21F-9110_21F-9088_File_2_F_6.h"

// Mock SHA256_Transform function
void SHA256_Transform(uint32_t state[8], const uint8_t block[64],
                      uint32_t W[64], uint32_t S[8]) {
    // This is a placeholder function for testing.
}

// Test function for crypto_hash_sha256_update
void test_crypto_hash_sha256_update() {
    crypto_hash_sha256_state state;
    unsigned char input1[32] = {0x61};  // 32-byte input (smaller than 64)
    unsigned char input2[128] = {0x62}; // 128-byte input (larger than 64)

    // Initialize the state
    memset(&state, 0, sizeof(state));

    // Test with input size < 64
    int result1 = crypto_hash_sha256_update(&state, input1, 32);
    CU_ASSERT(result1 == 0);
    CU_ASSERT(state.count == (32 * 8)); // Count should be updated

    // Test with input size > 64
    int result2 = crypto_hash_sha256_update(&state, input2, 128);
    CU_ASSERT(result2 == 0);
    CU_ASSERT(state.count == (160 * 8)); // Count should be updated correctly
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("SHA256 Update Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "SHA256 Update Test", test_crypto_hash_sha256_update);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
