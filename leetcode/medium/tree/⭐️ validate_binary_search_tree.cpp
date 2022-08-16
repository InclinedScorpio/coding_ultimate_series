// https://leetcode.com/problems/validate-binary-search-tree/

/**
 * LOGIC: Took long time, 
 * 
 * 
 */ 
struct Resolver {
    long minVal, maxVal;
    bool result;
};

class Solution {
public:
    Resolver helper(TreeNode* root) {
        if(!root) return {LONG_MIN, LONG_MAX, true};
        
        Resolver left = helper(root->left); 
        if(!left.result) return left;
        
        bool leftMinCheck=true, leftMaxCheck=true;
        if(left.minVal==LONG_MIN) {
            leftMinCheck=false;
            left.minVal=root->val;
        }
        if(left.maxVal==LONG_MAX) {
            left.maxVal=root->val;
            leftMaxCheck=false;
        }
        
        if((leftMinCheck && left.minVal >= root->val) || (left.maxVal >= root->val && leftMaxCheck)) return {1, 1, false};
        
        Resolver right = helper(root->right);
        if(!right.result) return right;
        
        bool rightMinCheck = true, rightMaxCheck=true;
         if(right.minVal==LONG_MIN) {
            rightMinCheck=false;
            right.minVal=root->val;
        }
        if(right.maxVal==LONG_MAX) {
            right.maxVal=root->val;
            rightMaxCheck=false;
        }
        
        if( (rightMaxCheck && right.maxVal <= root->val) || (rightMinCheck && right.minVal <=root->val)) return {1, 1, false};
        
        return {left.minVal, right.maxVal, true};
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root).result;
    }
};