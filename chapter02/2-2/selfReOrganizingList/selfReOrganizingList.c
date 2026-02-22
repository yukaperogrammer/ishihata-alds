#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "selfReOrganizingList.h"

void initList(List *list)
{
    list->head.value = NULL;
    list->head.next = &(list->sentinel);
    list->sentinel.value = NULL;
    list->sentinel.next = &(list->head);
    list->size = 0;
}

int search(List *list, char *target)
{
    Node *current;
    Node *prev;
    int index;

    list->sentinel.value = target;
    current = list->head.next;
    prev = &(list->head);
    index = 0;
    while (strcmp(current->value, target) != 0) {
        prev = current;
        current = current->next;
        index++;
    }

    // 番兵なので-1を返して終了
    if (current == &(list->sentinel)) {
        return -1;
    }

    // 先頭に持ってくる
    prev->next = current->next;
    current->next = list->head.next;
    list->head.next = current;
    printf("info: search %s\n", target);

    return index;
}

int insertList(List *list, char *value, int index)
{
    Node *current = NULL;
    Node *prev = NULL;
    Node *new;
    int i;

    if (index < 0 || index > list->size) {
        fprintf(stderr, "range error\n");
        return 0;
    }

    new = (Node *)xmalloc(NULL, sizeof(Node));
    if (new == NULL) {
        fprintf(stderr, "memory allocation error\n");
        return 0;
    }
    new->value = value;

    current = list->head.next;
    prev = &(list->head);
    for (i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }

    prev->next = new;
    new->next = current;
    list->size++;
    printf("info: insert %s, index %d\n", value, index);

    return 1;
}

int deleteList(List *list, int index)
{
    Node *current = NULL;
    Node *prev = NULL;
    int i;

    if (index < 0 || index >= list->size) {
        fprintf(stderr, "range error\n");
        return 0;
    }

    current = list->head.next;
    prev = &(list->head);
    for (int i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    free(current);
    list->size--;
    printf("info: delete element of index %d\n", index);

    return 1;
}

void showList(List *list)
{
    Node *current;
    int i;

    printf("-----リスト列挙-----\n");
    current = list->head.next;
    for (i = 0; i < list->size; i++) {
        printf("element = %s\n", current->value);
        current = current->next;
    }
    printf("--------------------\n");

    return;
}

void *xmalloc(void *ptr, size_t size)
{
    if (ptr == NULL) {
        return malloc(size);
    }

    return realloc(ptr, size);
}

