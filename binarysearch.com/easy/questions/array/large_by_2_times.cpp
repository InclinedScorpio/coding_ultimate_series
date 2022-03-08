// https://binarysearch.com/problems/Largest-Number-By-Two-Times

bool solve(vector<int>& nums) {
    bool allZero = true;
    for(int num: nums) {
        if(num!=0) allZero = false;
    }
    if(allZero) return false;

    sort(nums.begin(), nums.end());
    if(nums[nums.size()-1] > nums[nums.size()-2] * 2) {
        return true;
    }
    return false;
}