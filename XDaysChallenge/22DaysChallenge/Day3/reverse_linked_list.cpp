// https://leetcode.com/problems/reverse-linked-list/description/

/**
 * Question requires only understanding of linked list and pointers manipulation
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* n;
        ListNode* c;
        if(!head) return NULL;
        if(!head->next) return head;
        c = head;
        n = head->next;
        int cal=0;
        while(n) {
            ListNode* save = n->next;
            n->next = c;
            if(cal++==0) c->next = NULL;
            c = n;
            n = save;
        }
        return c;
    }
};