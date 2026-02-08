#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"

void initList(DoubleLinkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int insertList(DoubleLinkedList *list, char *value, int index)
{
    Node *new = NULL;
    Node *current = NULL;
    Node *previous = NULL;
    int i = 0;

    // ポインタがない場合
    if (list == NULL) {
        return -1;
    }

    // 範囲外
    if (index < 0 || index > list->size) {
        fprintf(stderr, "範囲外\n");
        return -1;
    }

    new = (Node *)xmalloc(NULL, sizeof(Node));
    // メモリ確保失敗
    if (new == NULL) {
        fprintf(stderr, "allocate error\n");
        return -1;
    }

    new->value = value;
    new->previous = NULL;
    new->next = NULL;

    current = list->head;
    for (i = 0; i < index; i++) {
        previous = current;
        current = current->next;
    }

    // 通常の追加
    if (0 < index && index < list->size) {
        current->previous->next = new;
        new->previous = current->previous;
        new->next = current;
        current->previous = new;
    // 特殊な場合 
    } else {
        // 先頭に追加
        if (index == 0) {
            list->head = new;
            new->next = current;
            if (current != NULL) {
                current->previous = new;
            }
        }

        // 末尾に追加
        if (index == list->size) {
            list->tail = new;
            new->previous = previous;
            if (previous != NULL) {
                previous->next = new;
            }
        }
    }

    list->size++;

    return 1;
}

int deleteList(DoubleLinkedList *list, int index)
{
    Node *target = NULL;
    int i = 0;

    target = list->head;
    for (i = 0; i < index; i++) {
        target = target->next;
    }

    // 通常の削除
    if (0 < index && index < list->size - 1) {
        target->previous->next = target->next;
        target->next->previous = target->previous;
    // 特殊な場合
    } else {
        if (index == 0) {
            list->head = target->next;
            if (target->next != NULL) {
                target->next->previous = NULL;
            }
        }

        if (index == list->size - 1) {
            list->tail = target->previous;
            if (target->previous != NULL) {
                target->previous->next = NULL;
            }
        }
    }

    free(target);

    list->size--;

    return 1;
}

void showList(DoubleLinkedList *list)
{
    Node *tmp;

    for (tmp = list->head; tmp != NULL; tmp = tmp->next) {
        printf("value = %s\n", tmp->value);
    }
}

void showListReverse(DoubleLinkedList *list)
{
    Node *tmp;

    for (tmp = list->tail; tmp != NULL; tmp = tmp->previous) {
        printf("value = %s\n", tmp->value);
    }
}


void *xmalloc(void *ptr, size_t size)
{
    if (ptr == NULL) {
        return malloc(size);
    }

    return realloc(ptr, size);
}

