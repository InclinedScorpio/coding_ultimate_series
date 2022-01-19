// https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * LOGIC: Count no. of nodes in both the branches
 * 1. Check difference of no. of nodes in both branch
 * 2. Now skip the difference from the branch which is longer.
 * 3. Now, this means before intersection both head are at same difference
 * 4. Now keep moving both head forward and keep checking if they are pointing to same node
 * 5. Once find, return that nodes, that's the one where intersection is happening.
 * 
 */ 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* copyA = headA;
        ListNode* copyB = headB;
        int noOfA=0,noOfB=0;
        
        while(copyA) {
            copyA = copyA->next;
            noOfA++;
        }
        while(copyB) {
            copyB = copyB->next;
            noOfB++;
        }
        
        int noOfNodeDiff = abs(noOfA-noOfB); //1. Diff btw two branch
        
        //2. Now, skip those nodes from longer branch so both head at same difference from intersection
        if(noOfA-noOfB>0) {
            while(noOfNodeDiff) {
                headA = headA->next;    
                noOfNodeDiff--;
            }
        }else {
             while(noOfNodeDiff) {
                headB = headB->next;    
                noOfNodeDiff--;
            }
        }
        
        //4. Now as both head are at same difference, move them forward one by one and return when same
        while(headA!=headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        //5. At this point both headA and headB are pointing to the intersection.
        return headA;
    }
};