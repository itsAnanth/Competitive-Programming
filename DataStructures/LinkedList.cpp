#include <bits/stdc++.h>


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> v) {
    os << "[";
    for (int i = 0; i < v.size(); i++) {
        os << v[i];
        (i != v.size() - 1) && (os << ", ");
    }
    os << "]\n";
    return os;
}


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
    List() {};
    
    void push(int data) {
        Node * newnode = new Node(data);
        Node * _head = this->head;
        
        if (!_head) {
            this->head = newnode;
            return;
        }
        while (_head->next) {
            _head = _head->next;
        }
            
        _head->next = newnode;
    }
};

std::ostream& operator<<(std::ostream& os, const List v) {
    os << "[";
    Node * curr = v.head;
    if (!curr) {
        os << "Empty List\n";
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
    print(list);

    return 0;
}
