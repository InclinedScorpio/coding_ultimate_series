// https://leetcode.com/problems/linked-list-cycle/description


/**
 * LOGIC: This is a slow and a fast pointer problem.
 * 
 * 
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        if(!head || !head->next) return false;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            if(slow==fast) {
                return true;
            }
        }
        return false;
    }
};