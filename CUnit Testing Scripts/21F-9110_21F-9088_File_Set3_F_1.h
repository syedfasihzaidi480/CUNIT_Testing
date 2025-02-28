#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "20F-1133_21F-9053_File_Set3_Function_1.h"

// Test for cli_init()
void test_cli_init() {
    struct cli_def *cli = cli_init();
    CU_ASSERT_PTR_NOT_NULL(cli);
    CU_ASSERT_PTR_NOT_NULL(cli->buffer);
    CU_ASSERT_EQUAL(cli->buf_size, 1024);
    CU_ASSERT_EQUAL(cli->telnet_protocol, 1);
    CU_ASSERT_EQUAL(cli->timeout_tm.tv_sec, 1);
    CU_ASSERT_EQUAL(cli->timeout_tm.tv_usec, 0);

    cli_done(cli); // Clean up
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("CLI Initialization Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "CLI Init Test", test_cli_init);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
