#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node * next;
    int data;
};

typedef struct node Node;

Node * createNode(int);
void insertNodeLast(Node**, int);
void print(Node*);
int insertNodeBefore(Node**, int, int);
int insertNodeAfter(Node**, int, int);

int main() {
    
    Node * head = malloc(sizeof(head));
    head = NULL;
    int i;
    printf("Enter number of nodes\n");
    scanf("%d", &i);
    
    
    for (int j = 0; j < i; j++) {
        int temp;
        printf("Enter %d node data\n", j + 1);
        scanf("%d", &temp);
        insertNodeLast(&head, temp);
    }
    
    print(head);
    insertNodeBefore(&head, 5, 50);
    insertNodeAfter(&head, 50, 100);
    print(head);

    return 0;
}

void print(Node * head) {
    Node * ptr = head;
    while (ptr->next) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}

void insertNodeLast(Node ** head, int data) {
    Node * newnode = createNode(data);
    if (!*head) {
        *head = newnode;
    } else {
        Node * ptr = *head;
        while (ptr->next) {
            ptr = ptr->next;
        }
        
        ptr->next = newnode;
    }
}

int insertNodeBefore(Node ** head, int target, int data) {
    Node * newnode = createNode(data);
    Node * ptr = *head;
    
    if (ptr->data == target) {
        newnode->next = *head;
        *head = newnode;
        return 1;
    }
    
    while (ptr->next) {
        if (ptr->next->data != target) continue; 
            
        Node * temp = ptr->next;
        newnode->next = temp;
        ptr->next = newnode;
        return 1;
        
    }
    
    return 0;
}

int insertNodeAfter(Node ** head, int target, int data) {
    Node * newnode = createNode(data);
    Node * ptr = *head;

    
    while (ptr) {
        if (ptr->data != target) continue; 
            
        Node * temp = ptr->next;
        newnode->next = temp;
        ptr->next = newnode;
        return 1;
        
    }
    
    return 0;
}

Node * createNode(int data) {
    Node * newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
