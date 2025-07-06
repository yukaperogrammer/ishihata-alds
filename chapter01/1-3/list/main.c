#include <stdio.h>
#include "list.h"

int main(int argc, char *argv[]) {
    List strList;
    initList(&strList);

    insertIntoList(&strList, 0, "100");
    insertIntoList(&strList, 1, "200");
    insertIntoList(&strList, 1, "300");
    insertIntoList(&strList, 0, "1000");
    insertIntoList(&strList, 4, "999");
    showList(&strList);
    printf("index %d value = %s\n",2, getFromList(&strList, 2));
    printf("index %d value = %s\n",0, getFromList(&strList, 0));
    printf("index %d value = %s\n",4, getFromList(&strList, 4));
    printf("------------------------------\n");

    deleteFromList(&strList, 0);
    showList(&strList);
    printf("------------------------------\n");

    deleteFromList(&strList, 3);
    showList(&strList);
    printf("------------------------------\n");

    deleteFromList(&strList, 1);
    showList(&strList);
    printf("------------------------------\n");

    return 0;
}
