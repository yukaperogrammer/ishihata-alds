#include <stdio.h>
#include "queue.h"

int main(int argc, char *argv[]) {
    Queue queue;
    initQueue(&queue);

    enterIntoQueue(&queue, "1");
    printf("enter 1\n");
    showQueue(&queue);
    printf("-----------------------------\n");

    enterIntoQueue(&queue, "2");
    printf("enter 2\n");
    showQueue(&queue);
    printf("-----------------------------\n");

    enterIntoQueue(&queue, "3");
    printf("enter 3\n");
    showQueue(&queue);
    printf("-----------------------------\n");

    printf("remove %s\n", removeFromQueue(&queue));
    showQueue(&queue);
    printf("-----------------------------\n");

    printf("remove %s\n", removeFromQueue(&queue));
    showQueue(&queue);
    printf("-----------------------------\n");

    enterIntoQueue(&queue, "100");
    printf("enter 100\n");
    showQueue(&queue);
    printf("-----------------------------\n");

    printf("remove %s\n", removeFromQueue(&queue));
    showQueue(&queue);
    printf("-----------------------------\n");

    return 0;
}
