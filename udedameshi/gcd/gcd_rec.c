#include <stdio.h>
#include <stdlib.h>

long gcd_rec(long, long);

int main(int argc, char *argv[])
{
    long m = 0L;
    long n = 0L;
    long answer = 0L;

    if (argc != 3) {
        fprintf(stderr, "Usage: gcd_rec <num1(integer)> <num2(integer)>");
        return 1;
    }

    m = strtol(argv[1], NULL, 10);
    n = strtol(argv[2], NULL, 10);

    answer = gcd_rec(m, n);
    printf("gcd(%ld, %ld) = %ld\n", m, n, answer);

    return 0;
}

long gcd_rec(long m, long n)
{
    if (n == 0) {
        return m;
    }

    return gcd_rec(n, m % n);
}

