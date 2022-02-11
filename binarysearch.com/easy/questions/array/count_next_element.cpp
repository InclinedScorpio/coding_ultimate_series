// https://binarysearch.com/problems/Count-Next-Element

int solve(vector<int>& nums) {
    map<int,int> store;
    int result=0;
    for(int i=0;i<nums.size();i++) {
        store[nums[i]]++;
    }
    for(int i=0;i<nums.size();i++) {
        if(store.find(nums[i]+1)!=store.end()) {
            result++;
        }
    }
    return result;
}
