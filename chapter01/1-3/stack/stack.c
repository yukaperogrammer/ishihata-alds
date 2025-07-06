#include <stdio.h>
#include "../list/list.h"
#include "stack.h"

void initStack(Stack *stack) {
    initList(stack->list);
}

int pushIntoStack(Stack *stack, char *value) {
    if (stack == NULL) {
        return 0;
    }

    return insertIntoList(stack->list, stack->list->size, value);
}

char *popFromStack(Stack *stack) {
    char *tmp;
    if (isStackEmpty(stack)) {
        return NULL;
    }

    tmp = getFromList(stack->list, stack->list->size - 1);
    deleteFromList(stack->list, stack->list->size - 1);

    return tmp;
}

void showStack(Stack *stack) {
    showList(stack->list);
}

int getStackSize(Stack *stack) {
    if (stack == NULL) {
        return -1;
    }

    return stack->list->size;
}

int isStackEmpty(Stack *stack) {
    if (stack->list->size == 0) {
        return 1;
    }

    return 0;
}