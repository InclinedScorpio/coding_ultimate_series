// https://binarysearch.com/problems/Sort-List-by-Hamming-Weight

int intToNumOfOnesInBin(int num) {
    int result=0;
    while(num>1) {
        if(num % 2) result++;
        num = num/2;
    }
    return ++result;
}

vector<int> solve(vector<int>& nums) {
    vector<pair<int, int> > store;

    for(int i=0;i<nums.size();i++)
        store.push_back({intToNumOfOnesInBin(nums[i]), nums[i]});

    sort(store.begin(), store.end());
    vector<int> result;
    for(pair<int, int> i: store) {
        result.push_back(i.second);
    }
    return result;
}
