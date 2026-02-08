#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initList(List *list)
{
    list->head = NULL;
    list->size = 0;
}

int insertList(List *list, char *value, int index)
{
    Node *new = NULL;
    Node *prev = NULL;
    Node *current = NULL;
    int i;

    // 参照なし
    if (list == NULL) {
        return 0;
    }

    // 範囲外
    if (index < 0 || index > list->size) {
        return 0;
    }

    new = (Node *)xmalloc(NULL, sizeof(Node));
    // メモリ割り当てエラー
    if (new == NULL) {
        return 0;
    }
    new->value = value;
    new->next = NULL;

    current = list->head;
    for (i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }

    new->next = current;
    if (current == list->head) {
        list->head = new;
    } else {
        prev->next = new;
    }

    list->size++;

    return 1;
}

int deleteList(List *list, int index)
{
    Node *prev = NULL;
    Node *current = NULL;
    int i;

    // 参照エラー
    if (list == NULL) {
        return 0;
    }

    // 範囲外
    if (index > list->size) {
        return 0;
    }

    // リストが空
    if (isEmptyList(list)) {
        return 0;
    }

    current = list->head;
    for (i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }

    if (current == list->head) {
        list->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    list->size--;

    return 1;
}

void *xmalloc(void *ptr, size_t size)
{
    if (ptr == NULL) {
        return malloc(size);
    }

    return realloc(ptr, size);
}

void showList(List *list)
{
    Node *current = list->head;
    int i;

    for (i = 0; i < list->size; i++) {
        printf("list[%d] = %s\n", i, current->value);
        current = current->next;
    }
    printf("\n");
}

int isEmptyList(List *list)
{
    if (list->size == 0) {
        return 1;
    }

    return 0;
}

