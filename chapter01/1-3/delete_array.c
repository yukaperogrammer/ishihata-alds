/*
 * 列(配列表現)からのデータの削除
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define ARRAYSIZE 10

int array[ARRAYSIZE] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
int size = ARRAYSIZE;

int strtole(char *);
void print_array();
void delete(int);

int main(int argc, char *argv[])
{
    int index;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <index>\n", argv[0]);
        exit(1);
    }

    index = strtole(argv[1]);
    if (index < 0 || index >= size)
    {
        fprintf(stderr, "Index out of range\n");
        exit(1);
    }
    delete(index);
    print_array();

    return 0;
}

int strtole(char *s)
{
    long m;

    errno = 0;
    m = strtol(s, NULL, 10);
    if (errno == EINVAL)
    {
        perror("strtol");
        exit(1);
    }

    return (int)m;
}

void print_array()
{
    int i;

    printf("array = [");
    for (i = 0; i < size - 1; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[i]);
}

void delete(int index)
{
    int i;

    size--;
    for (i = index; i < size; i++)
    {
        array[i] = array[i + 1];
    }
    array[size] = -1;
}

