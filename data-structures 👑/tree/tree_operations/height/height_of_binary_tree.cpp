#include <iostream>

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

int ind=-1;
Node* createTree(int arr[]) {
    ind++;
    if(arr[ind]==-1) {
        return NULL;
    }

    Node* newNode = new Node(arr[ind]);
    newNode->left = createTree(arr);
    newNode->right = createTree(arr);
    return newNode;
}

/**
 * COMPLEXITY: O(N)=> because all nodes will be traversed
 * 
 * LOGIC: traverse all the node... think about base case always first
 * 1. Leaf will have height 0... means leaf->left & leaf->right will be 0
 * 2. MAINLOGIC: Now, every node will return max of left & right "+ 1" 
 * 
 * 
 * IMPORTANT: This is height 2! (1-> is at level 1, (2, 3) are at level 2) - height 2
 *                  1
 *                2   3
 * 
 */ 
int maxHeight(Node* node) {
    if(node==NULL) {
        return 0;
    }
    int leftValue = maxHeight(node->left);
    int rightValue = maxHeight(node->right);
    return max(leftValue, rightValue)+1;
}


int main() {
    int treeData[] = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    Node* root = createTree(treeData);
    cout<<maxHeight(root);
}
