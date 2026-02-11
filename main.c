#include <stdio.h>

int run_bit_ops_tests(void);

int main(void) {
    int failed = run_bit_ops_tests();

    if (failed != 0) {
        printf("\nSome tests failed.\n");
        return 1;
    }

    printf("\nEverything works correctly.\n");
    return 0;
}
