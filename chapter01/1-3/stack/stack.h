#ifndef STACK_H
#define STACK_H
#include "../list/list.h"

typedef struct stack {
    List *list;
} Stack;

void initStack(Stack *);
int pushIntoStack(Stack *, char *);
char *popFromStack(Stack *);
void showStack(Stack *);
int getStackSize(Stack *);
int isStackEmpty(Stack *);

#endif
