#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "21F-9110_21F-9088_File_2_F_7.h"

// Mock SHA256_Pad function
void SHA256_Pad(crypto_hash_sha256_state *state, uint32_t tmp32[64 + 8]) {
    // Placeholder function for testing
}

// Mock be32enc_vect function
void be32enc_vect(unsigned char *dst, const uint32_t *src, size_t len) {
    // Simulate copying the state data into output
    for (size_t i = 0; i < len / 4; i++) {
        dst[i] = (unsigned char) src[i]; // Simple byte assignment for test purposes
    }
}

// Test function for crypto_hash_sha256_final
void test_crypto_hash_sha256_final() {
    crypto_hash_sha256_state state;
    unsigned char out[32];

    // Initialize state with sample data
    memset(&state, 0xA5, sizeof(state));

    // Call the function
    int result = crypto_hash_sha256_final(&state, out);

    // Validate output
    CU_ASSERT(result == 0);
    CU_ASSERT(state.count == 0);  // Ensure state is zeroed
    for (int i = 0; i < 8; i++) {
        CU_ASSERT(state.state[i] == 0);
    }
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("SHA256 Final Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "SHA256 Final Test", test_crypto_hash_sha256_final);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
