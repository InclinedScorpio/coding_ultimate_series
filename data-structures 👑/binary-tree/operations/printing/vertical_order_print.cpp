#include <iostream>
#include <map>
#include <vector>

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

map<int, vector<int> > score_node_data_mapping;

/**
 * COMPLEXITY: O(N)
 * LOGIC: Right step = +1 & Left step = -1
 * > This will tag which node is in which step
 * > Same step nodes means on same vertical level |
 * > Keep array(node->data) related to step 
 * > At last print the step array
 * 
 */ 
void verticalOrderPrint(Node* node, int step=0) {
    if(node==NULL) {
        return;
    }
    if(score_node_data_mapping.find(step)!=score_node_data_mapping.end()) {
        score_node_data_mapping[step].push_back(node->data);
    }else {
        vector<int> temp_vector;
        temp_vector.push_back(node->data);
        score_node_data_mapping[step] = temp_vector;
    }
    verticalOrderPrint(node->left, step-1);
    verticalOrderPrint(node->right, step+1);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    verticalOrderPrint(root);
    // map<int, vector> ::iterator it;
    for(auto it: score_node_data_mapping) {
        for(auto v: it.second) {
            cout<<v<<" ";
        }
        cout<<endl;
    }
}
