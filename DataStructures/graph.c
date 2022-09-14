// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Graph {
    struct Node ** nodes;
    int size;
    int max;
};

typedef struct Graph Graph;
typedef struct Node Node;

void addNode(Graph*, int);
void addEdge(Graph*, int, int);
void printNodes(Graph*);
void printEdges(Graph*, int);
Node * createNode(int);


int main() {
    Graph * gr = (Graph*)malloc(sizeof(Graph));
    gr->max = 1;
    gr->size = 0;
    gr->nodes = (Node**)malloc(sizeof(Node*) * gr->max);


    addNode(gr, 6);
    addNode(gr, 2);
    addNode(gr, 3);
    addNode(gr, 4);
    
    addEdge(gr, 0, 1);
    addEdge(gr, 0, 2);
    addEdge(gr, 0, 3);
    
    printEdges(gr, 0);


    return 0;
}

void printEdges(Graph * g, int source) {
    Node * curr = g->nodes[source]->next;
    
    printf("\n[");
    
    while (curr) {
        printf("%d", curr->data);
        curr = curr->next;
        curr && printf(", ");
    }
    printf("]\n");
}

void printNodes(Graph * g) {
    printf("\n[");
    
    for (int i = 0; i < g->size; i++) {
        printf("%d", g->nodes[i]->data);
        
        if (i != g->size - 1)  
            printf(", ");
    }
    
    printf("]\n");
}

Node * createNode(int data) {
    Node * n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void addEdge(Graph * g, int source, int destination) {
    if (source > g->size || destination > g->size)
        printf("Graph data out of bounds\n");
    else {
        Node * s = g->nodes[source], * tmp = g->nodes[destination];
        
        tmp->next = NULL;
        
        while (s->next) {
            s = s->next;
        }      
    
        s->next = tmp;
    }

    
}
void addNode(Graph * g, int data) {
    if (g->size >= g->max) {
        g->nodes = (Node**)realloc(g->nodes, sizeof(Node*) * 2 * g->max);
        g->max *= 2;
    }

    Node * newNode = createNode(data);
    g->nodes[g->size] = newNode;
 
    g->size++;
}
