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

void printLinkedList(Node* head) {
	while(head!=NULL) {
		cout<<head->data<<" ";
		head = head->next;
	}
}

/**
 * COMPLEXITY: O(N)
 * LOGIC: Iterate until that position and insert the node
 * > Make sure to reconfig the pointers
 * 
 */ 
void insertAtPosition(Node* &nodePtr, int data, int position) {
    int index = 0;
    if(position==0) {
        insertAtHead(nodePtr, data);
        return;
    }
    Node* node = nodePtr; // IMPORTANT: we need to create copy otherwise head will move & that will effect head in main fn
    while(position-1!=index++) { // take node to position
        node = node->next;
    }
    Node* temp = node->next;
    Node* newNode = new Node(data);
    node->next = newNode;
    newNode->next = temp;
}

int main() {
	int arr[] = {5, 4, 3, 2, 1};
	Node* head = NULL;
	for(int i: arr) {
		insertAtHead(head, i);
	}
    printLinkedList(head);
    insertAtPosition(head, 9494, 2);
    cout<<"After insertion at position 2"<<endl;
    printLinkedList(head);
}