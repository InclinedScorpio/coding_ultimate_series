// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Question is special - requires understanding of 2 pointer approach to get nth node from end
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* first = head;
        ListNode* second = head;
        // skip second to n+1
        int skipCount = n+1;
        while(skipCount) {
            if(second) second = second->next;
            else if(skipCount==1) return head->next;
            else return head;
            skipCount--;
        }

        // now just take second to null
        while(second) {
            first = first->next;
            second = second->next;
        }
        first->next = first->next->next;
        return head;
    }
};