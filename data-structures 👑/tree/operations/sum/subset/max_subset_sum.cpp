#include <iostream>
#include <queue>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data) {
        this->data = data;
    }
};

int globalIndex=-1;

Node* createTree(int *arr) {
    globalIndex++;
    if(arr[globalIndex]<0) {
        return NULL;
    }
    Node* node = new Node(arr[globalIndex]);
    node->left = createTree(arr);
    node->right = createTree(arr);
    return node;
}


/***
 * 
 * QUESTION: Select max sum that can be made without taking any adjacent node
 * 
 * COMPLEXITY: O(N)- all nodes are traversed only once
 * 
 * LOGIC: Think in terms of bottom up fashion
 * 1. Every node can create it's inclusion/exclusion pair
 * 2. For inclusion- pick exclusion value of childrens
 * 3. If it's exlusion- pick whatever is max(inclusion/exclusion) of children...
 * ... as it's not compulsory that alternative has to be picked
 * 
 * SIMILAR: To Leetcode > easy > array > Stickler Theif Array Question
 * 
 */ 
pair<int,int> subsetSum(Node* node) {
    pair<int,int> currPair;
    if(node==NULL) {
        currPair.first=0;
        currPair.second=0;
        return currPair;
    }

    pair<int,int> left = subsetSum(node->left);
    pair<int,int> right = subsetSum(node->right);

    // Current Node Included: Pick current and left right exclusion (As inclusion can't be picked)
    currPair.first = node->data + left.second + right.second;

    // Current Node Excluded: Pick max of left right (exclusion or inclusion)
    currPair.second = max(left.first, left.second) + max(right.first, right.second);

    // return the inclusion,exclusion pair for current node
    return currPair;
}

int main() {
    int treeData[] = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    Node* root = createTree(treeData);
    pair<int,int> sum = subsetSum(root);
    cout<<max(sum.first, sum.second);
}