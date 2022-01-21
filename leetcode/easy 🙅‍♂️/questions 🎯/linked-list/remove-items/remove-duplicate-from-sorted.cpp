// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* saveHead = head;
        while(head) {
            
            // keep checking head next data till it's different
            ListNode* nodeChecker = head->next;
            while(nodeChecker && head->val==nodeChecker->val) {
                nodeChecker = nodeChecker->next;
            }
            
            // once it's different link it and move to that node
            head->next = nodeChecker;
            head = nodeChecker;
            
            // repeat
        }
        return saveHead;
    }
};