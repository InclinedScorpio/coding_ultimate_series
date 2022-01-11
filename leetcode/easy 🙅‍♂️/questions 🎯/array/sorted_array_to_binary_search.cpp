// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
class Solution {
public:
    int a=0;
    int b;
    
    TreeNode* sortedArrayToBSTUtility(vector<int>& nums, int start, int end) {
        if(start>end) {
            return NULL;
        }
        int mid = (start + end)/2;
        TreeNode* treeNode = new TreeNode(nums[mid]);
        treeNode->left = sortedArrayToBSTUtility(nums, start, mid-1);
        treeNode->right = sortedArrayToBSTUtility(nums, mid+1, end);
        return treeNode;
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return  sortedArrayToBSTUtility(nums, 0, nums.size()-1);
        
    }
};