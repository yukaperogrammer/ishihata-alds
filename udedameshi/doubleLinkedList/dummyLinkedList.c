#include <stdio.h>
#include <stdlib.h>
#include "dummyLinkedList.h"

void initList(DummyLinkedList *list)
{
    list->dummy.prev = &list->dummy;
    list->dummy.next = &list->dummy;
    list->dummy.value = NULL;
    list->size = 0;
}

int insertList(DummyLinkedList *list, char *value, int index)
{
    Node *new = NULL;
    Node *current = NULL;
    int i = 0;

    if (list == NULL) {
        fprintf(stderr, "参照エラー\n");
        return -1;
    }

    if (index < 0 || index > list->size) {
        fprintf(stderr, "範囲エラー\n");
        return -1;
    }

    new = (Node *)xmalloc(NULL, sizeof(Node));
    if (new == NULL) {
        fprintf(stderr, "メモリ割り当てエラー\n");
        return -1;
    }
    new->value = value;
    new->prev = NULL;
    new->next = NULL;

    current = list->dummy.next;
    for (i = 0; i < index; i++) {
        current = current->next;
    }
    current->prev->next = new;
    new->prev = current->prev;
    new->next = current;
    current->prev = new;
    list->size++;

    return 1;
}

int deleteList(DummyLinkedList *list, int index)
{
    Node *current = NULL;
    int i = 0;

    if (list == NULL) {
        fprintf(stderr, "参照エラー\n");
        return -1;
    }

    if (index < 0 || index > list->size) {
        fprintf(stderr, "範囲エラー\n");
        return -1;
    }

    current = list->dummy.next;
    for (i = 0; i < index; i++) {
        current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    list->size--;

    return 0;
}

void showList(DummyLinkedList *list)
{
    Node *node = list->dummy.next;
    int i;
    for (i = 0; i < list->size; i++) {
        printf("element = %s\n", node->value);
        node = node->next;
    }

    return;
}

void showListReverse(DummyLinkedList *list)
{
    Node *node = list->dummy.prev;
    int i;
    for (i = 0; i < list->size; i++) {
        printf("element = %s\n", node->value);
        node = node->prev;
    }

    return;
}

void *xmalloc(void *ptr, size_t size)
{
    if (ptr == NULL) {
        return malloc(size);
    }

    return realloc(ptr, size);
}

