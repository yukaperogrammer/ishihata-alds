#include <stdio.h>
#include "../../list/list.h"
#include "queue.h"

void initQueue(Queue *queue) {
    initList(queue->list);
}

int enterIntoQueue(Queue *queue, char *value) {
    return insertIntoList(queue->list, queue->list->size, value);
}

char *removeFromQueue(Queue *queue) {
    char *tmp = NULL;

    if (isQueueEmpty(queue)) {
        return NULL;
    }

    tmp = getFromList(queue->list, 0);
    deleteFromList(queue->list, 0);

    return tmp;
}

int isQueueEmpty(Queue *queue) {
    if (queue->list->size == 0) {
        return 1;
    }

    return 0;
}

void showQueue(Queue *queue) {
    showList(queue->list);
}
