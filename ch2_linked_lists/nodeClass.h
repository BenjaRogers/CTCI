#include <iostream>

class Node {
    public:
        Node *next = nullptr;
        int data;

    Node(int d) {
        data = d;
    }
    void printList() {
        Node* n = this;
        std::cout << "[" << n->data;
        while (n ->next != nullptr) {
            n = n->next;
            std::cout << n->data;
        }
        if (n->next == nullptr) {
            std::cout << "]" << "\n";
        }
    }
    void appendToTail(int d) {
        Node* end = new Node(d);
        //std::cout << &end << " " << end.data << "\n";
        Node* thisNode = this;
        //std::cout << &n << "\n";
        while (thisNode->next != nullptr) {
            thisNode = thisNode->next;
        }
        thisNode->next = end;
    }
    Node deleteNode(Node* head, int d) {
        Node* n = head;
        if (n->data == d) {
            return *head;
        }

        while (n->next != nullptr) {
            if(n->next->data == d) {
                n->next = n->next->next;
                return *head;
            }
            n = n->next;
        }
        return *head;
    }
};