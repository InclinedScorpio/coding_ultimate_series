// https://leetcode.com/problems/palindrome-linked-list/

/**
 * LOGIC: Doing using Recursion rather iterative approach for O(N)
 * - Recursive approach will help us to reach last node...
 * - ...and keep returning that node which we can ultimately compare
 * 
 * - Keep a temp pointer at head which can keep checking node from start to end
 * - And operation inside recursion will carry the nodes from last
 *  
 */ 
class Solution {
public:
    
    ListNode* temp; // store temp for storing head (will help to iterate from start)
    
    bool isPalindromeMod(ListNode* head) {
        if(!head) return true;
        
        // iteration to last
        bool upcomingResult = isPalindromeMod(head->next);

        //recursion operation (compare temp ptr(running from start to end) to current node(running from end to start))
        if(temp->val != head->val) return false;
        temp = temp->next; //increase the ptr running from start to end
        return upcomingResult;
    }
    
    // O(N) 
    bool isPalindrome(ListNode* head) {
        temp = head; // store head to temp
        return isPalindromeMod(head);
    }
};