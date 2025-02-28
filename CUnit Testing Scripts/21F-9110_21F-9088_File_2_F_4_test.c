#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "21F-9110_21F-9088_File_2_F_4.h"
#include <string.h>

// Mock function for SHA256_Transform
void SHA256_Transform(uint32_t state[8], const uint8_t block[64], uint32_t W[64], uint32_t S[8]) {
    for (int i = 0; i < 8; i++) {
        state[i] += i;  // Dummy transformation for testing
    }
}

// Test function for SHA256_Pad
void test_SHA256_Pad() {
    crypto_hash_sha256_state state;
    uint32_t tmp32[64 + 8] = {0};

    memset(&state, 0, sizeof(state));
    state.count = 440;  // Example bit count (55 bytes)

    SHA256_Pad(&state, tmp32);

    // Ensure padding byte 0x80 is present
    CU_ASSERT(state.buf[55] == 0x80);

    // Ensure last 8 bytes contain count in big-endian format
    uint8_t expected_length[8] = {0, 0, 0, 0, 0, 0, 1, 184}; // 440 bits = 0x00000000000001B8
    CU_ASSERT(memcmp(&state.buf[56], expected_length, 8) == 0);

    // Ensure SHA256_Transform was called by checking if state was modified
    CU_ASSERT(state.state[0] != 0);
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("SHA256 Padding Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "SHA256 Padding Test", test_SHA256_Pad);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
