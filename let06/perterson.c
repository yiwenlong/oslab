#include "thread.h"

#define A 1
#define B 2

#define BARRIER __sync_synchronize()

atomic_int nested;
atomic_long count;

void critical_section() {
    long cnt = atomic_fetch_add(&count, 1);
    int i = atomic_fetch_add(&nested, 1) + 1;
    if (i != 1) {
        printf("%d threads in the critical section @ count=%ld\n", i, count);
        assert(0);
    }
    atomic_fetch_add(&nested, -1);
}

int volatile flag_a = 0, flag_b = 0, turn;

void TA() {
    while (1) {
        flag_a = 1;                 BARRIER;
        turn = B;                   BARRIER;
        while (1) {
            if (!flag_b) break;     BARRIER;
            if (turn != B) break;   BARRIER;
        }
    }

    critical_section();
    flag_a = 0;                     BARRIER;
}

void TB() {
    while (1) {
        flag_b = 1;                 BARRIER
        turn = A;                   BARRIER;
        while (1) {
            if (!flag_a) break;     BARRIER;
            if (turn != A) break;   BARRIER;
        }
    }

    critical_section();
    flag_b = 0;                     BARRIER;                     
}