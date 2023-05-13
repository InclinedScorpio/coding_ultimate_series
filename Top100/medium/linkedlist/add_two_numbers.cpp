// https://leetcode.com/problems/add-two-numbers/


/**
 * 
 * Addition of 2 linkedlists
 */ 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry=0;
        ListNode* resultNode = NULL;
        ListNode* headNode = NULL;
        while(l1 || l2) {
            ListNode* newNode;
            int toAdd=0;
            if(l1 && l2) {
                toAdd = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            } else if(l1) {
                toAdd = l1->val + carry;
                l1 = l1->next;
            } else {
                toAdd = l2->val + carry;
                l2 = l2->next;
            }

            if(toAdd>9) {
                carry=1;
                toAdd=toAdd%10;
            } else carry=0;

            newNode = new ListNode(toAdd);

            if(!resultNode) {
                resultNode = newNode;
                headNode = resultNode;
            } else {
                resultNode->next = newNode;
                resultNode = resultNode->next;
            }
        }
        if(carry) {
            ListNode* newNode = new ListNode(1);
            resultNode->next = newNode;
        }
        return headNode;
    }
};