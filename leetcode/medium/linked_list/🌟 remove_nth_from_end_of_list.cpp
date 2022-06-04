// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * LOGIC: While returning return 2 things
 * - Curr Index from last + the node itself
 * - Create reconnection on each iteration
 * - Skip reconnecting if index matched
 * 
 * COMPLEXITY: O(N)
 * - Can there be a better way? Yes scroll down!!
 * 
 */ 
struct NodeData{
    int val;
    ListNode* node;
};

class Solution {
public:
    
    NodeData helper(ListNode* head, int n) {
        if(!head) {
            return {0, NULL};
        }
        
        NodeData nodeData = helper(head->next, n);
        nodeData.val = nodeData.val+1;
   
        if(nodeData.val==n) {
            return {INT_MIN, nodeData.node};
        } else {
            head->next = nodeData.node;
            return {nodeData.val, head};
        }
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return helper(head, n).node;
    }
};


/**
 * LOGIC: Use 2 ptr, take the fast one to steps ahead required
 * - And then move both slow and fast
 * - This way we can create gap of "n" and hence remove that nth node
 * 
 * GOT STUCK HERE:
 * - For edge case (when first need to be removed) check if fast reached last then just remove head
 * 
 * COMPLEXITY: O(N) In a single pass
 * SPACE: O(1)
 */ 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* fast=head;
        while(n--) {
            fast = fast->next;
        }
        
        if(!fast) return head->next;
        
        ListNode* slow = head;
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        } 
        
        slow->next = slow->next->next;
        
        return head;
    }
};