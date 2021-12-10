#include <iostream>
#include <map>

using namespace std;
class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data, Node* left=NULL, Node* right=NULL) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
};

map<int, int> level_node_mapping;
/**
 * 
 * COMPLEXITY: O(N)
 * LOGIC: keep check of level
 * > the latest new left level is the node required
 * > As it's left iter, then right iter...
 * > It will make sure the left ones gets printed first
 * 
 *                            1 
 *                    2             3
 *                4       5           9
 *                     6     7         10
 *                          8            11                   
 *                                     12
 * RESULT: 1 2 4 6 8 12
 */ 
void printLeftView(Node* node, int level=0) {
    if(node==NULL) {
        return;
    }
    if(level_node_mapping.find(level)==level_node_mapping.end()) {
        level_node_mapping[level] = node->data;
    }
    printLeftView(node->left, level+1);
    printLeftView(node->right, level+1);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->left->right->right->left = new Node(8);
    root->right->right = new Node(9);
    root->right->right->right = new Node(10);
    root->right->right->right->right = new Node(11);
    root->right->right->right->right->left = new Node(12);
    
    printLeftView(root);
    for(auto keys: level_node_mapping) {
        cout<<keys.second<<" ";
    }
}
