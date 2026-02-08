#ifndef DUMMY_LIST_H
#define DUMMY_LIST_H

typedef struct node {
    char *value;
    struct node *next;
} Node;

typedef struct dummyList {
    struct node dummy;
    int size;
} DummyList;

void initList(DummyList *);
int insertList(DummyList *, char *, int);
int deleteList(DummyList *, int);
void showList(DummyList *);
void *xmalloc(void *, size_t);

#endif

