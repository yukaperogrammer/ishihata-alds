/*
 * 列(配列表現)へのデータの挿入
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define ARRAYSIZE 11

int array[ARRAYSIZE] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
int size = ARRAYSIZE - 1;

int strtole(char *);
void print_array();
void insert(int, int);

int main(int argc, char *argv[])
{
    int index;
    int value;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <index> <value>\n", argv[0]);
        exit(1);
    }

    index = strtole(argv[1]);
    value = strtole(argv[2]);

    if (index > size)
    {
        fprintf(stderr, "Index out of range\n");
        exit(1);
    }

    insert((int)index, (int)value);
    print_array();

    return 0;
}

int strtole(char *s)
{
    long number;

    errno = 0;
    number = strtol(s, NULL, 10);
    if (errno == EINVAL)
    {
        perror("strtol");
        exit(1);
    }

    return (int)number;
}

void print_array()
{
    int i;

    printf("array = [");
    for (i = 0; i < size - 1; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[size - 1]);
}

void insert(int index, int value)
{
    int i;

    size++;
    for (i = size - 1; i > index; i--)
    {
        array[i] = array[i - 1];
    }
    array[index] = value;
}

