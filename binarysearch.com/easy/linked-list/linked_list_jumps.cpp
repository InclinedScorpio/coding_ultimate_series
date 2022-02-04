// https://binarysearch.com/problems/Linked-List-Jumps

/**
 * LOGIC: Basic - just make the no. of jumps required and map the blocks
 * COMPLEXITY: O(N)
 */
LLNode* solve(LLNode* node) {
    
    LLNode* save = node;
    LLNode* saveHead = save;
    
    while(node) {
        int counter = save->val;
        while(counter--) {
            if(!node) {
                break;
            }
            node = node->next;
        }
        save->next = node;
        save = node;
    } 
    if(save){
        save->next = NULL;
    }
    
    return saveHead;
}

// linked list deletion