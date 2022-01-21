// https://leetcode.com/problems/linked-list-cycle/

/**
 * LOGIC: Floyd Cycle Finding Algorithm
 * - Keep 2 ptr, 1 slow, 1 fast
 * - slow takes 1 step, fast takes 2 steps
 * - If there will be circle, slow and fast will meet somwhere
 * - ...if they meet, loop is present
 * 
 */ 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        if(!head || !head->next || !head->next->next) {
            return false;
        }
        ListNode* fast = head->next->next;
        while(true) {
            if(slow==fast) {
                return true;
            }
            if(fast->next && fast->next->next) {
                fast = fast->next->next;
                slow = slow->next;
            } else {
                return false;
            }
        }
    }
};