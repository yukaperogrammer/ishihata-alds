#include <stdio.h>
#include "queue.h"

void initQueue(Queue *queue) {
    int i;

    for (i = 0; i < ARRAYSIZE; i++) {
        queue->array[i] = NULL;
    }
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
}

int enterIntoQueue(Queue *queue, char *value) {
    if (isQueueFull(queue)) {
        return 0;
    }

    queue->array[queue->tail] = value;
    queue->tail = (queue->tail + 1) % ARRAYSIZE;
    queue->size++;

    return 1;
}

char *removeFromQueue(Queue *queue) {
    char *tmp;

    if (isQueueEmpty(queue)) {
        return NULL;
    }

    tmp = queue->array[queue->head];
    queue->array[queue->head] = NULL;
    queue->head = (queue->head + 1) % ARRAYSIZE;
    queue->size--;

    return tmp;
}

int isQueueEmpty(Queue *queue) {
    if (queue->size == 0){
        return 1;
    }

    return 0;
}

int isQueueFull(Queue *queue) {
    if (queue->size == ARRAYSIZE) {
        return 1;
    }

    return 0;
}

void showQueue(Queue *queue) {
    int i;

    for (i = queue->head; i < queue->head + queue->size; i++) {
        printf("value = %s\n", queue->array[i % ARRAYSIZE]); 
    }
}
