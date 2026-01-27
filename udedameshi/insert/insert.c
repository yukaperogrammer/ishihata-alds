#include <stdio.h>
#include <stdlib.h>

#define ARRAYSIZE 10

void insert(int *, int, int, int);
void show_array(int *, int);

int main(int argc, char *argv[])
{
    int arr[ARRAYSIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    long index = 0;
    long value = 0;

    if (argc != 3) {
        fprintf(stderr, "Usage: insert <index> <value>");
        return 1;
    }

    index = strtol(argv[1], NULL, 10);
    value = strtol(argv[2], NULL, 10);

    insert(arr, ARRAYSIZE, (int)index, (int)value);

    return 0;
}

void insert(int *arr, int size, int index, int value)
{
    int i;

    if (index < 0 || index > size) {
        fprintf(stderr, "index out of range.");
        return;
    }

    for(i = size - 1; i > index; i--) {
        arr[i] =  arr[i - 1];
    }
    arr[index] = value;

    show_array(arr, size);
}

void show_array(int *arr, int size)
{
    int i;

    for(i = 0; i < size; i++) {
        printf("array[%d] = %d\n", i, arr[i]);
    }
}

