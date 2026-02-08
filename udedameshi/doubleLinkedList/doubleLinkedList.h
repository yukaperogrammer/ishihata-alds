#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

typedef struct node {
    char *value;
    struct node *previous;
    struct node *next;
} Node;

typedef struct double_linked_list{
    struct node *head;
    struct node *tail;
    int size;
} DoubleLinkedList;

void initList(DoubleLinkedList *);
int insertList(DoubleLinkedList *, char *, int);
int deleteList(DoubleLinkedList *, int);
void showList(DoubleLinkedList *);
void showListReverse(DoubleLinkedList *);
void *xmalloc(void *, size_t);

#endif

