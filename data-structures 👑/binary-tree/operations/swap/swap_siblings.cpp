#include <iostream>
#include <map>
#include <queue>

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

/**
 * QUESTION: Check if both tree can be created identical after as many child swaps needed
 * LOGIC: Just check left node with left, right of other tree, and vice-versa
 * > Keep recursively checking if at any point the node doesn't match neither left or right of other node
 * 
 * TREE:1) left    
 * 
 *                                           6
 *                                   3              8
 *                               1       7       4      2
 *                                             7   1      3
 * TREE:2) right  
 *                                           6
 *                                   8              3
 *                                2      4       7      1
 *                              3       1  7
 * 
 */ 
bool swapSib(Node* left, Node* right) {
    if(left==NULL && right==NULL) {
        return true;
    }
    if(left==NULL || right==NULL) { // as one would be data and other would be NULL
        return false;
    }
    if(left->data != right->data) { // if data is not same no need to go forward
        return false;
    }

    bool checkEqL =  swapSib(left->left, right->left) || swapSib(left->left, right->right);
    if(!checkEqL) 
        return false;
    bool checkEqR = swapSib(left->right, right->left) || swapSib(left->right, right->right);
    return checkEqR; // as data is same and left is same, now it depends upon right branch
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    root->right->right = new Node(2);
    root->right->left = new Node(4);
    root->right->right->right = new Node(3);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(1);

    Node* rootRight = new Node(6);
    rootRight->left = new Node(8);
    rootRight->right = new Node(3);
    rootRight->left->left = new Node(2);
    rootRight->left->right = new Node(4);
    rootRight->right->right = new Node(1);
    rootRight->right->left = new Node(7);
    rootRight->left->left->left = new Node(3);
    rootRight->left->right->left = new Node(1);
    rootRight->left->right->right = new Node(7);

    cout<<swapSib(root, rootRight);    
}
