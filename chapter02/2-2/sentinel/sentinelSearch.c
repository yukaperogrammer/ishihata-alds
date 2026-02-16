#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 10

int search(int, int *);

int main(int argc, char *argv[])
{
    int arr[] = {18, 32, 9, 1, 28, 49 ,76, 30, 11, 0};
    long input;
    int target;
    int index;

    if (argc != 2) {
        fprintf(stderr, "error\n");
        return 1;
    }

    input = strtol(argv[1], NULL, 10);
    target = (int)input;
    index = search(target, arr);
    if (index < 0) {
        printf("%d is not found\n", target);
    } else {
        printf("%d index is %d\n", target, index);
    }

    return 0;
}

int search(int target, int *arr)
{
    int *ptr;
    int index;
    int i;

    ptr = (int *)malloc(sizeof(int) * (ARRAYSIZE + 1));
    if (ptr == NULL) {
        fprintf(stderr, "error\n");
        return 1;
    }

    for (i = 0; i < ARRAYSIZE; i++) {
        *(ptr + i) = arr[i];
    }
    *(ptr + i) = target;

    printf("-----番兵末尾追加-----\n");
    for (i = 0; i < ARRAYSIZE + 1; i++) {
        printf("ptr[%d] = %d\n", i, *(ptr + i));
    }
    printf("-------------------------\n");

    for (i = 0; i < ARRAYSIZE + 1; i++) {
        if (*(ptr + i) == target) {
            index = i;
            break;
        }
    }

    if (index == ARRAYSIZE) {
        return -1;
    }

    return index;
}

