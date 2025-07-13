#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

void buildTree(BinaryTree *binaryTree) {
    Node *parent;
    Node *left;
    Node *right;

    // first ROOT
    parent = (Node *)xmalloc(NULL, sizeof(Node));
    binaryTree->root = parent;
    left = (Node *)xmalloc(NULL, sizeof(Node));
    right = (Node *)xmalloc(NULL, sizeof(Node));
    parent->value = "*";
    left->value = "+";
    right->value = "-";
    parent->left = left;
    parent->right = right;

    // root left child
    parent = binaryTree->root->left;
    left = (Node *)xmalloc(NULL, sizeof(Node));
    right = (Node *)xmalloc(NULL, sizeof(Node));
    left->value = "a";
    left->left = NULL;
    left->right = NULL;
    right->value = "b";
    right->left = NULL;
    right->right = NULL;
    parent->left = left;
    parent->right = right;

    // root right child
    parent = binaryTree->root->right;
    left = (Node *)xmalloc(NULL, sizeof(Node));
    right = (Node *)xmalloc(NULL, sizeof(Node));
    left->value = "c";
    left->left = NULL;
    left->right = NULL;
    right->value = "/";
    parent->left = left;
    parent->right = right;

    // root right right child
    parent = parent->right;
    left = (Node *)xmalloc(NULL, sizeof(Node));
    right = (Node *)xmalloc(NULL, sizeof(Node));
    left->value = "d";
    left->left = NULL;
    left->right = NULL;
    right->value = "e";
    right->left = NULL;
    right->left = NULL;
    parent->left = left;
    parent->right = right;
}

void preOrder(Node *current) {
    if (current == NULL) {
        return;
    }

    showNodeValue(current);
    preOrder(current->left);
    preOrder(current->right);
}

void inOrder(Node *current) {
    if (current == NULL) {
        return;
    }

    inOrder(current->left);
    showNodeValue(current);
    inOrder(current->right);
}

void postOrder(Node *current) {
    if (current == NULL) {
        return;
    }

    postOrder(current->left);
    postOrder(current->right);
    showNodeValue(current);
}

void showNodeValue(Node *node) {
    printf("value = %s\n", node->value);
}

void *xmalloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    }

    return realloc(ptr, size);
}
