// https://leetcode.com/problems/merge-two-sorted-lists/

/**
 * Consider list1 & 2 as the latest ptr for node
 * Now compare and assign them to our newly created list (sortedMergedList)
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // edge cases
        if(list1 == NULL && list2 == NULL ) {
            return NULL;
        }
        
        if(list1 == NULL ) {
            return list2;
        }
        
        if(list2 == NULL ) {
            return list1;
        }
        
        ListNode* sortedMergedList;
        ListNode* head;
        
        if(list1->val < list2-> val) {
            sortedMergedList = list1;
            list1 = list1->next;
        } else {
            sortedMergedList = list2;
            list2 = list2->next;
        }
        head = sortedMergedList;
        
        while(!(list1 == NULL && list2==NULL)) {
            if(list1 == NULL) {
                sortedMergedList->next = list2;
                sortedMergedList = sortedMergedList->next;
                list2 = list2->next;
                continue;
            }
            
            if(list2 == NULL) {
                sortedMergedList->next = list1;
                sortedMergedList = sortedMergedList->next;
                list1 = list1->next;
                continue;
            }
            
            if(list1->val < list2-> val) {
                sortedMergedList->next = list1;
                list1 = list1->next;
            } else {
                sortedMergedList->next = list2;
                list2 = list2->next;
            }
            sortedMergedList = sortedMergedList->next;
        }
        return head;
        
    }
};