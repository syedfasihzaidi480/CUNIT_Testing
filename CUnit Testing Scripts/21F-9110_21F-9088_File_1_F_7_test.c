#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "20F-1133_21F-9053_File_1_Function_7.h"
#include <string.h> // For memcmp

// Test function for crypto_auth_hmacsha256_final
void test_crypto_auth_hmacsha256_final() {
    crypto_auth_hmacsha256_state state;
    unsigned char output1[32];
    unsigned char output2[32];

    // Run HMAC-SHA256 finalization twice and check if the output is consistent
    CU_ASSERT(crypto_auth_hmacsha256_final(&state, output1) == 0);
    CU_ASSERT(crypto_auth_hmacsha256_final(&state, output2) == 0);

    // Verify that the output is not empty (mocked as nonzero values)
    int is_nonzero = 0;
    for (size_t i = 0; i < 32; i++) {
        if (output1[i] != 0) {
            is_nonzero = 1;
            break;
        }
    }
    CU_ASSERT(is_nonzero);

    // Ensure outputs are identical (since the state is not actually modified in the mock)
    CU_ASSERT(memcmp(output1, output2, 32) == 0);
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("HMAC-SHA256 Final Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "HMAC-SHA256 Final Test", test_crypto_auth_hmacsha256_final);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
