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

void initList(List *);
int insertIntoList(List *, int, char *);
int deleteFromList(List *, int);
char *getFromList(List *, int);
void showList(List *);
void *xmalloc(void *, size_t);

#endif
