// https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/**
 * LOGIC: Basic only
 * - 4 conditions are there and are clearly coded
 * COMPLEXITY: O(N) N=>Length of bigger List
 */ 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0, carry=0;
        ListNode* prev=NULL;
        ListNode* head=NULL;
        
        while(l1 || l2) {
            ListNode* node = new ListNode();

            if(l1 && l2) {
                int currSum = l1->val + l2->val + carry;
                if(currSum>9) {
                    carry=floor(currSum/10);
                    currSum = currSum%10;
                } else carry = 0;
                node->val=currSum;
                
            } else if (l1 && !l2) {
                
                int currSum = l1->val + carry;
                if(currSum>9) {
                    carry=floor(currSum/10);
                    currSum = currSum%10;
                } else carry = 0;
                node->val=currSum;
                
            } else if (!l1 && l2) {
                int currSum = l2->val + carry;
                if(currSum>9) {
                    carry=floor(currSum/10);
                    currSum = currSum%10;
                } else carry = 0;
                node->val=currSum;
                
            } 
            if(!head) head = node;
            if(prev) prev->next = node;
            prev = node;
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry>0) {
            ListNode* node = new ListNode(carry);
            prev->next = node;
        }
        return head;
    }
};
