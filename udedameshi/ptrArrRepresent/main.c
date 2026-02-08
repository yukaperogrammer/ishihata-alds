#include <stdio.h>
#include "arrPool.h"
#define ARRAYSIZE 10

int main(int argc, char *argv[])
{
    int i;
    Pool pool[ARRAYSIZE];
    initPool(pool, ARRAYSIZE);

    i = allocate(pool);
    printf("i = %d\n", i);

    i = allocate(pool);
    printf("i = %d\n", i);

    i = allocate(pool);
    printf("i = %d\n", i);

    i = allocate(pool);
    printf("i = %d\n", i);

    i = allocate(pool);
    printf("i = %d\n", i);

    i = allocate(pool);
    printf("i = %d\n", i);

    i = allocate(pool);
    printf("i = %d\n", i);

    i = allocate(pool);
    printf("i = %d\n", i);
    
    i = allocate(pool);
    printf("i = %d\n", i);
    
    i = allocate(pool);
    printf("i = %d\n", i);

    i = allocate(pool);
    printf("i = %d\n", i);

    return 0;
}

