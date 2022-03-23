// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * LOGIC: While returning return 2 things
 * - Curr Index from last + the node itself
 * - Create reconnection on each iteration
 * - Skip reconnecting if index matched
 * 
 * COMPLEXITY: O(N)
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