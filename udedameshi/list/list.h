#ifndef LIST_H
#define LIST_H

typedef struct node {
    char *value;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
    int size;
} List;

void initList(List *);
int insertList(List *, char *, int);
int deleteList(List *, int);
void showList(List *);
int isEmptyList(List *);
void *xmalloc(void *, size_t);
void clear(List *);

#endif

