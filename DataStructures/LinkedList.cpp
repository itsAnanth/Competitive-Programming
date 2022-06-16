#include <bits/stdc++.h>

template <typename T>
void print(T arg) {
    std::cout << arg << std::endl;
}


class Node {
    public:
    int data;
    Node * next = NULL;
    Node(int data) {
        this->data = data;
    }
};

class List {
    public:
    Node * head = NULL;
    int size = 0;
    List() {};
    
    void push(int data) {
        Node * newnode = new Node(data);
        Node * _head = this->head;
        
        size++;
        if (!_head) {
            this->head = newnode;
            return;
        }
        while (_head->next) {
            _head = _head->next;
        }
            
        _head->next = newnode;
    }
    
    Node* operator[](int i) {
        int ptr = 0;
        Node * element = this->head;
        
        if (i > this->size - 1) return element;
        
        while (ptr < i && element->next) {
            element = element->next;
            ptr++;
        }

        return element;
    }
};

std::ostream& operator<<(std::ostream& os, const List v) {
    os << "[";
    Node * curr = v.head;
    if (!curr) {
        os << "Empty List";
    }
    
    while (curr) {
        os << curr->data;
        (curr->next) && (os << ", ");
        curr = curr->next;
    }
    os << "]\n";
    return os;
}

int main() {
    List list;
    list.push(1);
    list.push(2);
    list.push(10);
    list.push(20);
    print(list);
    
    return 0;
}
