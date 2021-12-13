#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

/**
 * Both recursive and iterative approach can be used
 * NOTE: Pass by ref (&) is more efficient
 * > In pass by ref, the variable will now have reference to the same heap area
 * 
 */ 
void insertAtHead(Node* &head, int data) { // head contains address(&) of Node* type
    if(head == NULL) {
        head = new Node(data);
        return;
    }
    Node* newHead = new Node(data);
    newHead->next = head;
    head = newHead;
    return;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	Node* head = NULL;
	for(int i: arr) {
		head = insertAtHead(head, i);
	}
}