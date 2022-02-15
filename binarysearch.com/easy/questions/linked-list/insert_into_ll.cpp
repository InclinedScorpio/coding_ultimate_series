// https://binarysearch.com/problems/Insert-Into-Linked-List

LLNode* solve(LLNode* head, int pos, int val) {
    LLNode* temp = new LLNode(val);    
    if(pos==0) {
        temp->next = head;
        return temp;
    }
    LLNode* headItr = head;
    pos--;
    while(pos--) {
        headItr = headItr->next;
    }
    temp->next = headItr->next;
    headItr->next = temp;
    return head;
}