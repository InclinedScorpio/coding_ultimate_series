// https://binarysearch.com/problems/Leaderboard

/**
 * LOGIC: Reverse traverse a map 
 * - use rbegin(), rend(), increment ptr
 * 
 */ 
vector<int> solve(vector<int>& nums) {
    map<int,int> store;
    for(int i: nums) {
        store[i]++;
    }
    map<int,int> temp;
    int index=0;
    for(auto i=store.rbegin(); i!=store.rend(); i++) {
        temp[i->first] = index; 
        index++;
    }

    vector<int> result;
    for(int i=0;i<nums.size();i++) {
        result.push_back(temp[nums[i]]);
    }
    return result;
}