// https://leetcode.com/problems/add-two-numbers/?envType=company&envId=amazon&favoriteSlug=amazon-three-months


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
class Solution {
private:
    ListNode* head = nullptr;
    ListNode* iter = nullptr;

    int addNewNode(ListNode*& l1, ListNode*& l2, int totalSum) {
        int carry=0;
        if(!head) {
            int finalVal = totalSum;
            carry = finalVal>9;
            finalVal = finalVal%10;
            head=new ListNode(finalVal);
            iter = head;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            return carry;
        }
        int finalVal = totalSum; 
        carry = finalVal>9;
        finalVal = finalVal%10;
        ListNode* newNode = new ListNode(finalVal);
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
        iter->next = newNode;
        iter = iter->next;
        return carry;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        while(l1 && l2) {
            carry = this->addNewNode(l1, l2, l1->val + l2->val + carry);
        }

        while(l1) {
            carry = this->addNewNode(l1, l2, l1->val + carry);
        }

        while(l2) {
            carry = this->addNewNode(l1, l2, l2->val + carry);
        }

        if(carry) {
            carry = this->addNewNode(l1, l2, 1);
        }
        return head;
    }
};
