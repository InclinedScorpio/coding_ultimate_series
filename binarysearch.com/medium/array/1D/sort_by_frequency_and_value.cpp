// https://binarysearch.com/problems/Sort-by-Frequency-and-Value


/**
 * LOGIC: Make sure to know sort(x, x, greater<int>()) to sort in descending order
 * - Use map to store count
 * - Then make use of vector<pair<>> so to get in sorted order of count
 * 
 */ 
vector<int> solve(vector<int>& nums) {
    map<int, int> store;
    for(int i: nums) store[i]++;

    vector<pair<int, int>> result;
    for(auto st: store) {
        int num = st.first;
        int count = st.second;
        result.push_back({count, num});
    }
    sort(result.begin(), result.end(), greater<pair<int, int>>());

    int ind=0;
    for(int i=0;i<result.size();i++) {
        int count = result[i].first;
        int num = result[i].second;
        while(count--) {
            nums[ind++]=num;
        }
    }
    return nums;
}