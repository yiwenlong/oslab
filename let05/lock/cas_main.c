#include <stdio.h>

void compare_and_swap(int *ptr, int expect, int new_val);

int main() {
    int val = 0;
    compare_and_swap(&val, 0, 1);

    printf("val: %d\n", val);
    return 0;
}
