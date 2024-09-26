// https://leetcode.com/problems/add-two-numbers/

/**
 * Problem requires understanding of linked list
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
        ListNode* newResult = NULL;
        ListNode* headResult = NULL;
        int carry=0;
        while(l1 && l2) {
            int storeResult= l1->val + l2->val + carry;
            carry = storeResult>=10 ? 1 : 0;
            storeResult = storeResult % 10;
            if(!headResult) {
                headResult = new ListNode(storeResult);
                newResult = headResult;
            } else {
                newResult->next = new ListNode(storeResult);
                newResult = newResult->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int storeResult= l1->val + carry;
            carry = storeResult>=10 ? 1 : 0;
            storeResult = storeResult % 10;
            if(!headResult) {
                headResult = new ListNode(storeResult);
                newResult = headResult;
            } else {
                newResult->next = new ListNode(storeResult);
                newResult = newResult->next;
            }
            l1 = l1->next;
        }
        while(l2) {
            int storeResult= l2->val + carry;
            carry = storeResult>=10 ? 1 : 0;
            storeResult = storeResult % 10;
            if(!headResult) {
                headResult = new ListNode(storeResult);
                newResult = headResult;
            } else {
                newResult->next = new ListNode(storeResult);
                newResult = newResult->next;
            }
            l2 = l2->next;
        }
        if(carry) {
            newResult->next = new ListNode(1);
        }

        return headResult;
    }
};