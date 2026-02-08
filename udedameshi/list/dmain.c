#include <stdio.h>
#include "dummyList.h"

int main(int argc, char *argv[])
{
    DummyList list;
    initList(&list);

    insertList(&list, "A", 0);
    printf("size = %d\n", list.size);
    insertList(&list, "B", 1);
    printf("size = %d\n", list.size);
    insertList(&list, "C", 2);
    printf("size = %d\n", list.size);
    insertList(&list, "D", 3);
    printf("size = %d\n", list.size);
    insertList(&list, "AA", 0);
    printf("size = %d\n", list.size);
    insertList(&list, "BB", 0);
    printf("size = %d\n", list.size);
    insertList(&list, "CC", 0);
    printf("size = %d\n", list.size);
    insertList(&list, "X", 7);
    printf("size = %d\n", list.size);
    insertList(&list, "Z", 8);
    printf("size = %d\n", list.size);
    insertList(&list, "Y", 9);
    printf("size = %d\n", list.size);
    insertList(&list, "AAAAA", 5);
    printf("size = %d\n", list.size);
    showList(&list);

    deleteList(&list, 0);
    printf("削除\n");
    showList(&list);

    deleteList(&list, 9);
    printf("削除\n");
    showList(&list);

    deleteList(&list, 0);
    deleteList(&list, 0);
    deleteList(&list, 0);
    deleteList(&list, 0);
    deleteList(&list, 0);
    deleteList(&list, 0);
    deleteList(&list, 0);
    deleteList(&list, 0);
    printf("8つ削除\n");
    showList(&list);

    deleteList(&list, 0);
    printf("1つ削除\n");
    showList(&list);

    insertList(&list, "MMM", 0);
    printf("1つ追加\n");
    showList(&list);

    return 0;
}

