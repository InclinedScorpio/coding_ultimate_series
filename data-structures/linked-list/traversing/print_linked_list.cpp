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

Node* insertAtHead(Node* head, int data) {
	if(head==NULL) {
		return new Node(data);
	}
	head->next = insertAtHead(head->next, data);
	return head;
}

void printLinkedList(Node* head) {
	while(head!=NULL) {
		cout<<head->data<<" ";
		head = head->next;
	}
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	Node* head = NULL;
	for(int i: arr) {
		head = insertAtHead(head, i);
	}
	printLinkedList(head);
}