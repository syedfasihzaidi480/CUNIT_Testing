#include "21F-9110_21F-9088_File_Set3_F_1.h"

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

// Test case for cli_init()
void test_cli_init() {
    struct cli_def *cli = cli_init();

    CU_ASSERT_PTR_NOT_NULL(cli);
    CU_ASSERT_PTR_NOT_NULL(cli->buffer);
    CU_ASSERT_EQUAL(cli->buf_size, 1024);
    CU_ASSERT_EQUAL(cli->telnet_protocol, 1);

    cli_done(cli);
}

// Setup and run CUnit tests
int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("CLI Init Suite", 0, 0);
    CU_add_test(suite, "CLI Initialization Test", test_cli_init);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
