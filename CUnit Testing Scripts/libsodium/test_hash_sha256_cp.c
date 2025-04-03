/*
 * test_hash_sha256_cp.c
 *
 *  Created on: 23 Feb 2025
 *      Author: alij7
 */


//#include <CUnit/CUnit.h>
//#include <CUnit/Basic.h>
//#include <stdint.h>
//#include <string.h>
//#include "hash_sha256_cp.h"
//
//// Test SHA256 initialization
//void test_sha256_init(void) {
//    crypto_hash_sha256_state state;
//    CU_ASSERT_EQUAL(crypto_hash_sha256_init(&state), 0);
//}
//
//// Test SHA256 update with sample data
//void test_sha256_update(void) {
//    crypto_hash_sha256_state state;
//    unsigned char input[] = "test data";
//    CU_ASSERT_EQUAL(crypto_hash_sha256_init(&state), 0);
//    CU_ASSERT_EQUAL(crypto_hash_sha256_update(&state, input, strlen((char*)input)), 0);
//}
//
//// Test SHA256 final computation
//void test_sha256_final(void) {
//    crypto_hash_sha256_state state;
//    unsigned char output[32];
//    CU_ASSERT_EQUAL(crypto_hash_sha256_init(&state), 0);
//    CU_ASSERT_EQUAL(crypto_hash_sha256_final(&state, output), 0);
//}
//
//// Test full SHA256 hash computation
//void test_sha256_full(void) {
//    unsigned char input[] = "hello world";
//    unsigned char output[32];
//    CU_ASSERT_EQUAL(crypto_hash_sha256(output, input, strlen((char*)input)), 0);
//}
//
//int main() {
//    CU_initialize_registry();
//    CU_pSuite suite = CU_add_suite("SHA-256 Tests", NULL, NULL);
//
//    CU_add_test(suite, "SHA256 Init", test_sha256_init);
//    CU_add_test(suite, "SHA256 Update", test_sha256_update);
//    CU_add_test(suite, "SHA256 Final", test_sha256_final);
//    CU_add_test(suite, "SHA256 Full Hash", test_sha256_full);
//
//    CU_basic_set_mode(CU_BRM_VERBOSE);
//    CU_basic_run_tests();
//    CU_cleanup_registry();
//    return 0;
//}
