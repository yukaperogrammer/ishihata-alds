#include <stdio.h>
#include "selfReOrganizingList.h"

int main(int argc, char *argv[])
{
    List list;
    initList(&list);

    insertList(&list, "A", 0);
    showList(&list);

    insertList(&list, "B", 1);
    showList(&list);

    insertList(&list, "C", 2);
    showList(&list);

    insertList(&list, "D", 2);
    showList(&list);

    insertList(&list, "F", 0);
    showList(&list);

    insertList(&list, "G", 5);
    showList(&list);

    deleteList(&list, 0);
    showList(&list);

    deleteList(&list, 4);
    showList(&list);

    deleteList(&list, 2);
    showList(&list);

    search(&list, "B");
    showList(&list);

    search(&list, "C");
    showList(&list);

    search(&list, "C");
    showList(&list);

    search(&list, "A");
    showList(&list);

    deleteList(&list, 0);
    deleteList(&list, 0);
    deleteList(&list, 0);
    insertList(&list, "AA", 0);
    showList(&list);

    return 0;
}

