/*
 * 線形探索
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define ARRAYSIZE 10

void print_array(int *);
int linear_search(int *, int);

int main(int argc, char *argv[])
{
    int array[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    long target;
    int result_index;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <integer>\n", argv[0]);
        exit(1);
    }

    errno = 0;
    target = strtol(argv[1], NULL, 10);

    if (errno != 0)
    {
        fprintf(stderr, "An error occured\n");
        exit(1);
    }

    result_index = linear_search(array, (int)target);

    print_array(array);
    if (result_index == -1)
    {
        printf("Not found %d in array\n",  (int)target);
    }
    else
    {
        printf("array[%d] = %d\n", result_index, (int)target);
    }

    return 0;
}

void print_array(int *array)
{
    int i;

    printf("array = [");
    for (i = 0; i < ARRAYSIZE - 1; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[ARRAYSIZE - 1]);
}

int linear_search(int *array, int target)
{
    int i;
    int index = -1;

    for (i = 0; i < ARRAYSIZE; i++)
    {
        if (target == array[i])
        {
            index = i;
            break;
        }
    }

    return index;
}

