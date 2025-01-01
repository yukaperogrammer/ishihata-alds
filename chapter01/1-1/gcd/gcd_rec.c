/*
 * ユークリッドの互除法(再帰)
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int gcd(int, int);

int main(int argc, char *argv[])
{
    long m;
    long n;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <integer> <integer>\n", argv[0]);
        exit(1);
    }

    errno = 0;
    m = strtol(argv[1], NULL, 10);
    n = strtol(argv[2], NULL, 10);

    if (m == 0 || n == 0)
    {
        fprintf(stderr, "Please enter non 0 integer value\n");
        exit(1);
    }

    if (errno != 0)
    {
        fprintf(stderr, "An error occured\n");
        exit(1);
    }

    printf("gcd(%d, %d) = %d\n", (int)m, (int)n, gcd((int)m, (int)n));

    return 0;
}

int gcd(int m, int n)
{
    int r = m % n;
    return (r == 0) ? n : gcd(n, r);
}

