#include "spin_lock.h"

// compare to expected
// if true, set to new value, else do nothing.
// return old value.
int compare_and_swap(int *ptr, int expected, int new);

void spin_lock_init(lock_t *lock) {
    lock->flag = 0;
}

void spin_lock(lock_t *lock) {
    while (compare_and_swap(&lock->flag, 0, 1) == 1)
        ;  // spin-wait (do nothing)
}

void spin_unlock(lock_t *lock) {
    lock->flag = 0;
}

