// https://binarysearch.com/problems/List-Min-Replacement

vector<int> solve(vector<int>& nums) {
    int currMin = nums[0];
    vector<int> result;
    result.push_back(0);
    for(int i=1;i<nums.size();i++) {
        result.push_back(currMin);
        if(currMin>nums[i]) {
            currMin = nums[i];
        }
    }
    return result;
}
