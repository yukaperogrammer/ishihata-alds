#include <stdio.h>
#include "list.h"

int main(int argc, char *argv[])
{
    List list;
    initList(&list);

    insertList(&list, "test", 0);
    insertList(&list, "aaa", 1);
    insertList(&list, "bbb", 2);
    insertList(&list, "ccc", 0);
    insertList(&list, "ddd", 4);
    showList(&list);

    deleteList(&list, 4);
    deleteList(&list, 0);
    showList(&list);

    deleteList(&list, 1);
    showList(&list);

    return 0;
}

