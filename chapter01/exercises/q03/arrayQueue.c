#include <stdio.h>
#include <stdlib.h>
#include "arrayQueue.h"
#define ARRAYSIZE 10

int initQueue(Queue *queue)
{
    int i;

    queue->array = (int *)xmalloc(NULL, sizeof(int) * ARRAYSIZE);
    if (queue->array == NULL) {
        fprintf(stderr, "memory allocation error\n");
        return 0;
    }

    for (i = 0; i < ARRAYSIZE; i++) {
        queue->array[i] = -1;
    }
    queue->head = 0;
    queue->tail = 0;

    return 1;
}

int enterQueue(Queue *queue, int value)
{
    if (isFull(queue) == 1) {
        fprintf(stderr, "array is full\n");
        return -1;
    }

    queue->array[queue->tail] = value; 
    queue->tail = (queue->tail + 1) % ARRAYSIZE;

    return 1;
}

int removeQueue(Queue *queue)
{
    int value;

    if (isEmpty(queue) == 1) {
        fprintf(stderr, "array is empty\n");
        return -1;
    }

    value = queue->array[queue->head];
    queue->array[queue->head] = -1;
    queue->head = (queue->head + 1) % ARRAYSIZE;

    return value;
}

int getSize(Queue *queue)
{
    int index = queue->head;
    int size = 0;

    while (index != queue->tail) {
        index = (index + 1) % ARRAYSIZE;
        size++;
    }
    
    return size;
}

int isFull(Queue *queue)
{
    if (getSize(queue) == ARRAYSIZE - 1) { 
        return 1;
    } 

    return 0;
}

int isEmpty(Queue *queue)
{
    if (getSize(queue) == 0) {
        return 1;
    }

    return 0;
}

void show(Queue *queue)
{
    int index = queue->head;

    printf("-----内容列挙(size = %d)-----\n", getSize(queue));
    while (index != queue->tail) {
        printf("array[%d] = %d\n", index, queue->array[index]);
        index = (index + 1) % ARRAYSIZE;
    }
    printf("-----------------------------\n\n");

    return;
}

void *xmalloc(void *ptr, size_t size)
{
    if (ptr == NULL) {
        return malloc(size);
    }

    return realloc(ptr, size);
}

