// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * LOGIC: Floyd algo says that keep 2 ptr - slow & fast
 * - Slow will take 1 step, fast will take 2 steps
 * - This above algo will help to check if there is any cycle
 * 
 * - Now, to check start point of cycle, the same algo states that
 * - We can find that too after finding the intersection of slow & fast
 * 
 * - Basically we just need to move slow + one another slow from head
 * - The point they meet is the point where cycle starts
 * 
 * Q) What's start of cycle?
 * A) Where 2 pointers are converging to a single node is called start of cycle
 * TIP: (This same concept can be used to find Duplicate item also in case of array!)
 * 
 * Q) Is there proof of this that after intersection if keep moving move both slow ptr 1 step we get start of cycle?
 * A) Yes, 
 * 
 * Let's say we have some nodes and they form a cycle
 * 
 *                              D     E     F
 *                 B     C                       G
 *                              J      I      H
 * 
 * Now from the view it's clear that C is the start of cycle
 * - Now let's say, from B to C length is 'p'.
 * - From J to C length is 'x'.
 * - & from D-E-F-G-H-I-J (D-J) length is 'c'.
 * 
 * Now let's say slow & fast met at 'J' ( It will be always before the start of cycle)
 * 0) We know, 2 * slow = fast  (fast is 2 times of slow)
 * 
 * 1) Distance covered by slow -> p + c
 * 2) Distance covered by fast -> p + c + x + c -> 2c + p + x
 * 
 * Keep 1) and 2) in 0)
 *  -> 2 * (p + c) = 2c + p + x
 *  -> 2p + 2c = 2c + p + x
 *  -> p = x 
 * 
 * Hence proved, the slow(from merger of fast and slow) and newSlow pointer(from head)...
 * ... if taken 1-1 steps will meet at the point where cycle starts!
 * 
 */ 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next || !head->next->next) return NULL;
        ListNode* slow=head->next;
        ListNode* fast=head->next->next;
        
        while(fast && fast->next && slow!=fast ) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(!fast || !fast->next) {
            return NULL;
        }
        
        ListNode* slowFinder=head;
        while(slow!=slowFinder) {
            slow = slow->next;
            slowFinder = slowFinder->next;
        }
        
        return slow;
    }
};
