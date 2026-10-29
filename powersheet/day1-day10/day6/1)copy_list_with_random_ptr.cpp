// https://leetcode.com/problems/copy-list-with-random-pointer/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* saveHead = head;

        Node* copyHead;
        unordered_map<Node*, Node*> store;

        Node* currNode=NULL;
        Node* saveNewHead=NULL;
        while(head) {
            if(currNode) {
                Node* nextNode = new Node(head->val);
                currNode->next = nextNode;
                currNode = nextNode;
            } else {
                currNode = new Node(head->val);
                saveNewHead= currNode;
            }
            
            store[head] = currNode;
            head = head->next;
        }
        Node* result = saveNewHead;
        while(saveHead) {
            saveNewHead->random = store[saveHead->random];
            saveNewHead = saveNewHead->next;
            saveHead = saveHead->next;
        }
        
        return result;
    }
};