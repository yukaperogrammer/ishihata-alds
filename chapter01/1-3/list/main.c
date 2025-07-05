#include <stdio.h>
#include "list.h"

int main(int argc, char *argv[]) {
    List strList;
    init(&strList);

    insert(&strList, 0, "100");
    insert(&strList, 1, "200");
    insert(&strList, 1, "300");
    insert(&strList, 0, "1000");
    insert(&strList, 4, "999");
    showList(&strList);
    printf("index %d value = %s\n",2, get(&strList, 2));
    printf("index %d value = %s\n",0, get(&strList, 0));
    printf("index %d value = %s\n",4, get(&strList, 4));
    printf("------------------------------\n");

    delete(&strList, 0);
    showList(&strList);
    printf("------------------------------\n");

    delete(&strList, 3);
    showList(&strList);
    printf("------------------------------\n");

    delete(&strList, 1);
    showList(&strList);
    printf("------------------------------\n");

    return 0;
}
