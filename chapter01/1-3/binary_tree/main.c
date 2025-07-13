#include <stdio.h>
#include "binary_tree.h"

int main(int argc, char *argv[]) {
    BinaryTree binaryTree;
    buildTree(&binaryTree);

    printf("pre order traversal\n");
    printf("-------------------------------\n");
    preOrder(binaryTree.root);
    printf("\n");

    printf("in order traversal\n");
    printf("-------------------------------\n");
    inOrder(binaryTree.root);
    printf("\n");

    printf("post order traversal\n");
    printf("-------------------------------\n");
    postOrder(binaryTree.root);
    printf("\n");

    return 0;
}
