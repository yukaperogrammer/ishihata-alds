#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H
typedef struct queue {
    int *array;
    int head;
    int tail;
} Queue;

int initQueue(Queue *);
int enterQueue(Queue *, int);
int removeQueue(Queue *);
int getSize(Queue *);
int isFull(Queue *);
int isEmpty(Queue *);
void show(Queue *);
void *xmalloc(void *, size_t);

#endif

