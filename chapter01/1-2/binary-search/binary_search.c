/*
 * 二分探索
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define ARRAYSIZE 10

void print_array(int *);
int binary_search(int *, int);

int main(int argc, char *argv[])
{
    int array[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    long target;
    int result_index;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <integer>\n", argv[1]);
        exit(1);
    }

    errno = 0;
    target = strtol(argv[1], NULL, 10);
    if (errno != 0)
    {
        fprintf(stderr, "An error occured\n");
        exit(1);
    }

    result_index = binary_search(array, (int)target);

    print_array(array);
    if (result_index == -1)
    {
        printf("Not found %d in array\n", (int)target);
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

int binary_search(int *array, int target)
{
    int index = -1;
    int low = 0;
    int high = ARRAYSIZE - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (target == array[mid])
        {
            index = mid;
            break;
        }

        if (target < array[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return index;
}

