#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[]) {
    Stack stack;
    initStack(&stack);
    printf("stack size = %d\n", getStackSize(&stack));
    printf("-----------------------------\n");

    pushIntoStack(&stack, "1");
    printf("push 1\n");
    pushIntoStack(&stack, "2");
    printf("push 2\n");
    pushIntoStack(&stack, "3");
    printf("push 3\n");
    showStack(&stack);
    printf("stack size = %d\n", getStackSize(&stack));
    printf("-----------------------------\n");

    printf("pop %s\n" ,popFromStack(&stack));
    showStack(&stack);
    printf("stack size = %d\n", getStackSize(&stack));
    printf("-----------------------------\n");

    pushIntoStack(&stack, "100");
    printf("push 100\n");
    showStack(&stack);
    printf("stack size = %d\n", getStackSize(&stack));
    printf("pop %s\n" ,popFromStack(&stack));
    showStack(&stack);
    printf("stack size = %d\n", getStackSize(&stack));
    printf("-----------------------------\n");

    printf("pop %s\n" ,popFromStack(&stack));
    showStack(&stack);
    printf("stack size = %d\n", getStackSize(&stack));
    printf("-----------------------------\n");

    return 0;
}