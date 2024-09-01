https://leetcode.com/problems/merge-two-sorted-lists/

/**
 * Question requires only understanding of linked list and pointers manipulation
 * 
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* store;
        if(list1 && list2 && list1->val<list2->val) {
            store = list1;
            list1 = list1->next;
        } else if(list1 && list2 && list1->val>=list2->val) {
            store=list2;
            list2 = list2->next;
        }
        if(!store) {
            if(list1) {
                store = list1;
                list1 = list1->next;
            }
            if(list2) {
                store = list2;
                list2 = list2->next;
            }
        }

        ListNode* storeHead = store;
        cout<<" head: "<<(store&&store->val)<<" ";
        
        while(list1 && list2) {
            if(list1 && list2 && list1->val<list2->val) {
                store->next = list1;
                store = store->next;
                list1 = list1->next;
            } else if(list1 && list2 && list1->val>=list2->val) {
                store->next=list2;
                store = store->next;
                list2 = list2->next;
            }
        }

        if(list2) {
            while(list2) {
                store->next=list2;
                store = store->next;
                list2 = list2->next;
            }
        }
        if(list1) {
            while(list1) {
                store->next=list1;
                store = store->next;
                list1 = list1->next;
            }
        }

        return storeHead;
        
    }
};