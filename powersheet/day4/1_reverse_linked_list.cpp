// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {

        if(!head || !head->next) return head;
        ListNode* c;
        ListNode* n;
        ListNode* saven;
        c=head;
        n=c->next;
        while(n) {
            saven=n->next;
            n->next = c;
            c = n;
            n= saven;
        }

        head->next=NULL;
        return c;
    }
};

// [1,2,3,4,5]
// c = 1
// n = 2

// c, n, saven



// while n not null

// saven=n->next;
// n->next=c;
// c = n;
// n = saven;







