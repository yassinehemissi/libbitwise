// AI Generated Test 
#include <stdio.h>
#include <stdint.h>
#include "../include/bitwise.h"

static int tests_run = 0;
static int tests_failed = 0;

#define ASSERT_EQ(expected, actual)                           \
    do {                                                      \
        tests_run++;                                          \
        if ((expected) != (actual)) {                         \
            tests_failed++;                                   \
            printf("Test failed at line %d\n", __LINE__);     \
            printf("Expected: %u\n", (unsigned)(expected));   \
            printf("Actual  : %u\n\n", (unsigned)(actual));   \
        }                                                     \
    } while (0)

/* ============================= */
/* make_mask                     */
/* ============================= */
static void test_make_mask() {
    ASSERT_EQ(0u, make_mask(0, 0));
    ASSERT_EQ(1u, make_mask(0, 1));      /* 0001 */
    ASSERT_EQ(7u, make_mask(0, 3));      /* 0111 */
    ASSERT_EQ(28u, make_mask(2, 3));     /* 11100 */
    ASSERT_EQ(240u, make_mask(4, 4));    /* 11110000 */
}

/* ============================= */
/* extract_bits                  */
/* ============================= */
static void test_extract_bits() {
    /* n = 186 = 0b10111010 */
    ASSERT_EQ(0u, extract_bits(186u, 0, 0));
    ASSERT_EQ(0u, extract_bits(186u, 0, 1));  /* bit0 = 0 */
    ASSERT_EQ(1u, extract_bits(186u, 1, 1));  /* bit1 = 1 */
    ASSERT_EQ(1u, extract_bits(186u, 1, 2));  /* bits [2:1] = 01 -> 1 */
    ASSERT_EQ(7u, extract_bits(186u, 3, 3));  /* bits [5:3] = 111 -> 7 */

    /* n = 10 = 0b1010 */
    ASSERT_EQ(1u, extract_bits(10u, 1, 2));   /* bits [2:1] = 01 -> 1 */
    ASSERT_EQ(2u, extract_bits(10u, 2, 2));   /* bits [3:2] = 10 -> 2 */
}

/* ============================= */
/* clear_bits_range              */
/* ============================= */
static void test_clear_bits_range() {
    ASSERT_EQ(255u, clear_bits_range(255u, 0, 0));  /* no-op */
    ASSERT_EQ(254u, clear_bits_range(255u, 0, 1));  /* clear bit0 */
    ASSERT_EQ(227u, clear_bits_range(255u, 2, 3));  /* 11111111 -> 11100011 */
    ASSERT_EQ(15u,  clear_bits_range(255u, 4, 4));  /* 11111111 -> 00001111 */
}

/* ============================= */
/* set_bits_range                */
/* ============================= */
static void test_set_bits_range() {
    ASSERT_EQ(0u,   set_bits_range(0u, 0, 0));      /* no-op */
    ASSERT_EQ(1u,   set_bits_range(0u, 0, 1));      /* set bit0 */
    ASSERT_EQ(28u,  set_bits_range(0u, 2, 3));      /* set bits 2..4 */
    ASSERT_EQ(255u, set_bits_range(15u, 4, 4));     /* 00001111 -> 11111111 */
}

/* ============================= */
/* insert_bits                   */
/* ============================= */
static void test_insert_bits() {
    /* dest=160 (10100000), insert src low3 bits=111 into bits 2..4 => 10111100 (188) */
    ASSERT_EQ(188u, insert_bits(160u, 7u, 2, 3));

    ASSERT_EQ(0u, insert_bits(0u, 0u, 0, 0));       /* no-op */
    ASSERT_EQ(4u, insert_bits(0u, 1u, 2, 1));       /* insert 1 at bit2 -> 0100 */
    ASSERT_EQ(8u, insert_bits(0u, 2u, 2, 2));       /* insert 10 at bits 2..3 -> 1000 */
}

/* ============================= */
/* Runner                        */
/* ============================= */
int run_bit_masks_tests() {
    printf("Running bit_masks tests...\n\n");

    test_make_mask();
    test_extract_bits();
    test_clear_bits_range();
    test_set_bits_range();
    test_insert_bits();

    printf("Tests run    : %d\n", tests_run);
    printf("Tests failed : %d\n", tests_failed);

    if (tests_failed == 0) {
        printf("\nAll bit_masks tests passed.\n");
    }

    return tests_failed;
}

