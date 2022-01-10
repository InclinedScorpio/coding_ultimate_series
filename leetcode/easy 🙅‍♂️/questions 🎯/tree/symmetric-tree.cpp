// https://leetcode.com/problems/symmetric-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/**
 * LOGIC: Queue used || Operations: push, pop, front, back, size
 * - Left on the mirror - run preorder
 * - Right on the mirror - run postorder
 * 
 * - During preorder store all elements in queue one by one
 * - During postorder, keep comparing the nodes and remove from queue
 * 
 */
class Solution {
public:
    
    int currValue;
    queue<int> myStack;
    
    void leftLeftOrderTraversal(TreeNode* node) {
        if(!node) {
            this->myStack.push(-101);
            return;
        }
        this->myStack.push(node->val);
        leftLeftOrderTraversal(node->left);
        leftLeftOrderTraversal(node->right);
    }
    
    bool rightRightOrderTraversal(TreeNode* node) {
        if(!node) {
            if(this->myStack.front()==(-101)) {
                this->myStack.pop();
                return true;
            }else {
                return false;    
            }
        }
        if(node->val != this->myStack.front()) {
            return false;
        }
        this->myStack.pop();
        bool left = rightRightOrderTraversal(node->right);
        bool right = rightRightOrderTraversal(node->left);
        return left && right;
    }
     
    bool isSymmetric(TreeNode* root) {
        this->leftLeftOrderTraversal(root->left);
        return this->rightRightOrderTraversal(root->right) && this->myStack.empty();
    }
};