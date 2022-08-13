// https://binarysearch.com/problems/Binary-Tree-to-Linked-List

/**
 * LOGIC: Only thing to note is to use & along with *
 * Why? otherwise while backtracking ->next would not have happened
 * 
 */ 
void helper(Tree* root, LLNode*& listNode, LLNode*& saveHead) {
    if(!root) return;
    helper(root->left, listNode, saveHead);
    if(!saveHead) {
        listNode = new LLNode(root->val);
        saveHead = listNode;
    } else {
        listNode->next = new LLNode(root->val);
        listNode = listNode->next;
    }
    helper(root->right, listNode, saveHead);
}

LLNode* solve(Tree* root) {
    LLNode* listRoot = NULL;
    LLNode* head = NULL;
    helper(root, listRoot, head);
    return head;
}