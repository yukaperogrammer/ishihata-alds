#ifndef LIST_H
#define LIST_H

typedef struct element {
    char *value;
    struct element *next;
} Element;

typedef struct list {
    struct element *head;
    int size;
} List;

void init(List *);
int insert(List *, int, char *);
int delete(List *, int);
char *get(List *, int);
void showList(List *);
void *xmalloc(void *, size_t);

#endif
