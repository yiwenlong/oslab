int test_and_set(int *, int);

typedef struct __lock_t {
    int flag;
} lock_t;

void lock_init(lock_t *lock) {
    lock->flag = 0;
}

void lock(lock_t *lock) {
    while (test_and_set(&lock->flag, 1))
        ;  // spin-wait (do nothing)
}

void unlock(lock_t *lock) {
    lock->flag = 0;
}