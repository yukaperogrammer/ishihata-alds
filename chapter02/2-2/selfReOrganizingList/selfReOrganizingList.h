#ifndef SELF_REORGANIZING_LIST_H
#define SELF_REORGANIZING_LIST_H
typedef struct node {
    char *value;
    struct node *next;
} Node;

typedef struct list {
    Node head;
    Node sentinel;
    int size;
} List;

void initList(List *);
int search(List *, char *);
int insertList(List *, char *, int);
int deleteList(List *, int);
void showList(List *);
void *xmalloc(void *, size_t);

#endif

