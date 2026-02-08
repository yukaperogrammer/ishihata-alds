#include <stdio.h>
#include "arrPool.h"

int freeList = 0;

void initPool(Pool list[], int size)
{
    int i;

    for (i = 0; i < size - 1; i++) {
        list[i].value = NULL;
        list[i].next = i + 1;
    }
    list[size - 1].next = -1;
    freeList = 0;
}

// 添字を返す
int allocate(Pool list[])
{
    int p;

    if (freeList < 0) {
        fprintf(stderr, "allocation error\n");
        return -1;
    }

    p = freeList;
    freeList = list[freeList].next;

    return p;
}

int deallocate(Pool list[], int p)
{
    list[p].next = freeList;
    list[p].value = NULL;
    freeList = p;

    return p;
}

