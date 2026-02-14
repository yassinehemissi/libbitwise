// AI Generated Test 
#include <stdio.h>
#include <stdint.h>
#include "../include/bitwise.h"

static int tests_run = 0;
static int tests_failed = 0;

#define ASSERT_EQ_HEX(expected, actual)                              \
    do {                                                             \
        tests_run++;                                                 \
        uint32_t _e = (uint32_t)(expected);                           \
        uint32_t _a = (uint32_t)(actual);                             \
        if (_e != _a) {                                              \
            tests_failed++;                                          \
            printf("Test failed at line %d\n", __LINE__);            \
            printf("Expected: 0x%08X\n", _e);                        \
            printf("Actual  : 0x%08X\n\n", _a);                      \
        }                                                            \
    } while (0)


/* ============================= */
/* rotl32 / rotr32               */
/* ============================= */

static void test_rotations_basic() {
    ASSERT_EQ_HEX(0x00000000u, rotl32(0x00000000u, 0));
    ASSERT_EQ_HEX(0x00000001u, rotl32(0x00000001u, 0));
    ASSERT_EQ_HEX(0x00000001u, rotl32(0x00000001u, 32));
    ASSERT_EQ_HEX(0x00000002u, rotl32(0x00000001u, 1));
    ASSERT_EQ_HEX(0x00000004u, rotl32(0x00000001u, 2));
    ASSERT_EQ_HEX(0x80000000u, rotl32(0x00000001u, 31));

    ASSERT_EQ_HEX(0x00000001u, rotr32(0x00000001u, 0));
    ASSERT_EQ_HEX(0x00000001u, rotr32(0x00000001u, 32));
    ASSERT_EQ_HEX(0x80000000u, rotr32(0x00000001u, 1));
    ASSERT_EQ_HEX(0x40000000u, rotr32(0x00000001u, 2));
    ASSERT_EQ_HEX(0x00000002u, rotr32(0x00000004u, 1));
}

static void test_rotations_wraparound() {
    ASSERT_EQ_HEX(0x00000001u, rotl32(0x80000000u, 1));  /* MSB wraps to LSB */
    ASSERT_EQ_HEX(0x80000000u, rotr32(0x00000001u, 1));  /* LSB wraps to MSB */

    ASSERT_EQ_HEX(0x00000001u, rotl32(0x00000001u, 64)); /* 64 -> 0 */
    ASSERT_EQ_HEX(0x00000002u, rotl32(0x00000001u, 33)); /* 33 -> 1 */

    ASSERT_EQ_HEX(0x00000001u, rotr32(0x00000001u, 64)); /* 64 -> 0 */
    ASSERT_EQ_HEX(0x80000000u, rotr32(0x00000001u, 33)); /* 33 -> 1 */

    /* Known value checks */
    ASSERT_EQ_HEX(0x34567812u, rotl32(0x12345678u, 8));
    ASSERT_EQ_HEX(0x78123456u, rotr32(0x12345678u, 8));
    ASSERT_EQ_HEX(0x81234567u, rotr32(0x12345678u, 4));
    ASSERT_EQ_HEX(0x23456781u, rotl32(0x12345678u, 4));
}


/* ============================= */
/* reverse_bits32                */
/* ============================= */

static void test_reverse_bits32_basic() {
    ASSERT_EQ_HEX(0x00000000u, reverse_bits32(0x00000000u));
    ASSERT_EQ_HEX(0x80000000u, reverse_bits32(0x00000001u));
    ASSERT_EQ_HEX(0x00000001u, reverse_bits32(0x80000000u));
    ASSERT_EQ_HEX(0xFFFFFFFFu, reverse_bits32(0xFFFFFFFFu));
    ASSERT_EQ_HEX(0x0000FFFFu, reverse_bits32(0xFFFF0000u));
}

static void test_reverse_bits32_known() {
    /* 0x12345678 -> 0x1E6A2C48 when fully bit-reversed (32-bit) */
    ASSERT_EQ_HEX(0x1E6A2C48u, reverse_bits32(0x12345678u));

    /* Pattern checks */
    ASSERT_EQ_HEX(0x55555555u, reverse_bits32(0xAAAAAAAAu));
    ASSERT_EQ_HEX(0xAAAAAAAAu, reverse_bits32(0x55555555u));
}


/* ============================= */
/* Runner                        */
/* ============================= */

int run_bit_transform_tests() {
    printf("Running bit_transform tests...\n\n");

    test_rotations_basic();
    test_rotations_wraparound();
    test_reverse_bits32_basic();
    test_reverse_bits32_known();

    printf("Tests run    : %d\n", tests_run);
    printf("Tests failed : %d\n", tests_failed);

    if (tests_failed == 0) {
        printf("\nAll bit_transform tests passed.\n");
    }

    return tests_failed;
}
