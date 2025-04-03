/*
 * test_crc32.c
 *
 *  Created on: 25 Feb 2025
 *      Author: alij7
 */


//#include <CUnit/CUnit.h>
//#include <CUnit/Basic.h>
//#include <stdio.h>
//#include <stdint.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <unistd.h>
//#include <string.h>
//
//extern uint32_t crc32_total;
//extern int crc32(int fd, uint32_t *cval, uint32_t *clen);
//
//// Setup function with correct signature for CUnit
//int setup(void) {
//    crc32_total = 0;
//    return 0;  // Return 0 for success
//}
//
//// Test empty file
//void test_crc32_empty_file(void) {
//    FILE *tmp = tmpfile();
//    CU_ASSERT_PTR_NOT_NULL_FATAL(tmp);
//
//    uint32_t cval, clen;
//    int fd = fileno(tmp);
//    int result = crc32(fd, &cval, &clen);
//    fclose(tmp);
//
//    CU_ASSERT_EQUAL(result, 0);
//    CU_ASSERT_EQUAL(clen, 0);
//    CU_ASSERT_EQUAL(cval, 0);
//}
//
//// Test known CRC value for "123456789"
//void test_crc32_known_value(void) {
//    FILE *tmp = tmpfile();
//    CU_ASSERT_PTR_NOT_NULL_FATAL(tmp);
//    const char *data = "123456789";
//    size_t len = strlen(data);
//    fwrite(data, 1, len, tmp);
//    rewind(tmp);
//
//    uint32_t cval, clen;
//    int fd = fileno(tmp);
//    int result = crc32(fd, &cval, &clen);
//    fclose(tmp);
//
//    CU_ASSERT_EQUAL(result, 0);
//    CU_ASSERT_EQUAL(clen, len);
//    CU_ASSERT_EQUAL(cval, 0xCBF43926);  // Precomputed CRC-32 value
//}
//
//// Test single character 'A'
//void test_crc32_single_character(void) {
//    FILE *tmp = tmpfile();
//    CU_ASSERT_PTR_NOT_NULL_FATAL(tmp);
//    char ch = 'A';
//    fwrite(&ch, 1, 1, tmp);
//    rewind(tmp);
//
//    uint32_t cval, clen;
//    int fd = fileno(tmp);
//    int result = crc32(fd, &cval, &clen);
//    fclose(tmp);
//
//    CU_ASSERT_EQUAL(result, 0);
//    CU_ASSERT_EQUAL(clen, 1);
//    CU_ASSERT_EQUAL(cval, 0x2C1D85FD);  // Precomputed CRC-32 value for 'A'
//}
//
//// Test accumulation across multiple files
//void test_crc32_total_accumulation(void) {
//    FILE *tmp1 = tmpfile();
//    FILE *tmp2 = tmpfile();
//    CU_ASSERT_PTR_NOT_NULL_FATAL(tmp1);
//    CU_ASSERT_PTR_NOT_NULL_FATAL(tmp2);
//
//    const char *data1 = "Hello";
//    const char *data2 = "World";
//    size_t len1 = strlen(data1);
//    size_t len2 = strlen(data2);
//    fwrite(data1, 1, len1, tmp1);
//    rewind(tmp1);
//    fwrite(data2, 1, len2, tmp2);
//    rewind(tmp2);
//
//    uint32_t cval1, clen1, cval2, clen2;
//    int fd1 = fileno(tmp1);
//    int result1 = crc32(fd1, &cval1, &clen1);
//    fclose(tmp1);
//
//    int fd2 = fileno(tmp2);
//    int result2 = crc32(fd2, &cval2, &clen2);
//    fclose(tmp2);
//
//    CU_ASSERT_EQUAL(result1, 0);
//    CU_ASSERT_EQUAL(result2, 0);
//
//    // Compute expected CRC of "HelloWorld"
//    FILE *tmp_combined = tmpfile();
//    const char *combined = "HelloWorld";
//    size_t combined_len = strlen(combined);
//    fwrite(combined, 1, combined_len, tmp_combined);
//    rewind(tmp_combined);
//    uint32_t expected_crc, expected_len;
//    int fd_combined = fileno(tmp_combined);
//    int result_combined = crc32(fd_combined, &expected_crc, &expected_len);
//    fclose(tmp_combined);
//
//    CU_ASSERT_EQUAL(result_combined, 0);
//    CU_ASSERT_EQUAL(crc32_total, expected_crc);
//}
//
//// Test read error handling
//void test_crc32_read_error(void) {
//    uint32_t cval, clen;
//    int fd = -1;  // Invalid file descriptor
//    int result = crc32(fd, &cval, &clen);
//    CU_ASSERT_EQUAL(result, 1);
//}
//
//int main() {
//    CU_pSuite suite = NULL;
//
//    // Initialize CUnit registry
//    if (CU_initialize_registry() != CUE_SUCCESS)
//        return CU_get_error();
//
//    // Add a suite to the registry
//    suite = CU_add_suite("CRC32 Test Suite", setup, NULL);
//    if (!suite) {
//        CU_cleanup_registry();
//        return CU_get_error();
//    }
//
//    // Add tests to the suite
//    if (
//        !CU_add_test(suite, "test empty file", test_crc32_empty_file) ||
//        !CU_add_test(suite, "test known value", test_crc32_known_value) ||
//        !CU_add_test(suite, "test single character", test_crc32_single_character) ||
//        !CU_add_test(suite, "test total accumulation", test_crc32_total_accumulation) ||
//        !CU_add_test(suite, "test read error", test_crc32_read_error)
//    ) {
//        CU_cleanup_registry();
//        return CU_get_error();
//    }
//
//    // Run all tests in verbose mode
//    CU_basic_set_mode(CU_BRM_VERBOSE);
//    CU_basic_run_tests();
//
//    // Clean up and exit
//    CU_cleanup_registry();
//    return CU_get_error();
//}

