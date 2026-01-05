// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

/**
 * LOGIC:
 * Just set the left, right pointer at right place 
 * move left slow, and right fast(x2)
 * think and figure out and then code
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        ListNode* saveHead=head;
        ListNode* left=head;
        if(!head->next) return NULL;
        ListNode* right = head->next->next;

        while(right && right->next) {
            right = right->next->next;
            head = head->next;
        }
        head->next = head->next->next;
        return saveHead;
        
    }
};