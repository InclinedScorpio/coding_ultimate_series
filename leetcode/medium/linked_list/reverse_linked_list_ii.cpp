// https://leetcode.com/problems/reverse-linked-list-ii/

/**
 * LOGIC: Must know how to reverse a linked list
 * - It's just a variation, you need to pick left and right and do reverse among them
 * - And then rewire the connection once reversed!
 * 
 * COMPLEXITY: O(N)
 */ 
class Solution {
public:
    void reverseList(ListNode* left, ListNode* right) {
        ListNode* prevNode = left;
        ListNode* nextNode = prevNode->next;
        ListNode* reverseTill = right->next;
        while(nextNode!=reverseTill) {
            ListNode* save = nextNode->next;
            nextNode->next = prevNode;
            prevNode = nextNode;
            nextNode = save;
        }
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftNode = head;
        ListNode* rightNode = head;
        --left;--right;
        ListNode* saveLeftsPrev = NULL;
        if(left==1)
            saveLeftsPrev = leftNode;
        while(left--) {
            leftNode = leftNode->next;
            if(left==1)
                saveLeftsPrev = leftNode;
        }
            
        while(right--)
            rightNode = rightNode->next;
        ListNode* saveRightsNext = rightNode->next;
        // reverse Call! 
        reverseList(leftNode, rightNode);

        if(saveLeftsPrev) saveLeftsPrev->next = rightNode;
        else head = rightNode;
        
        leftNode->next = saveRightsNext;
        return head;
    }
};