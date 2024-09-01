// https://leetcode.com/problems/add-two-numbers/description/

/**
 * 
 * Problem requires understanding of linked list and how to traverse it
 * - Edge cases are - when one list is bigger than other
 * - When carry is generated at the end
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        bool carry = 0;
        ListNode* head=NULL;
        ListNode* nodeIter=NULL;
        while(l1 && l2) {
            int newVal = l1->val + l2->val + carry;
            carry = false;
            if(newVal>9) {
                newVal = newVal - 10;
                carry = true;
            }
            ListNode* newNode = new ListNode(newVal);
            if(head) { // head available
                nodeIter->next = newNode;
                nodeIter = newNode;
            } else { // head not available
                head = newNode;
                nodeIter = head;
            }

            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int newVal = l1->val + carry;
            carry = false;
            if(newVal>9) {
                newVal = newVal - 10;
                carry = true;
            }
            ListNode* newNode = new ListNode(newVal);
            if(head) { // head available
                nodeIter->next = newNode;
                nodeIter = newNode;
            } else { // head not available
                head = newNode;
                nodeIter = head;
            }
            l1 = l1->next;
        }
        while(l2) {
            int newVal = l2->val + carry;
            carry = false;
            if(newVal>9) {
                newVal = newVal - 10;
                carry = true;
            }
            ListNode* newNode = new ListNode(newVal);
            if(head) { // head available
                nodeIter->next = newNode;
                nodeIter = newNode;
            } else { // head not available
                head = newNode;
                nodeIter = head;
            }
            l2 = l2->next;
        }
        if(carry) {
            ListNode* newNode = new ListNode(1);
            nodeIter->next = newNode;
        }
        return head;
    }
};