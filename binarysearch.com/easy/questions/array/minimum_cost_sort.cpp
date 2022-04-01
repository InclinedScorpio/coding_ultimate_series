// https://binarysearch.com/problems/Flipped-Matrix-Prequel

int solve(vector<int>& nums) {
    vector<int> store = nums;
    vector<int> decend = nums;
    sort(decend.rbegin(), decend.rend());
    sort(store.begin(), store.end());
    int result=0;
    int deceResult=0;

    for(int i=0;i<nums.size();i++) {
        result += abs(nums[i]-store[i]);
        deceResult += abs(decend[i]-nums[i]);
    }
    return min(deceResult, result);
}