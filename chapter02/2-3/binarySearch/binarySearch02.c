#include <stdio.h>

int binarySearch(int *, int, int);

int main(int arhc, char *argv[])
{
    int arr[] = {1, 3, 4, 7, 10, 11, 16, 22, 30, 33, 39, 42, 50};
    int size = 13;
    int result;
    int target = 39;
    
    result = binarySearch(arr, size, target);
    if (result == -1) {
        printf("%d is not found.\n", target);
        return 0;
    }
    printf("%d is found. index is %d.\n", target, result);

    return 0;
}

int binarySearch(int *arr, int size, int target)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (target < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (high == -1) {
        return -1;
    }

    if (arr[high] == target) {
        return high;
    }

    return -1;
}

