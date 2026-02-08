#ifndef ARR_POOL_H
#define ARR_POOL_H

typedef struct pool {
    char *value;
    // 次の値が格納されている配列のインデックスを保持
    int next;
} Pool;

void initPool(struct pool *, int);
int allocate(struct pool *);
int deallocate(struct pool *, int); 

#endif

