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
void traverse(Node**, void(*fn)(Node*, int));
int deleteNode(Node**, int);
int insertNodeBefore(Node**, int, int);
int insertNodeAfter(Node**, int, int);
int search(Node*, int);

void logc(Node* head, int data) {
    printf("%d ", data);
}

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
    
    deleteNode(&head, 100);

    
    traverse(&head, *logc);
    

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

int deleteNode(Node ** head, int data) {
    Node * prev = NULL;
    Node * curr = *head;
    
    if (curr->data == data) {
        *head = curr->next ? curr->next : NULL;
        return 1;
    }
    
    while (curr) {
        if (curr->data == data) {
            prev->next = curr->next;
            return 1;
        }
        
        prev = curr;
        curr = curr->next;
    }
    
    return -1;
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

void traverse(Node** head, void(*fn)(Node*, int)) {
    Node * curr = *head;
    
    while (curr) {
        fn(curr, curr->data);
        curr = curr->next;
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

int search(Node * head, int data) {
    if (!head) return -1;
    
    Node * curr = head;
    int i = 0;
    while (curr) {
        if (curr->data == data) return i;
        i++;
        curr = curr->next;
    }
    
    return -1;
}

Node * createNode(int data) {
    Node * newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
