// AI Generated Test 
#include <stdio.h>
#include <stdint.h>
#include "../include/bitwise.h"

static int tests_passed = 0;
static int tests_failed = 0;

#define ASSERT_EQ(actual, expected)                                      \
    do {                                                                  \
        if ((actual) != (expected)) {                                     \
            printf("❌ FAIL: %s:%d | Expected %d, got %d\n",              \
                   __FILE__, __LINE__, (expected), (actual));             \
            tests_failed++;                                                \
        } else {                                                           \
            tests_passed++;                                                \
        }                                                                  \
    } while (0)


int run_bit_scan_test() {

    /* =========================
       Zero Edge Cases
       ========================= */
    ASSERT_EQ(ctz32(0), 32);      // Convention: 32 for zero
    ASSERT_EQ(clz32(0), 32);
    ASSERT_EQ(ffs32(0), -1);
    ASSERT_EQ(fls32(0), -1);

    /* =========================
       Single Bit Cases
       ========================= */
    ASSERT_EQ(ctz32(1), 0);
    ASSERT_EQ(clz32(1), 31);
    ASSERT_EQ(ffs32(1), 0);
    ASSERT_EQ(fls32(1), 0);

    ASSERT_EQ(ctz32(2), 1);
    ASSERT_EQ(clz32(2), 30);
    ASSERT_EQ(ffs32(2), 1);
    ASSERT_EQ(fls32(2), 1);

    ASSERT_EQ(ctz32(0x80000000), 31);
    ASSERT_EQ(clz32(0x80000000), 0);
    ASSERT_EQ(ffs32(0x80000000), 31);
    ASSERT_EQ(fls32(0x80000000), 31);

    /* =========================
       Multi-bit Patterns
       ========================= */
    ASSERT_EQ(ctz32(0b101000), 3);
    ASSERT_EQ(clz32(0b101000), 26);
    ASSERT_EQ(ffs32(0b101000), 3);
    ASSERT_EQ(fls32(0b101000), 5);

    ASSERT_EQ(ctz32(0x00F00000), 20);
    ASSERT_EQ(clz32(0x00F00000), 8);
    ASSERT_EQ(ffs32(0x00F00000), 20);
    ASSERT_EQ(fls32(0x00F00000), 23);

    ASSERT_EQ(ctz32(0xFFFFFFFF), 0);
    ASSERT_EQ(clz32(0xFFFFFFFF), 0);
    ASSERT_EQ(ffs32(0xFFFFFFFF), 0);
    ASSERT_EQ(fls32(0xFFFFFFFF), 31);

    /* =========================
       Summary
       ========================= */
    printf("\nBit Scan Tests:\n");
    printf("Passed: %d\n", tests_passed);
    printf("Failed: %d\n", tests_failed);

    return tests_failed == 0;
}
