// https://binarysearch.com/problems/Kth-Last-Node-of-a-Linked-List

/**
 * LOGIC: The problem is tricky when asked about O(1) Space complexity
 * - If we see closely
 * - We can take 2 ptr, at a difference of k
 * - Now move both forward & the one behind will point to kth last once forward reaches to NULL
 * 
 * 
 * COMPLEXITY: O(N)
 * SPACE COMPLEXITY: O(1)
 */ 
int solve(LLNode* node, int k) {
    LLNode* temp = node;
    k++;
    while(k) {
        temp = temp->next;
        k--;
    }
    while(temp) {
        node = node->next;
        temp = temp->next;
    }
    return node->val;
}
