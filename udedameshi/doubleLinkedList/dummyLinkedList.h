#ifndef DUMMY_LINKED_LIST_H
#define DUMMY_LINKED_LIST_H

typedef struct node {
    char *value;
    struct node *prev;
    struct node *next;
} Node;

typedef struct dummyLinekdList {
    struct node dummy;
    int size;
} DummyLinkedList;

void initList(DummyLinkedList *);
int insertList(DummyLinkedList *, char *, int);
int deleteList(DummyLinkedList *, int);
void showList(DummyLinkedList *);
void showListReverse(DummyLinkedList *);
void *xmalloc(void *, size_t);

#endif

