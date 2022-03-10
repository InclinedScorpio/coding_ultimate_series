// https://binarysearch.com/problems/Hoppable

/**
 * @GOODQUESTION
 * LOGIC: Just take the currentMax and see if currentMax could take us to the last! 
 * COMPLEXITY: O(N)
 * 
 */ 
bool solve(vector<int>& nums) {
    int currMax=0;
    for(int i=0;i<nums.size();i++) {
        if(currMax<0) return false;
        if(nums[i]>currMax) currMax=nums[i];
        if(i+currMax>=nums.size()-1) return true;
        currMax--;
    }
    return true;
}
