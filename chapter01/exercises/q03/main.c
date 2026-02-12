#include <stdio.h>
#include "arrayQueue.h"

int main(int argc, char *argv[])
{
    Queue queue;
    initQueue(&queue);

    removeQueue(&queue);
    show(&queue);

    enterQueue(&queue, 100);
    show(&queue);

    removeQueue(&queue);
    show(&queue);

    enterQueue(&queue, 100);
    show(&queue);

    enterQueue(&queue, 100);
    enterQueue(&queue, 200);
    enterQueue(&queue, 300);
    enterQueue(&queue, 400);
    enterQueue(&queue, 500);
    enterQueue(&queue, 600);
    enterQueue(&queue, 700);
    enterQueue(&queue, 800);
    enterQueue(&queue, 900);
    enterQueue(&queue, 1000);
    show(&queue);

    removeQueue(&queue);
    removeQueue(&queue);
    removeQueue(&queue);
    removeQueue(&queue);
    removeQueue(&queue);
    removeQueue(&queue);
    removeQueue(&queue);
    removeQueue(&queue);
    removeQueue(&queue);
    removeQueue(&queue);
    show(&queue);

    enterQueue(&queue, 100);
    enterQueue(&queue, 200);
    enterQueue(&queue, 300);
    enterQueue(&queue, 400);
    enterQueue(&queue, 500);
    removeQueue(&queue);
    removeQueue(&queue);
    removeQueue(&queue);
    enterQueue(&queue, 100);
    enterQueue(&queue, 200);
    enterQueue(&queue, 300);
    enterQueue(&queue, 600);
    enterQueue(&queue, 700);
    enterQueue(&queue, 800);
    enterQueue(&queue, 900);
    enterQueue(&queue, 1000);
    show(&queue);

    return 0;
}

