// https://binarysearch.com/problems/Verify-Max-Heap

bool solve(vector<int>& nums) {
    for(int i=0;i<nums.size();i++) {
        if((2*i+1)<nums.size()) {
            if(nums[i]<nums[2*i +1]) {
                return false;
            }
        }
        if((2*i+2)<nums.size()) {
            if(nums[i]<nums[2*i +2]) {
                return false;
            }
        }
    }
    return true;
}