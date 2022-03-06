// https://binarysearch.com/problems/Pythagorean-Triplets

bool solve(vector<int>& nums) {
    if(nums.size()==0) return false;
    set<int> store;
    for(int i: nums) {
        store.insert(pow(i,2));
    }

    for(int i=0;i<nums.size()-1;i++) {
        for(int j=i+1;j<nums.size();j++) {
            int num = pow(nums[i], 2) + pow(nums[j], 2);
            if(store.find(num)!=store.end()) {
                return true;
            }
        }
    }
    return false;
}