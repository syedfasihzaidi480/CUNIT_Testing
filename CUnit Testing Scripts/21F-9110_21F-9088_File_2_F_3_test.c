#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "20F-1133_21F-9053_File_2_Function_3.h"
#include <string.h> // For memcmp

// Mock function for be32dec_vect
void be32dec_vect(uint32_t *dst, const unsigned char *src, size_t len) {
    for (size_t i = 0; i < len / 4; i++) {
        dst[i] = (src[i * 4] << 24) | (src[i * 4 + 1] << 16) | (src[i * 4 + 2] << 8) | src[i * 4 + 3];
    }
}

// Test function for SHA256_Transform
void test_SHA256_Transform() {
    uint32_t state[8] = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
                         0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};

    uint8_t block[64] = {0};  // Mock input data
    uint32_t W[64] = {0};
    uint32_t S[8] = {0};

    // Run transformation
    SHA256_Transform(state, block, W, S);

    // Validate state is modified
    CU_ASSERT(state[0] != 0x6a09e667);
    CU_ASSERT(state[1] != 0xbb67ae85);
    CU_ASSERT(state[2] != 0x3c6ef372);
    CU_ASSERT(state[3] != 0xa54ff53a);
    CU_ASSERT(state[4] != 0x510e527f);
    CU_ASSERT(state[5] != 0x9b05688c);
    CU_ASSERT(state[6] != 0x1f83d9ab);
    CU_ASSERT(state[7] != 0x5be0cd19);
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("SHA256 Transform Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "SHA256 Transform Test", test_SHA256_Transform);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
