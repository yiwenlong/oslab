#include <stdio.h>
#include <pthread.h>

#include "lock.h"

#define MAX 1000000

int count = 0;

void *tfunc(void *arg) {
    lock_t *l = (lock_t *) arg;
    for (int i = 0; i < MAX; i++) {
	lock(l);
        count++;
        unlock(l);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    lock_t lock;

    lock_init(&lock);

    pthread_create(&t1, NULL, tfunc, &lock);
    pthread_create(&t2, NULL, tfunc, &lock);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("count: %d\n", count);

    return 0;
}
