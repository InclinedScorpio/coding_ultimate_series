// https://leetcode.com/problems/reverse-linked-list/

/**
 * LOGIC: Reversing linked list iteratively is just game of ptr's
 * NOTE: I have taken 3 Ptr, you can take even 2 (p1 is basically node->next)
 * - Let's say current node is "node"
 * - node-> next is "p1"
 * - node-> next -> next is "p2"
 * - p2 will help you to keep disconnected linked list under your control
 * 
 * COMPLEXITY: O(N)
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // handle edge cases
        if(!head) {
            return NULL;
        }
        if(!head->next) {
            return head;
        }
        
        // main op
        ListNode* node = head, *p1=node->next, *p2;
        while(p1) {
            p2 = p1->next;
            p1->next = node;
            if(node==head) node->next = NULL; //disconnect head's next
            
            node=p1;
            p1 = p2;
        }
        return node;
            
    }
};