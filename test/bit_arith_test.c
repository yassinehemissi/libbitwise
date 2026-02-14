// AI Generated Test 
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include "../include/bitwise.h"

static int tests_run = 0;
static int tests_failed = 0;

#define ASSERT_EQ_I32(expected, actual)                              \
    do {                                                             \
        tests_run++;                                                 \
        int32_t _e = (int32_t)(expected);                             \
        int32_t _a = (int32_t)(actual);                               \
        if (_e != _a) {                                              \
            tests_failed++;                                          \
            printf("Test failed at line %d\n", __LINE__);            \
            printf("Expected: %d\n", _e);                            \
            printf("Actual  : %d\n\n", _a);                          \
        }                                                            \
    } while (0)

#define ASSERT_EQ_INT(expected, actual)                              \
    do {                                                             \
        tests_run++;                                                 \
        int _e = (int)(expected);                                     \
        int _a = (int)(actual);                                       \
        if (_e != _a) {                                              \
            tests_failed++;                                          \
            printf("Test failed at line %d\n", __LINE__);            \
            printf("Expected: %d\n", _e);                            \
            printf("Actual  : %d\n\n", _a);                          \
        }                                                            \
    } while (0)


/* ============================= */
/* add_no_plus                   */
/* ============================= */
static void test_add_no_plus() {
    ASSERT_EQ_I32(0, add_no_plus(0, 0));
    ASSERT_EQ_I32(5, add_no_plus(2, 3));
    ASSERT_EQ_I32(-1, add_no_plus(2, -3));
    ASSERT_EQ_I32(-10, add_no_plus(-7, -3));
    ASSERT_EQ_I32(INT32_MAX, add_no_plus(INT32_MAX, 0));
    ASSERT_EQ_I32((int32_t)(INT32_MIN + 1), add_no_plus(INT32_MIN, 1));
}

/* ============================= */
/* negate32                      */
/* ============================= */
static void test_negate32() {
    ASSERT_EQ_I32(0, negate32(0));
    ASSERT_EQ_I32(-5, negate32(5));
    ASSERT_EQ_I32(5, negate32(-5));
    /* Note: negate32(INT32_MIN) overflows in signed arithmetic in C.
       We do not assert a value here; behavior may wrap on two's complement
       but is technically undefined in standard C. */
}

/* ============================= */
/* sub_no_minus                  */
/* ============================= */
static void test_sub_no_minus() {
    ASSERT_EQ_I32(0, sub_no_minus(0, 0));
    ASSERT_EQ_I32(-1, sub_no_minus(2, 3));
    ASSERT_EQ_I32(5, sub_no_minus(2, -3));
    ASSERT_EQ_I32(-4, sub_no_minus(-7, -3));
    ASSERT_EQ_I32(INT32_MAX, sub_no_minus(INT32_MAX, 0));
    ASSERT_EQ_I32((int32_t)(INT32_MIN + 1), sub_no_minus(INT32_MIN, -1));
}

/* ============================= */
/* abs_no_branch                 */
/* ============================= */
static void test_abs_no_branch() {
    ASSERT_EQ_I32(0, abs_no_branch(0));
    ASSERT_EQ_I32(7, abs_no_branch(7));
    ASSERT_EQ_I32(7, abs_no_branch(-7));
    /* Note: abs(INT32_MIN) cannot be represented in int32_t.
       We skip asserting it. */
}

/* ============================= */
/* min_no_branch / max_no_branch */
/* ============================= */
static void test_min_max_no_branch() {
    ASSERT_EQ_I32(2, min_no_branch(2, 3));
    ASSERT_EQ_I32(2, min_no_branch(3, 2));
    ASSERT_EQ_I32(-5, min_no_branch(-5, 2));
    ASSERT_EQ_I32(-5, min_no_branch(2, -5));
    ASSERT_EQ_I32(-7, min_no_branch(-7, -3));

    ASSERT_EQ_I32(3, max_no_branch(2, 3));
    ASSERT_EQ_I32(3, max_no_branch(3, 2));
    ASSERT_EQ_I32(2, max_no_branch(-5, 2));
    ASSERT_EQ_I32(2, max_no_branch(2, -5));
    ASSERT_EQ_I32(-3, max_no_branch(-7, -3));
}

/* ============================= */
/* have_opposite_signs           */
/* ============================= */
static void test_have_opposite_signs() {
    ASSERT_EQ_INT(0, have_opposite_signs(0, 0));
    ASSERT_EQ_INT(0, have_opposite_signs(0, 5));
    ASSERT_EQ_INT(0, have_opposite_signs(0, -5));
    ASSERT_EQ_INT(0, have_opposite_signs(5, 7));
    ASSERT_EQ_INT(0, have_opposite_signs(-5, -7));
    ASSERT_EQ_INT(1, have_opposite_signs(5, -7));
    ASSERT_EQ_INT(1, have_opposite_signs(-5, 7));
}

/* ============================= */
/* average_no_overflow           */
/* ============================= */
static void test_average_no_overflow() {
    ASSERT_EQ_I32(0, average_no_overflow(0, 0));
    ASSERT_EQ_I32(2, average_no_overflow(2, 3));     /* floor((2+3)/2)=2 */
    ASSERT_EQ_I32(-2, average_no_overflow(-2, -3));  /* floor((-5)/2)=-2 in C trunc toward 0? Actually -5/2 = -2 (trunc toward 0) */
    ASSERT_EQ_I32(0, average_no_overflow(-1, 1));
    ASSERT_EQ_I32(INT32_MAX, average_no_overflow(INT32_MAX, INT32_MAX));
    ASSERT_EQ_I32(INT32_MIN, average_no_overflow(INT32_MIN, INT32_MIN));
    ASSERT_EQ_I32(-1, average_no_overflow(INT32_MIN, INT32_MAX));    /* (-1)/2 -> 0? Actually INT32_MIN+INT32_MAX = -1, -1/2 = 0 in C trunc toward 0. So expected 0. */
    ASSERT_EQ_I32(0, average_no_overflow(INT32_MIN, INT32_MAX));
}


/* ============================= */
/* Runner                        */
/* ============================= */
int run_bit_arith_tests() {
    printf("Running bit_arith tests...\n\n");

    test_add_no_plus();
    test_negate32();
    test_sub_no_minus();
    test_abs_no_branch();
    test_min_max_no_branch();
    test_have_opposite_signs();
    test_average_no_overflow();

    printf("Tests run    : %d\n", tests_run);
    printf("Tests failed : %d\n", tests_failed);

    if (tests_failed == 0) {
        printf("\nAll bit_arith tests passed.\n");
    }

    return tests_failed;
}
