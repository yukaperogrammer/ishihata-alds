#ifndef QUEUE_H
#define QUEUE_H
#define ARRAYSIZE 10

typedef struct queue {
    char *array[ARRAYSIZE];
    int head;
    int tail;
    int size;
} Queue;

void initQueue(Queue *);
int enterIntoQueue(Queue *, char *);
char *removeFromQueue(Queue *);
int isQueueEmpty(Queue *);
int isQueueFull(Queue *);
void showQueue(Queue *);

#endif
