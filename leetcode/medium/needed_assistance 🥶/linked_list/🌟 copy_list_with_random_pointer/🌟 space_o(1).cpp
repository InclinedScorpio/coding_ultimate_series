// https://leetcode.com/problems/copy-list-with-random-pointer/

/**
 * LOGIC: As no extra memory has to be used
 * - We can wire the new list to existing list in such a way
 * - That list forms as well as random can be known and pointed
 * 
 * - Best method to do is to point real list to new list corresponding nodes
 * - Once done, wire the random
 * - Random is nothing but the node which is pointed's next...
 * -... because that's what the new list's corresponding is!
 * 
 * - Now, just rewire the real list as it was!
 * - return the head of newly formed list
 * 
 * COMPLEXITY: O(N)
 * SPACE: O(1)
 * 
 */ 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        // create the new linked list above existing & do wiring
        // current nodes next -> to new nodes corresponding
        // new nodes next next -> next node (original)
        Node* saveHead = head;
        while(head) {
            Node* newNode = new Node(head->val);
            newNode->next = head->next;
            head->next = newNode;
            head = newNode->next;
        }
        head = saveHead;
        Node* saveNewHead = head->next; // new list's head
        
        // update the random pointers
        // DO NOT RESET WIRING, else in case when random points to previous, it won't work as expected due to obvious reasons
        while(head) {
            Node* temp = head->next;
            if(head->random) 
                temp->random = head->random->next;
            head = head->next->next;
        }
        
        // Reset the wiring so original list isn't altered
        head = saveHead;
        while(head) {
            Node* temp = head->next;
            head->next = head->next->next;
            if(temp->next) {
                temp->next= temp->next->next;
            }
            head = head->next;
        }
        
        // return the head of new list formed
        return saveNewHead;
    }
};