// https://leetcode.com/problems/reverse-linked-list/description

/**
 * NOTE: Just 3 pointers game.
 * 
 */ 
class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode* l = NULL;
        ListNode* r = head;
        

        while(r) {
            ListNode* n = r->next;
            r->next = l;
            l=r;
            r=n;
        }
        return l;
    }
};

