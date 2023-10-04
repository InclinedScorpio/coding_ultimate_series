// https://leetcode.com/problems/palindrome-linked-list/

/**
 * Question requires only understanding of recursion and linked list
*/
class Solution {
public:

    ListNode* frontEndPtr;
    bool helper(ListNode* head) {
        if(!head) return true;
        bool result = helper(head->next);
        if(!result) return result;
        if(frontEndPtr->val!=head->val) return false;
        frontEndPtr = frontEndPtr->next;
        return true;
    }
    bool isPalindrome(ListNode* head) {
        frontEndPtr = head;
        return helper(head);
    }
};