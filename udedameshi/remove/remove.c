#include <stdio.h>
#include <stdlib.h>

#define ARRAYSIZE 10

void remv(int *, int, int); 
void show_array(int *, int size);

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: ./remove <index>");
        return 1;
    }

    index = strtol(argv[1], NULL, 10);

    remv(arr, ARRAYSIZE, index);

    return 0;
}

void remv(int *arr, int size, int index)
{
    int i;

    if (index < 0 || index > size - 1) {
        fprintf(stderr, "index out of range.");
        return;
    }

    for(i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = 0;

    show_array(arr, size - 1);
}

void show_array(int *arr, int size)
{
    int i;

    for(i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}


