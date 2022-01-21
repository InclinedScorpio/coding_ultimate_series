// https://leetcode.com/problems/remove-linked-list-elements/

/**
 * LOGIC: Basic
 * - 2 cases -1) if header is target
 * - 2) if any upcoming node is target
 * 
 */ 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // handle head case
        while(head && head->val == val) {
            head = head->next;
        }
        
        // handle non head case
        ListNode* iter = head;
        while(iter && iter->next) {
            if(iter->next->val == val) {
                iter->next = iter->next->next;
            }else {
                iter = iter->next;                
            }
        }
        
        return head;
    }
};
