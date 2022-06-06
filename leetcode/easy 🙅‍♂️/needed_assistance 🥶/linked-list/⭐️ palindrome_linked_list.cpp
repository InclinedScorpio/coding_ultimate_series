// https://leetcode.com/problems/palindrome-linked-list/

/**
 * LOGIC: Doing using Recursion rather iterative approach for O(N)
 * - Recursive approach will help us to reach last node...
 * - ...and keep returning that node which we can ultimately compare
 * 
 * - Keep a temp pointer at head which can keep checking node from start to end
 * - And operation inside recursion will carry the nodes from last
 *  
 * 
 * COMPLEXITY: O(N)
 * SPACE: O(N)
 * 
 * NOTE: For better version (no extra space) scroll down!
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


/**
 * LOGIC: We will just find middle
 * - and reverse second half
 * - Now just step by step go ahead from 0 and middle
 * - If all same then it's palindrome
 * 
 * - No extra space is used in this approach
 * - Also if list doesn't need to be changed then reverse again after finding questions result
 * 
 * COMPLEXITY: O(N)
 * SPACE: O(1)
 * 
 */ 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // it's odd
        if(fast) slow = slow->next;
        
        // slow to end reverse
        ListNode* left = NULL;
        ListNode* mid = slow;
        while(mid) {
            ListNode* save = mid->next;
            mid->next = left;
            left = mid;
            mid = save;
        }
        slow = left;
        
        while(slow) {
            if(head->val!=slow->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};