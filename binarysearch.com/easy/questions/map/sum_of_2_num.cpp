// https://binarysearch.com/problems/Sum-of-Two-Numbers

bool solve(vector<int>& nums, int k) {
    set<int> store;
    for(int num: nums) {
        if(store.find(k-num)!=store.end()) {
            return true;
        }
        store.insert(num);
    }
    return false;
}