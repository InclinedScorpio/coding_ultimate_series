/**
 * QUESTION: Given 2 sorted linked list
 * - Merge them to form a single sorted linked list
 * - Don't use any extra space
 * 
 * LOGIC: Basic, use 2 pointer, for current position of 2 LL
 * - And use a currPtr to point to the current node
 * 
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node(int val) {
            this->val = val;
            this->next = NULL;
        }
};

Node* insertAtHead(Node* head, int val) {
    if(!head) return new Node(val);
    Node* temp = head;
    while(temp && temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}


Node* mergeSortedLinkedList(Node* headTop, Node* headBottom) {
    Node* headPtr = headTop->val > headBottom->val ? headBottom : headTop;
    Node* currPtr = headPtr;

    if(currPtr == headTop)  {
        headTop = headTop->next;
    }
    else  {
        headBottom = headBottom->next;
    }

    while(headTop && headBottom) {
        if(headTop->val < headBottom->val) {
            currPtr->next = headTop;
            currPtr = currPtr->next;
            headTop = headTop->next;
        } else {
            currPtr->next = headBottom;
            currPtr = currPtr->next;
            headBottom = headBottom->next;
        }
    }

    if(headTop) currPtr->next = headTop;
    if(headBottom) currPtr->next = headBottom;
    return headPtr;
}

int main() {
    vector<int> top = {1, 5, 7, 10, 12, 999};
    vector<int> bottom = {2, 3, 6, 8, 9, 10, 11, 12};
    Node* headTop=NULL;
    Node* headBottom=NULL;
    for(int i: top) {
        headTop = insertAtHead(headTop, i);
    }
    for(int i: bottom) {
        headBottom = insertAtHead(headBottom, i);
    }

    Node* head = mergeSortedLinkedList(headTop, headBottom);
    while(head) {
        cout<<head->val<<" ";
        head = head->next;
    }
}