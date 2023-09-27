#include <stdio.h>

int compare_and_swap(int *ptr, int expect, int new_val);

int main() {
    int val = 0;
    int old_val = compare_and_swap(&val, 0, 1);
    printf("1. val: %d, old_val: %d\n", val, old_val);

    old_val = compare_and_swap(&val, 0, 2);
    printf("2. val: %d, old_val: %d\n", val, old_val);
    return 0;
}
