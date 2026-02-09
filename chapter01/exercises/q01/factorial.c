#include <stdio.h>
#include <stdlib.h>

long factorial(long);

int main(int argc, char *argv[])
{
    long n;
    long result;
    long i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <integer>\n", argv[0]);
        return 1;
    }

    n = strtol(argv[1], NULL, 10);
    result = factorial(n);
    printf("再帰バージョン\n");
    printf("%ld! = %ld\n", n, result);

    result = 1;
    for (i = 1; i <= n; i++) {
        result = result * i;
    }
    printf("ループバージョン\n");
    printf("%ld! = %ld\n", n, result);

    /*
    正当性
    ループ不変条件は、ループ開始時点で
        result = (i-1)!
    が成立していること。

    i = 1のとき、result = 1 * 1 で成立。
    i = kのとき、result = (k-1)! が成立していると仮定。
    i = k + 1のとき
        result = result * (k+1-1)!
               = (k-1)! * k
               = k!
    よって任意のiで成立。
    以上からこのアルゴリズムは正しい結果を計算する。 --- A

    停止性
    ループ継続条件が
        i <= n
    であり、1ループごとにiはインクリメントされるので、
        i > n
    となったときにループを終了する。
    以上からこのアルゴリズムは終了する。 --- B

    A、Bより、このアルゴリズムは正しい。
    */
}

long factorial(long n)
{    
    if (n == 0 || n == 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

