// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/**
 * LOGIC: Preorder(root, l, r) gives us the root of each subtree. First item is the root of whole subtree
 * - Inorder gives us an idea about a root which items will lie on the left and which on right side
 * 
 * - Hence, we can keep make use of both the array to find the item at each step
 * 
 */ 
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preOrdInd, int ind, int jnd) {
        
        // node created
        TreeNode* node = new TreeNode(preorder[preOrdInd]);
        int inOrdInd;
        for(int i=ind;i<=jnd;i++) {
            if(inorder[i]==node->val) {
                inOrdInd=i; break;
            }
        }
        if(ind<=inOrdInd-1) {
            preOrdInd++;
            node->left = helper(preorder, inorder, preOrdInd, ind, inOrdInd-1);    
        }
        if(inOrdInd+1<=jnd) {
            preOrdInd++;
            node->right = helper(preorder, inorder, preOrdInd, inOrdInd+1, jnd);
        }
            
        return node;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0, j=preorder.size()-1;
        int preOrdInd=0;
        return helper(preorder, inorder, preOrdInd, i, j);
    }
};