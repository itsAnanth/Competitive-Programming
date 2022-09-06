// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

typedef struct Node Node;

Node * createNode(int);
void print(Node**);
void insert(Node**, int);


int main() {
    Node * root = (Node*)malloc(sizeof(Node));
    root = NULL;
    
    
    insert(&root, 15);
    insert(&root, 10);
    insert(&root, 25);
    insert(&root, 7);

    print(&root);

    return 0;
}

void print(Node ** n) {
    if (*n) {
        print(&(*n)->left);
        printf("%d ", (*n)->data);
        print(&(*n)->right);
    }
}



Node * createNode(int data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->left = newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

void insert(Node ** n, int d) {
    if (!(*n)) {
        *n = createNode(d);
    } else if (d <= (*n)->data)
        insert(&((*n)->left), d);
    else 
        insert(&((*n)->right), d);
}
