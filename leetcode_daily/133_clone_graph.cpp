// https://leetcode.com/problems/clone-graph/description

/**
 * 
 * Important to understand how DFS works here
 * 
 * - BFS is better if number of nodes are more than 10^4 as recursion stack may overflow
 * - here max nodes are 100 so DFS is fine
 */
class Solution {
    public:
        unordered_map<Node*, Node*> store;
        Node* cloneGraph(Node* node) {
            if(!node) return nullptr;
    
            if(store.find(node)!=store.end()) return store[node];
    
            store[node] = new Node(node->val);
    
            for(Node* neigh: node->neighbors) {
                store[node]->neighbors.push_back(cloneGraph(neigh));
            }
    
            return store[node];
        }
    };