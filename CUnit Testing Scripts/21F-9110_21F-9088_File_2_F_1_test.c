#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "20F-1133_21F-9053_File_2_Function_1.h"
#include <string.h> // For memcmp

// Test function for be32enc_vect
void test_be32enc_vect() {
    unsigned char output[8];
    uint32_t input[] = {0x11223344, 0xAABBCCDD};
    unsigned char expected[] = {
        0x11, 0x22, 0x33, 0x44,
        0xAA, 0xBB, 0xCC, 0xDD
    };

    // Run encoding function
    be32enc_vect(output, input, sizeof(input));

    // Verify output matches expected big-endian values
    CU_ASSERT(memcmp(output, expected, 8) == 0);

    // Edge case: Zero-length input
    unsigned char empty_output[4] = {0};
    be32enc_vect(empty_output, input, 0);
    CU_ASSERT(memcmp(empty_output, (unsigned char[4]){0}, 4) == 0);
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("BE32 Encoding Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "BE32 Encoding Test", test_be32enc_vect);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
