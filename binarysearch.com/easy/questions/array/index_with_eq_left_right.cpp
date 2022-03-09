// https://binarysearch.com/problems/Index-with-Equal-Left-and-Right-Sums

int solve(vector<int>& nums) {
    if(nums.size()==1) {
        return 0;
    }
    vector<int> left (nums.size(), 0);
    vector<int> right (nums.size(), 0);
    int lastIndex = nums.size()-1;
    int sumLeft=0,sumRight=0;

    for(int i=0;i<nums.size();i++) {
        sumLeft += nums[i];
        left[i] += sumLeft;
        sumRight += nums[lastIndex];
        right[lastIndex] += sumRight;
        lastIndex--;
    }

    if(0 == right[1]) return 0;

    for(int i=1;i<nums.size()-1;i++) 
        if(left[i-1]==right[i+1]) return i;
    
    if(left[nums.size()-2] == 0) return nums.size()-1;
    
    return -1;
    
}
