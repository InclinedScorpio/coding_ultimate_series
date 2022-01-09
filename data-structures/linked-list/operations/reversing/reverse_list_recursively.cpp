#include<iostream>

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

void insertAtHead(Node* &node, int data) {
    if(node==NULL) {
        node = new Node(data);
        return;
    }

    Node* temp = node;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

void iterateLinkedList(Node* head) {
    while(head!=NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

/**
 * COMPLEXITY: O(N) - all nodes visited once
 * LOGIC: Keep assigning next of next (Adress in next of next node) to current node
 *  > From last node return the node which will act as head now
 *  > keep assigning current node's next as NULL
 * - Think in perspective of 2 nodes at first! Then start thinking about multiple nodes
 * 
 */ 
Node* reverseLinkedList(Node* node) {
    if(node->next==NULL) {
        return node;
    }
    Node* newHead = reverseLinkedList(node->next);
    node->next->next = node;
    node->next = NULL;
    return newHead;
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    Node* head = NULL;
    for(int i: arr) {
        insertAtHead(head, i);
    }
    head = reverseLinkedList(head);
    iterateLinkedList(head);
}