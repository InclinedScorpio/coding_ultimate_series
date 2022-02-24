// https://binarysearch.com/problems/Add-One-to-List

vector<int> solve(vector<int>& nums) {
    int carry=1;
    for(int i=nums.size()-1;i>=0;i--) {
        if(nums[i]+carry>9) {
            carry=1;
            nums[i]=0;
        }else {
            nums[i] = nums[i]+carry;
            return nums;
        }
    }
    nums.insert(nums.begin(), 1);
    return nums;
}