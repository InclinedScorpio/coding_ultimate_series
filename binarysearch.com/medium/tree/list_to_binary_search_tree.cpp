// https://binarysearch.com/problems/List-to-Binary-Search-Tree

/**
 * LOGIC: Only logic is to understand the question tht it's asking for size/2
 * - Hence we are required to find the size(of items from l to r) at each step
 * 
 */ 
Tree* helper(vector<int>& nums, int l, int r) {
    if(l>r) return NULL;
    if(l==r) return new Tree(nums[l]);

    int indToPick = l + floor((r - l + 1)/2);
    Tree* currNode = new Tree(nums[indToPick]);
    currNode->left = helper(nums, l, indToPick-1);
    currNode->right = helper(nums, indToPick+1, r);
    return currNode;
}


Tree* solve(vector<int>& nums) {
    return helper(nums, 0, nums.size()-1);
}