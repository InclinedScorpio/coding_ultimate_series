// https://leetcode.com/problems/merge-k-sorted-lists/

/**
 * LOGIC: As list are sorted, we will make use of it
 * - As there are k list, we need to find minimum in them
 * - This can be done best by min heap
 * - Why min heap?
 * - Because we can pick the least among that k & push the next item from that list
 * - This will help us to always carry the k items and will have access to the least one
 * 
 * COMPLEXITY: O(N(logN)^2)
 * 
 */ 
class Comparator {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comparator> minHeap;

        for(int i=0;i<lists.size();i++) {
            if(lists[i]) {
                minHeap.push(lists[i]);    
            }
        } // all heads pushed

        ListNode* saveHead=NULL;
        ListNode* head=NULL;
        
        if(!minHeap.empty()) {
            saveHead = minHeap.top();
            head = saveHead;
            minHeap.pop();
            if(head->next) minHeap.push(head->next);
        }

        while(!minHeap.empty()) {
            ListNode* currTop = minHeap.top();
            minHeap.pop();
            if(currTop->next!=nullptr) {
                minHeap.push(currTop->next);
            }
            head->next = currTop;
            head = head->next;
        }
        
        return saveHead;       
    }
};