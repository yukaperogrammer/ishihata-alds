#include <stdio.h>
#include <stdlib.h>
#include "dummyList.h"

void initList(DummyList *list)
{
    list->dummy.value = NULL;
    list->dummy.next = &list->dummy;
    list->size = 0;
}

int insertList(DummyList *list, char *value, int index)
{
    Node *new = NULL;
    Node *current = NULL;
    Node *prev = NULL;
    int i = 0;

    if (list == NULL) {
        fprintf(stderr, "参照エラー\n");
        return -1;
    }

    if (index < 0 || index > list->size) {
        fprintf(stderr, "範囲エラー\n");
        return -1;
    }

    new = (void *)xmalloc(NULL, sizeof(Node));
    if (new == NULL) {
        fprintf(stderr, "メモリ割り当てエラー");
        return -1;
    }
    new->value = value;
    new->next = NULL;

    current = list->dummy.next;
    prev = &list->dummy;
    for (i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }

    prev->next = new;
    new->next = current;
    list->size++;

    return 1;
}

int deleteList(DummyList *list, int index)
{
    Node *current = NULL;
    Node *prev = NULL;
    int i = 0;

    if (list == NULL) {
        fprintf(stderr, "参照エラー");
        return -1;
    }

    if (index < 0 || index > list->size) {
        fprintf(stderr, "範囲エラー");
        return -1;
    }

    current = list->dummy.next;
    prev = &list->dummy;
    for (i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
    list->size--;

    return 1;
}

void showList(DummyList *list)
{
    Node *node = NULL;

    printf("---リスト列挙---\n");
    node = list->dummy.next;
    while (node != &list->dummy) {
        printf("element = %s\n", node->value);
        node = node->next;
    }
    printf("size = %d\n", list->size);
    printf("----------------\n\n");

    return;
}

void *xmalloc(void *ptr, size_t size)
{
    if (ptr == NULL) {
        return malloc(size);
    }

    return realloc(ptr, size);
}

