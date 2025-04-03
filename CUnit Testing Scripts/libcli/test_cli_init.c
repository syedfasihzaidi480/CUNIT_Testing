/*
 * test_cli_init.c
 *
 *  Created on: 25 Feb 2025
 *      Author: alij7
 */


#include <CUnit/Basic.h>
#include "libcli.h"
#include <stdio.h>
#include <string.h>

void test_cli_init_success(void) {
    struct cli_def *cli = cli_init();
    CU_ASSERT_PTR_NOT_NULL(cli);
    cli_done(cli);
}

void test_cli_init_with_register_command(void) {
    struct cli_def *cli = cli_init();
    CU_ASSERT_PTR_NOT_NULL(cli);
    struct cli_command *cmd = cli_register_command(cli, NULL, "test", NULL, PRIVILEGE_UNPRIVILEGED, MODE_EXEC, "Test command");
    CU_ASSERT_PTR_NOT_NULL(cmd);
    cli_done(cli);
}

void test_cli_init_after_done(void) {
    struct cli_def *cli1 = cli_init();
    CU_ASSERT_PTR_NOT_NULL(cli1);
    cli_done(cli1);
    struct cli_def *cli2 = cli_init();
    CU_ASSERT_PTR_NOT_NULL(cli2);
    cli_done(cli2);
}

// New Test: CLI Filters
void test_cli_register_filter(void) {
    struct cli_def *cli = cli_init();
    CU_ASSERT_PTR_NOT_NULL(cli);
    struct cli_command *filter_cmd = cli_register_filter(cli, "filter_test", NULL, NULL, PRIVILEGE_UNPRIVILEGED, MODE_EXEC, "Test filter");
    CU_ASSERT_PTR_NOT_NULL(filter_cmd);
    cli_done(cli);
}

// New Test: Authentication Callback
int auth_callback(const char *username, const char *password) {
    return strcmp(username, "admin") == 0 && strcmp(password, "password") == 0;
}
void test_cli_set_auth_callback(void) {
    struct cli_def *cli = cli_init();
    CU_ASSERT_PTR_NOT_NULL(cli);
    cli_set_auth_callback(cli, auth_callback);
    CU_ASSERT(cli->auth_callback != NULL);
    cli_done(cli);
}

// New Test: Command Execution Output
int test_command_callback(struct cli_def *cli, const char *command, char **argv, int argc) {
    cli_print(cli, "Test Command Executed");
    return CLI_OK;
}
void test_cli_execute_command(void) {
    struct cli_def *cli = cli_init();
    CU_ASSERT_PTR_NOT_NULL(cli);
    cli_register_command(cli, NULL, "run_test", test_command_callback, PRIVILEGE_UNPRIVILEGED, MODE_EXEC, "Run test command");
    cli_print(cli, "Executing run_test");
    CU_ASSERT_EQUAL(test_command_callback(cli, "run_test", NULL, 0), CLI_OK);
    cli_done(cli);
}

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

int main() {
    CU_initialize_registry();
    CU_pSuite pSuite = CU_add_suite("Libcli Suite", init_suite, clean_suite);

    CU_add_test(pSuite, "test_cli_init_success", test_cli_init_success);
    CU_add_test(pSuite, "test_cli_init_with_register_command", test_cli_init_with_register_command);
    CU_add_test(pSuite, "test_cli_init_after_done", test_cli_init_after_done);
    CU_add_test(pSuite, "test_cli_register_filter", test_cli_register_filter);
    CU_add_test(pSuite, "test_cli_set_auth_callback", test_cli_set_auth_callback);
    CU_add_test(pSuite, "test_cli_execute_command", test_cli_execute_command);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
