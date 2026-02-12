// AI GENERATED TEST 
#include <stdio.h>
#include "../include/bitwise.h"

static int tests_run = 0;
static int tests_failed = 0;

#define ASSERT_EQ(expected, actual)                           \
    do {                                                      \
        tests_run++;                                          \
        if ((expected) != (actual)) {                         \
            tests_failed++;                                   \
            printf("Test failed at line %d\n", __LINE__);     \
            printf("Expected: %d\n", (expected));             \
            printf("Actual  : %d\n\n", (actual));             \
        }                                                     \
    } while (0)


/* ============================= */
/* count_set_bits (naive)       */
/* ============================= */

static void test_count_set_bits() {
    ASSERT_EQ(0, count_set_bits(0));
    ASSERT_EQ(1, count_set_bits(1));
    ASSERT_EQ(2, count_set_bits(3));     // 11
    ASSERT_EQ(2, count_set_bits(10));    // 1010
    ASSERT_EQ(4, count_set_bits(15));    // 1111
}

/* ============================= */
/* is_power_of_two              */
/* ============================= */

static void test_is_power_of_two() {
    ASSERT_EQ(0, is_power_of_two(0));
    ASSERT_EQ(1, is_power_of_two(1));
    ASSERT_EQ(1, is_power_of_two(2));
    ASSERT_EQ(0, is_power_of_two(3));
    ASSERT_EQ(1, is_power_of_two(8));
    ASSERT_EQ(0, is_power_of_two(10));
}


/* ============================= */
/* lowest_set_bit               */
/* ============================= */
/* Assumes function returns mask (n & -n) */

static void test_lowest_set_bit() {
    ASSERT_EQ(0, lowest_set_bit(0));
    ASSERT_EQ(1, lowest_set_bit(1));      // 0001
    ASSERT_EQ(2, lowest_set_bit(10));     // 1010 -> 0010
    ASSERT_EQ(4, lowest_set_bit(12));     // 1100 -> 0100
}


/* ============================= */
/* highest_set_bit              */
/* ============================= */
/* Assumes function returns mask */

static void test_highest_set_bit() {
    ASSERT_EQ(0, highest_set_bit(0));
    ASSERT_EQ(1, highest_set_bit(1));
    ASSERT_EQ(8, highest_set_bit(10));    // 1010 -> 1000
    ASSERT_EQ(8, highest_set_bit(12));    // 1100 -> 1000
}


/* ============================= */
/* parity                       */
/* ============================= */

static void test_parity() {
    ASSERT_EQ(0, parity(0));      // 0 bits
    ASSERT_EQ(1, parity(1));      // 1 bit
    ASSERT_EQ(0, parity(3));      // 11 -> 2 bits
    ASSERT_EQ(1, parity(7));      // 111 -> 3 bits
    ASSERT_EQ(0, parity(10));     // 1010 -> 2 bits
}


/* ============================= */
/* Runner                       */
/* ============================= */

int run_bit_count_tests() {
    printf("Running bit_count tests...\n\n");

    test_count_set_bits();
    test_is_power_of_two();
    test_lowest_set_bit();
    test_highest_set_bit();
    test_parity();

    printf("Tests run    : %d\n", tests_run);
    printf("Tests failed : %d\n", tests_failed);

    if (tests_failed == 0) {
        printf("\nAll bit_count tests passed.\n");
    }

    return tests_failed;
}
