// https://binarysearch.com/problems/Longest-Increasing-Subsequence

/**
 * LOGIC: Logic is simple
 * - We will create a vector where increasing subsequence will be kept
 * - Now it will have the largest number at the end
 * - If some larger number comes (if part in code) then we will push it simply
 * - But, if smaller num comes we will replace it in the resultant vector
 * 
 * WHY REPLACE?
 * - Because we don't require the LIS array but rather the number of digits
 * - We will keep replacing till it reaches the largest (end of array) so that more digits can be accomodated
 * - While replacing it must be clear that the size of resultant array will remain same
 * 
 * COMPLEXITY: O(NlogN)
 * - In this approach we can't print the resultant array/ just number of items in LIS
 */ 

int solve(vector<int>& nums) {
    if(nums.size()==0) return 0;
    vector<int> store = {nums[0]};
    for(int i=1;i<nums.size();i++) {
        // nums is largest so push it
        if(store[store.size()-1]<nums[i]) {
            store.push_back(nums[i]);
        } else {
            // binary search to check where to replace as it's smaller than largest present
            // in a hope that maybe last one will also be replaced to give space to further data
            int ind = lower_bound(store.begin(), store.end(), nums[i]) - store.begin();
            cout<<ind;
            store[ind] = nums[i];
        }
    }
    return store.size();
}