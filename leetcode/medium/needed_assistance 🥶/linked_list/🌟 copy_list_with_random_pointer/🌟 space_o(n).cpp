// https://leetcode.com/problems/copy-list-with-random-pointer/

/**
 * 
 * LOGIC: Main point to note is to use map with Node*, Node*
 * - So that we can keep the address of corresponding nodes
 * - And can refer them when wiring the random pointers
 * 
 * 
 * COMPLEXITY: O(N)
 * SPACE: O(N)
 * Q) Can we improve the space?
 * A) Yes, we can do constant space!
 * 
 */ 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* saveHead = head;
        Node* newHead = NULL;
        Node* saveNewHead = NULL;
        
        unordered_map<Node*, Node*> store;
        store[NULL] = NULL;
        while(head) { // create new list
            Node* newNode = new Node(head->val);
            store[head] = newNode;
            if(!newHead) {
                newHead = newNode;
                saveNewHead = newHead;
            }
            else {
                newHead->next = newNode;
                newHead = newNode;
            }
            head = head->next;
        }
        
        //wire up random ptr
        head = saveHead;
        newHead = saveNewHead;
        while(head) {
            newHead->random = store[head->random];
            head = head->next;
            newHead = newHead->next;
        }
        
        return saveNewHead;
    }
};