#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "20F-1133_21F-9053_File_2_Function_2.h"
#include <string.h> // For memcmp

// Test function for be32dec_vect
void test_be32dec_vect() {
    unsigned char input[] = {
        0x11, 0x22, 0x33, 0x44,
        0xAA, 0xBB, 0xCC, 0xDD
    };
    uint32_t output[2] = {0};
    uint32_t expected[] = {0x11223344, 0xAABBCCDD};

    // Run decoding function
    be32dec_vect(output, input, sizeof(input));

    // Verify output matches expected decoded values
    CU_ASSERT(memcmp(output, expected, sizeof(expected)) == 0);

    // Edge case: Zero-length input
    uint32_t empty_output[2] = {0};
    be32dec_vect(empty_output, input, 0);
    CU_ASSERT(memcmp(empty_output, (uint32_t[2]){0}, sizeof(empty_output)) == 0);
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("BE32 Decoding Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "BE32 Decoding Test", test_be32dec_vect);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
