// https://leetcode.com/problems/rotate-list/

/**
 * LOGIC: Understand what needs to be done
 * - Use sheet to understand how to merge bigger k to the length of list
 * - Take some time to draw and understand how to proceed
 * - For edge case, use if whenever required
 * 
 * COMPLEXITY: O(N)
 */ 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return 0; // edge case
        ListNode* saveHead = head;
        int count=0;
        
        // find the length of list
        while(saveHead) {
            saveHead = saveHead->next;
            count++;
        }
        
        // find the jumps to made to reach point from where to cut out connection
        int rotateFrom = count - (k%count);
        if(rotateFrom == count) return head;
        
        // jump to that node from where to remove connection & remove connection
        saveHead = head;
        while(--rotateFrom) saveHead = saveHead->next;
        ListNode* saveNext = saveHead->next;
        saveHead->next=NULL;
        
        // now go to end and join head to it & return stored head above
        ListNode* returnHead = saveNext;
        while(saveNext && saveNext->next) saveNext = saveNext->next;
        saveNext->next = head;
        return returnHead;
    }