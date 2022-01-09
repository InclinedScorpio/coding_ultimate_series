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
// Don't perform iterative approach on these kind of question which screams to use recursive approach :)
/**
 * LOGIC: Follow recursive approach when problem has similar things to perform
 * - Like here we are require to reverse in set (reverse problem in set of k)
 * 
 * 1. In set of k, first element will accept further node and last one will be returned back
 * 2. Above point may create confusion so it's better to scratch and test
 * 
 * 
 * Q) 1 2 3 4 5 6 7 8  ||  K=3
 * A) 3 2 1 6 5 4 8 7
 */ 
Node* kReverseList(Node* node, int k) {
    if(node==NULL) { // base Condition
        return NULL;
    }
    int index = 0;

    Node* prev = NULL;
    Node* curr = node;
    
    // first element will accept further node- so save it
    Node* saveFirstNodeAsHead = curr;
    while(index<k && curr!=NULL) {
        Node* nextOne = curr->next;

        curr->next = prev;
        prev = curr;
        curr= nextOne;
        index++;
    }
    // take prev as currHead as due to condition, curr will be one step ahead!
    Node* currHead = prev;

    if(curr!=NULL) {
        saveFirstNodeAsHead->next = kReverseList(curr, k);
    }

    // last one will be returned back
    return currHead;
}

int main()
{
    Node* head = NULL;
    head = insertAtHead(head, 8);
    head = insertAtHead(head, 7);
    head = insertAtHead(head, 6);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);

    printList(head);
    cout<<endl<<"***** REVERSE K ********"<<endl;
    head = kReverseList(head, 3);
    printList(head);
}
