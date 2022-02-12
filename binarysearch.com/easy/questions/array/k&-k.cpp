// https://binarysearch.com/problems/K-and-K

int solve(vector<int>& nums) {
    int max=-1;
    set<int> store;
    for(int i=0;i<nums.size();i++) {
        if(store.find(-1 * nums[i])!=store.end() && max<abs(nums[i])) {
            max = abs(nums[i]);
        }else {
            if(nums[i]==0 && max<abs(nums[i])) {
                max=0;
            }
            store.insert(nums[i]);
        }
    }
    return max;
}
