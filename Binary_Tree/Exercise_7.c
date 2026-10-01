/*7) Verificar se é BST
Implemente uma função que, dada uma árvore binária qualquer,
determine se ela satisfaz as propriedades de uma árvore binária de busca.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
bool isBSTUtil(Node* node, long long min, long long max) {
    if (node == NULL) {
        return true;
    }
    if (node->data < min || node->data > max) {
        return false;
    }
    return isBSTUtil(node->left, min, (long long)node->data - 1) &&
           isBSTUtil(node->right, (long long)node->data + 1, max);
}
bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
int main() {
    Node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    if (isBST(root)) {
        printf("A árvore é uma BST\n");
    } else {
        printf("A árvore não é uma BST\n");
    }

    freeTree(root);
    return 0;
}

