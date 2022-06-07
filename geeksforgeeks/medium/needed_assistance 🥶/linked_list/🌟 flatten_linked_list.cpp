// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#

/**
 * LOGIC: Is similar to merge 2 linked list
 * - Here we just need to do that same thing recursively
 * 
 */ 
Node *flatten(Node *root)
{
    if(!root->next) return root;
    
    Node* left = root;
    Node* right = root->next;
    Node* saveRight = right;
    Node* curr = NULL;
    
    if(left->data < right->data) {
        curr = left;
        left = left->bottom;
    } else {
        curr = right;
        right = right->bottom;
    }
    
    Node* saveHead = curr;

    while(left && right) {
        if(left->data < right->data) {
            curr->bottom = left;
            left = left->bottom;
        } else {
            curr->bottom = right;
            right = right->bottom;
        }
        curr = curr->bottom;
    }
    
    while(left) {
        curr->bottom = left;
        curr = curr->bottom;
        left = left->bottom;
    }
    
    while(right) {
        curr->bottom = right;
        curr = curr->bottom;
        right = right->bottom;
    }
    
    saveHead->next = saveRight->next;
    return flatten(saveHead);
}
