#ifndef _SPIN_LOCK_H_
#define _SPIN_LOCK_H_ 1

typedef struct __lock_t {
    int flag;
} lock_t;

void spin_lock_init(lock_t *lock); 

void spin_lock(lock_t *lock);

void spin_unlock(lock_t *lock); 

#endif
