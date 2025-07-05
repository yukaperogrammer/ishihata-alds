#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init(List *list) {
    list->head = NULL;
    list->size = 0;
}

int insert(List *list, int target, char *value) {
    int i;
    Element *prev = NULL;
    Element *current = NULL;
    Element *new = NULL;

    if (list == NULL) {
        return 0;
    }

    // index error
    if (target > list->size) {
        return 0;
    }

    current = list->head;
    for (i = 0; i < target; i++) {
        prev = current;
        current = current->next;
    }

    new = (Element *)xmalloc(NULL, sizeof(Element));
    if (new == NULL) {
        fprintf(stderr, "error: memory allocation.");
        return 0;
    }
    new->value = value;
    new->next = current;
    if (prev == NULL) {
        list->head = new;
    } else {
        prev->next = new;
    }
    list->size++;

    return 1;
}

int delete(List *list, int target) {
    int i;
    Element *prev = NULL;
    Element *current = NULL;

    if (list == NULL) {
        return 0;
    }

    if (target > list->size) {
        return 0;
    }

    current = list->head;
    for (i = 0 ; i < target; i++) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        list->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    list->size--;

    return 1;
}

char *get(List *list, int target) {
    int i;
    Element *current = NULL;

    if (list == NULL) {
        return NULL;
    }

    if (target > list->size) {
        return NULL;
    }

    current = list->head;
    for (i = 0; i < target; i++) {
        current = current->next;
    }

    return current->value;
}

void showList(List *list) {
    Element *current;

    current = list->head;
    while (current != NULL) {
        printf("value = %s\n", current->value);
        current = current->next;
    }
    printf("list size = %d\n", list->size);
}

void *xmalloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    } else {
        return realloc(ptr, size);
    }
}
