#ifndef QUEUE_H
#define QUEUE_H
#include "../../list/list.h"

typedef struct queue {
    List *list;
} Queue;

void initQueue(Queue *);
int enterIntoQueue(Queue *, char *);
char *removeFromQueue(Queue *);
int isQueueEmpty(Queue *);
void showQueue(Queue *);

#endif
