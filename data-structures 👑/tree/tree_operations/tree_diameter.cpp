#include <iostream>
#include <algorithm>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data, Node* left = NULL, Node* right=NULL) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
};

int ind=-1;
Node* createTree(int arr[]) {
    ind++;

    if(arr[ind]==-1) {
        return NULL;
    }

    Node* node = new Node(arr[ind]);
    node->left = createTree(arr);
    node->right = createTree(arr);
    return node;
}

int maxHeight(Node* node, int ind) {
    if(node==NULL){
        return ind-1;
    }
    int left = maxHeight(node->left, ind+1);
    int right = maxHeight(node->right, ind+1);
    return max(left, right);
}

/**
 * TC: O(N^2)- because on each node we are calculating the maxHeight: O(N)
 * 
 * LOGIC: Think of top Node... max dia will pass through this top node right ?
 * Nope, it may bypass through node->left...or ummm left->right or node->left->left
 *
 * SOLUTION: 1. On a single node.. check dia if it passes through that node
 * 2. Check what will be if it passes through left subtree
 * 3. Check what will be if it passes through right subtree
 * 
 */ 
int findMaxDiameter(Node* node) {
    if(node==NULL) {
        return 0;
    }

    int left = maxHeight(node->left, 0);
    int right = maxHeight(node->right, 0);
    int throughNodeDia = left + right + 2;
    /**
     *  +2 is for the two edges connecting to current node
     */
    // cout<<"L: "<<left<<" R:"<<right<<" T:"<<throughNodeDia<<endl;

    int leftSubTree = findMaxDiameter(node->left);
    int rightSubTree = findMaxDiameter(node->right);
    return max(leftSubTree, max(rightSubTree, throughNodeDia));
}

int main() {
    int treeData[] = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    Node* root = createTree(treeData);
    cout<<findMaxDiameter(root);
}
