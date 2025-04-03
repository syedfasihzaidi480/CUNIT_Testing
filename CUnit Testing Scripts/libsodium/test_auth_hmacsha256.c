/*
 * test_auth_hmacsha256.c
 *
 *  Created on: 23 Feb 2025
 *      Author: alij7
 */


//#include <CUnit/CUnit.h>
//#include <CUnit/Basic.h>
//#include <string.h>
//#include "crypto_auth_hmacsha256.h"
//
//// Test cases for constant functions
//void test_bytes(void) {
//    CU_ASSERT(crypto_auth_hmacsha256_bytes() == 32);
//}
//
//void test_keybytes(void) {
//    CU_ASSERT(crypto_auth_hmacsha256_keybytes() == 32);
//}
//
//void test_statebytes(void) {
//    CU_ASSERT(crypto_auth_hmacsha256_statebytes() == sizeof(crypto_auth_hmacsha256_state));
//}
//
//// Test key generation
//void test_keygen(void) {
//    unsigned char k1[32], k2[32];
//    crypto_auth_hmacsha256_keygen(k1);
//    crypto_auth_hmacsha256_keygen(k2);
//    CU_ASSERT(memcmp(k1, k2, 32) != 0);
//}
//
//// Test HMAC verification against completely different HMAC
//void test_hmac_verification(void) {
//    unsigned char key[32] = {0};
//    unsigned char data1[] = "Message 1";
//    unsigned char data2[] = "Message 2";
//    unsigned char hmac1[32], hmac2[32];
//
//    crypto_auth_hmacsha256(hmac1, data1, strlen((char*)data1), key);
//    crypto_auth_hmacsha256(hmac2, data2, strlen((char*)data2), key);
//
//    CU_ASSERT(crypto_auth_hmacsha256_verify(hmac1, data1, strlen((char*)data1), key) == 0);
//    CU_ASSERT(crypto_auth_hmacsha256_verify(hmac2, data1, strlen((char*)data1), key) != 0);
//}
//
//// Test streaming API with distinct inputs
//void test_streaming_api(void) {
//    unsigned char key[32] = {0};
//    const char *msg1 = "Part 1 of message";
//    const char *msg2 = "Part 2 of message";
//    unsigned char hmac_single[32], hmac_stream[32];
//    crypto_auth_hmacsha256_state state;
//
//    crypto_auth_hmacsha256(hmac_single, (const unsigned char*)msg1, strlen(msg1), key);
//    crypto_auth_hmacsha256_init(&state, key, 32);
//    crypto_auth_hmacsha256_update(&state, (const unsigned char*)msg1, strlen(msg1));
//    crypto_auth_hmacsha256_update(&state, (const unsigned char*)msg2, strlen(msg2));
//    crypto_auth_hmacsha256_final(&state, hmac_stream);
//
//    CU_ASSERT(memcmp(hmac_single, hmac_stream, 32) != 0);
//}
//
//// Test key length impact on HMAC output
//void test_long_key(void) {
//    unsigned char short_key[32];
//    unsigned char long_key[80];
//    unsigned char data[] = "Key length test";
//    unsigned char hmac_short[32], hmac_long[32];
//
//    memset(short_key, 0xaa, 32);
//    memset(long_key, 0xaa, 80);
//
//    crypto_auth_hmacsha256(hmac_short, data, sizeof(data)-1, short_key);
//    crypto_auth_hmacsha256(hmac_long, data, sizeof(data)-1, long_key);
//
//    CU_ASSERT(memcmp(hmac_short, hmac_long, 32) != 0);
//}
//
//int main() {
//    CU_initialize_registry();
//    CU_pSuite suite = CU_add_suite("HMAC-SHA256 Tests", NULL, NULL);
//
//    CU_add_test(suite, "crypto_auth_hmacsha256_bytes", test_bytes);
//    CU_add_test(suite, "crypto_auth_hmacsha256_keybytes", test_keybytes);
//    CU_add_test(suite, "crypto_auth_hmacsha256_statebytes", test_statebytes);
//    CU_add_test(suite, "crypto_auth_hmacsha256_keygen", test_keygen);
//    CU_add_test(suite, "HMAC Verification", test_hmac_verification);
//    CU_add_test(suite, "Streaming API", test_streaming_api);
//    CU_add_test(suite, "Key Length Impact", test_long_key);
//
//    CU_basic_set_mode(CU_BRM_VERBOSE);
//    CU_basic_run_tests();
//    CU_cleanup_registry();
//    return 0;
//}
