#include <stdio.h>

int binarySearch(int *, int, int);

int main(int argc, char *argv[])
{
    int arr[] = {0, 2, 8, 11, 12, 27, 30, 37, 38, 55, 61, 63, 69, 70, 80, 83, 89, 99, 100};
    int size = 19;
    int result;
    int target = 80;

    result = binarySearch(arr, size, target);
    printf("%d index is %d\n", target, result);

    return 0;
}

int binarySearch(int *arr, int size, int target)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (target <= arr[mid]) high = mid - 1;
        if (target >= arr[mid]) low = mid + 1;
    }

    // 見つからなかった場合は負の値を返す。
    if (low == high + 1) {
        return -1;
    }
    
    return mid;
}

