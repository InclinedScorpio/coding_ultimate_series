// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/**
 * LOGIC: Just do bfs traversal, use queue, use NULL
 *
 */
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> store;
        store.push(root);
        store.push(NULL);
        while(!store.empty()) {
            Node* front = store.front();
            if(!front) {
                store.pop();
                if(store.empty()) break;
                store.push(NULL);
                continue;
            }
            if(front && front->left) store.push(front->left);
            if(front && front->right) store.push(front->right);
            store.pop();
            front->next = store.front();
        }
        return root;
    }
};