#include<iostream>  
#include<fstream>
#include<cstring>
#include<math.h>

using namespace std;

class Node {
    public:
        int val;
        Node* next;

        Node(int val, Node* next=NULL) {
            this->val = val;
            this->next = next;
        }
};

Node* insertAtHead(Node* head, int val) {
    return new Node(val, head);
}

void printList(Node* head) {
    while(head!=NULL) {
        cout<<head->val<<" ";
        head = head->next;
    }
}

/**
 * ITERATIVE APPROACH
 * COMPLEXITY: O(N)
 * LOGIC: 3 ptr are required for storing current, prev and next
 * - Main logic is just to assign next of node to previous while saving the next node so it isn't lost
 *
 *  
 * SPACECOMPLEXITY: Less than Iterative - It's O(1) as stacks are not created
 *
 */ 
Node* reverseLinkedList(Node* head) {

    // prev, curr, nextOne
    Node* prev = NULL;
    Node* curr = head;

    while(curr!=NULL) {
        Node* nextOne = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextOne;
    }
    return prev;
}

int main()
{
    Node* head = new Node(0);
    head = insertAtHead(head, 1);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 6);

    printList(head);
    cout<<endl<<"***** REVERSING ********"<<endl;
    head = reverseLinkedList(head);
    printList(head);
}
