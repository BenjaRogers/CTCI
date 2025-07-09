#include <iostream>
#include <set>
#include "nodeClass.h"

void removeDups(Node head) {
    std::set<int> dupSet;
    Node* n = &head;

    while (n->next != nullptr) {
        if(dupSet.find(n->data) == dupSet.end()) {
            dupSet.insert(n->data);
        }
        else {
            head.deleteNode(&head, n->data);
        }
        n = n->next;
    }
}
int main() {
    
    //Test
    int testArr[] = {1,2,3,4,5,5,6,7};
    Node n1 = Node(testArr[0]);
    // Load array elements to linked list 
    for (int i=1; i<7; i++) {
        n1.appendToTail(testArr[i]);
    }
    n1.printList();
    removeDups(n1);
    n1.printList();
    // Node n = Node(10);
    // std::cout << "n1 " << &n << " " << n.data << " " << n.next << "\n";
    // n.appendToTail(11);
    // std::cout << "n1 " << &n << " " << n.data << " " << "n2 " << n.next << " " << n.next->data << "\n";
    // n.deleteNode(&n, 11);
    // std::cout << "n1 " << &n << " " << n.data << " " << "n2 " << n.next << " " << "\n";
}