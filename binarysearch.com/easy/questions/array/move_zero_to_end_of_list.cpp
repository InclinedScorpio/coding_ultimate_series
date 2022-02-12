// https://binarysearch.com/problems/In-Place-Move-Zeros-to-End-of-List

/**
 * LOGIC: Take 2 pointer approach
 * - First pointer (i) will check latest zero form left to right
 * - Second pointer (nonZeroLastIdex) will check latest non zero after current zero
 * 
 */ 
vector<int> solve(vector<int>& nums) {
    int nonZeroLastIndex=-1;
    for(int i=0;i<nums.size();i++) {
        if(nums[i]!=0) continue;
        if(nonZeroLastIndex==-1) nonZeroLastIndex=i+1;        
        while(nonZeroLastIndex<nums.size() && nums[nonZeroLastIndex]==0){
            nonZeroLastIndex++;
        }
        if(nonZeroLastIndex<nums.size()) swap(nums[i], nums[nonZeroLastIndex++]);
    }
    return nums;
}
