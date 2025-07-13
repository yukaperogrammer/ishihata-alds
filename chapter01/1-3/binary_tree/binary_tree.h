#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <stdlib.h>

typedef struct binary_tree {
    struct node *root;
} BinaryTree;

typedef struct node {
    char *value;
    struct node *left;
    struct node *right;
} Node;

void buildTree(BinaryTree *);
void preOrder(Node *);
void inOrder(Node *);
void postOrder(Node *);
void showNodeValue(Node *);
void *xmalloc(void *, size_t);

#endif
