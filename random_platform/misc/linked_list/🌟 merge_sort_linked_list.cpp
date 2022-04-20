/**
 * LOGIC: Similar to how we do merge sort in vector
 * We can do similarly in LinkedList as well
 * 
 * - Here, like vector, we can't find mid in O(1)
 * - We need to traverse O(N) and find it
 * - We need to divide the list in 2 parts
 * - And once its unit (sorted) we can do "Merge 2 sorted list"
 * 
 * POINT TO NOTE:
 * - We need to put NULL after mid, so we have 2 different linked list
 * - Also, receive the updated result before merging further (shown in code)
 * - Keep fast iter one step ahead initially (mentioned in code) so no infinite recursion on first items
 * 
 * COMPLEXITY:O(NlogN)
 * 
 */ 
#include <iostream>
#include <vector>
#include <map>

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

Node* insertAtLast(Node* head, int val) {
    if(!head) return new Node(val);
    Node* temp = head;
    while(temp && temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}

Node* mergeLL(Node* left, Node* right) {
    Node* head = left->val > right->val ? right : left;
    Node* saveHead = head;
    if(head==left) left = left->next;
    else right = right->next;
    while(left && right) {
        if(left->val > right->val) {
            head->next = right;
            head = head->next;
            right = right->next;
        } else {
            head->next = left;
            head=head->next;
            left = left->next;
        }
    }
    if(left) head->next = left;
    if(right) head->next = right;
    return saveHead;
}

Node* mergeSort(Node* head) {
    if(!head || !head->next) return head;
    // findingMidpoint, so can be divided, we literally will divide the LL btw mid
    Node* midPoint = head;
    Node* fastIter = head->next; // keep faster iterator a step ahead initially
    while(fastIter && fastIter->next) {
        midPoint = midPoint->next;
        fastIter = fastIter->next->next;
    }
    Node* secondHalf = midPoint->next;
    midPoint->next = NULL; // break the bond!
    // midPoint is center  of LL
    head = mergeSort(head); // !STUCK- Didn't took head= , that's why the sorted thing was never taken!
    secondHalf = mergeSort(secondHalf); // !STUCK- Didn't took seconHalf= , that's why the sorted thing was never taken!
    return mergeLL(head, secondHalf);
}

int main() {
    Node* head;
    vector<int> inputs = {3,2,1,6,5,4,8,7, 77,45,600, 13};
    for(int i: inputs) {
        head = insertAtLast(head, i);
    }
    // call
    head = mergeSort(head);
    while(head) {
        cout<<head->val<<" ";
        head = head->next;
    }   
}