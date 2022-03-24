// https://leetcode.com/problems/swap-nodes-in-pairs/

/**
 * LOGIC: - Logic can be created by scratch
 * - Here iterative method is used
 * - Only some pointers are taken to do it in linear time complexity
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* saveHead = head->next;
        
        ListNode* r = head;
        ListNode* l;
        ListNode* m;
        ListNode* savePrev=NULL;
        
        while(r && r->next) {
            l = r;
            m = r->next;
            r = r->next->next;
            
            m->next = l;
            l->next = r;
            if(savePrev) {
                savePrev->next = m;
            }
            savePrev=l;
        }
        
        return saveHead;
    }
};
