// https://binarysearch.com/problems/Group-Integers

/**
 * LOGIC: Reached to the logic where understood for 3, 5 we need  some number which cn divide both
 * - That number was gcd !! and in cpp __gcd(x, y) is present!
 * 
 */ 
bool solve(vector<int>& nums) {

    unordered_map<int, int> store;
    for(int i=0;i<nums.size();i++) {
        store[nums[i]]++;
    }
    int minVal =INT_MAX;
    for(pair<int, int> st: store) {
        if(st.second<minVal) minVal = st.second;
    }

    for(pair<int, int> st: store) {
        if(__gcd(minVal, st.second)==1) return false;
    }
    return true;
}