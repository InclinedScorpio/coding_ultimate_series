// https://binarysearch.com/problems/Rotate-Linked-List-by-K


/**
 * 
 * LOGIC: Important to understand that right shift is asked from last k items
 * - NOTE: Right shift means take item from right and keep moving to head
 * 
 */ 
LLNode* solve(LLNode* node, int k) {
    if(k==0) return node;

    LLNode* saveHead = node;
    while(k-- && node) {
        node = node->next;
    }
    if(!node) {
        return saveHead;
    }

    LLNode* prev = saveHead;
    while(node && node->next) {
        node = node->next;
        prev = prev->next;
    }

    LLNode* newHead = prev->next;
    node->next = saveHead;
    prev->next = NULL;
    return newHead;
}