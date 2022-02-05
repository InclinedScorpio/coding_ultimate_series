// https://binarysearch.com/problems/Linked-List-Delete-Last-Occurrence-of-Value

/**
 * LOGIC: Reverse once, find first occurance cause that's easy, reverse back
 * COMPLEXITY: O(3N)
 */
LLNode* reverse(LLNode* node) {
    LLNode* prev=node;
    LLNode* curr=node->next;
    node->next = NULL;

    // reversed
    while(curr) {
        LLNode* save = curr->next;
        curr->next = prev;
        prev = curr;
        curr = save;
    }
    return prev;
}


LLNode* solve(LLNode* node, int target) {
    
    if(node->val==target && !node->next) {
        return NULL;
    }

    if(!node->next) {
        return node;
    }

    LLNode* prev;
    LLNode* curr;
    curr = reverse(node);

    LLNode* head = curr; //save head

    if(curr->val==target) { // if first
        head = curr->next;
    }else {
        prev = curr;
        curr = curr->next;
        while(curr) {
            if(curr->val==target) {
                prev->next = curr->next;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    
    // reverse back
    node = head;
    return reverse(node);
}
