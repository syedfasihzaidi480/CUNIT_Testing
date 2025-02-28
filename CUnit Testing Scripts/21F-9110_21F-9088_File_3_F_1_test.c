#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <fcntl.h>   // for open()
#include <unistd.h>  // for close()
#include "21F-9110_21F-9088_File_3_F_1.h"

// Test function for crc32
void test_crc32() {
    int fd = open("test_file.txt", O_RDONLY);
    CU_ASSERT(fd >= 0);

    uint32_t cval, clen;
    int result = crc32(fd, &cval, &clen);

    CU_ASSERT(result == 0);
    CU_ASSERT(clen > 0); // File should have some content
    CU_ASSERT(cval != 0); // CRC value should be computed

    close(fd);
}

// Setup and run CUnit tests
int main() {
    // Initialize CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("CRC32 Suite", 0, 0);

    // Add test cases
    CU_add_test(suite, "CRC32 Test", test_crc32);

    // Run tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Cleanup registry
    CU_cleanup_registry();
    return 0;
}
