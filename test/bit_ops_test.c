// AI GENERATED TEST BY GPT 5.2
#include <stdio.h>
#include "../include/bitwise.h"

static int tests_run = 0;
static int tests_failed = 0;

#define ASSERT_EQ(expected, actual)                           \
    do {                                                      \
        tests_run++;                                          \
        if ((expected) != (actual)) {                         \
            tests_failed++;                                   \
            printf("❌ Test failed at line %d\n", __LINE__);  \
            printf("   Expected: %d\n", (expected));          \
            printf("   Actual  : %d\n\n", (actual));          \
        }                                                     \
    } while (0)


static void test_set_bit() {
    ASSERT_EQ(5, set_bit(4, 0));   // 100 -> 101
    ASSERT_EQ(6, set_bit(4, 1));   // 100 -> 110
}

static void test_clear_bit() {
    ASSERT_EQ(4, clear_bit(5, 0)); // 101 -> 100
    ASSERT_EQ(0, clear_bit(1, 0)); // 001 -> 000
}

static void test_toggle_bit() {
    ASSERT_EQ(4, toggle_bit(5, 0)); // 101 -> 100
    ASSERT_EQ(5, toggle_bit(4, 0)); // 100 -> 101
}

static void test_check_bit() {
    ASSERT_EQ(1, check_bit(4, 2)); // 100 -> bit 2 = 1
    ASSERT_EQ(0, check_bit(4, 1)); // bit 1 = 0
}

static void test_update_bit() {
    ASSERT_EQ(5, update_bit(4, 0, 1)); // set
    ASSERT_EQ(4, update_bit(5, 0, 0)); // clear
}

static void test_swap_numbers() {
    int a = 3;
    int b = 5;
    swap_two_numbers_without_temp(&a, &b);
    ASSERT_EQ(5, a);
    ASSERT_EQ(3, b);
}

static void test_swap_bits() {
    // 1010 (10)
    ASSERT_EQ(6, swap_two_bits(10, 1, 2)); 
    // swapping bit1(1) and bit2(0) → 0110 (6)
}

int run_bit_ops_tests() {
    printf("Running bit_ops tests...\n\n");

    test_set_bit();
    test_clear_bit();
    test_toggle_bit();
    test_check_bit();
    test_update_bit();
    test_swap_numbers();
    test_swap_bits();

    printf("Tests run    : %d\n", tests_run);
    printf("Tests failed : %d\n", tests_failed);

    if (tests_failed == 0) {
        printf("\n✅ All tests passed!\n");
    }

    return tests_failed;
}
