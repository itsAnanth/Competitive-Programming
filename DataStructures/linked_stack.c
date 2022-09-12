#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Stack {
    int size;
    struct Node * first;
};

typedef struct Stack Stack;
typedef struct Node Node;

void push(Stack *, int);
Node * pop(Stack *);
void print(Stack *);

int main() {
    Stack * st = (Stack*)malloc(sizeof(Stack));
    st->size = 0;
    st->first = NULL;

    push(st, 5);
    push(st, 2);
    push(st, 1);
    
    print(st);
    pop(st);
    print(st);
    return 0;
}

Node * pop(Stack * s) {
    if (!s->size) return NULL;
    Node * curr = s->first, * prev = NULL;
    
    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }
    
    prev->next = NULL;
    s->size--;
    return curr;
}

void print(Stack * s) {
    Node * curr = s->first;
    
    while(curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void push(Stack * s, int data) {
    Node * n = (Node*)malloc(sizeof(Node)), * curr = NULL;
    n->data = data;
    n->next = NULL;
    
    if (!s->size) {
        s->first = n;
        s->size++;
    } else {
        curr = s->first;
        while(curr->next) {
            curr = curr->next;
        }
        curr->next = n;
        s->size++;
    }
}
