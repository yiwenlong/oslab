#include "spin_lock.h"

// set new value, return old value.
int test_and_set(int *, int);

void spin_lock_init(lock_t *lock) {
    lock->flag = 0;
}

void spin_lock(lock_t *lock) {
    while (test_and_set(&lock->flag, 1))
        ;  // spin-wait (do nothing)
}

void spin_unlock(lock_t *lock) {
    lock->flag = 0;
}
