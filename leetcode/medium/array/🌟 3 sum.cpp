// https://leetcode.com/problems/3sum/

/**
 * LOGIC: Uses 2 sum problem
 * - And for that first we need to sort
 * - Now just pick each index and implement 2 sum for the rest of them
 * - Similar thing we also did in 4 sum problem
 * 
 * COMPLEXITY: O(N^2)
 * 
 */ 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& myNums) {
        if(myNums.size()<3) return {};
        sort(myNums.begin(), myNums.end());
        vector<vector<int>> store;
        for(int i=0;i<myNums.size()-2;) {
            int requiredSum = 0 - myNums[i];
            
            int left = i+1, right = myNums.size()-1;
            while(left<right) {
                if(myNums[left]+myNums[right]==requiredSum) {
                    store.push_back({myNums[i], myNums[left], myNums[right]});   
                    while(left<right && myNums[left]==myNums[left+1]) left++;
                    left++;
                    while(left<right && myNums[right]==myNums[right-1]) right--;
                    right--;
                }
                else if(myNums[left]+myNums[right] < requiredSum) {
                    while(left<right && myNums[left]==myNums[left+1]) left++;
                    left++;
                } else {
                    while(left<right && myNums[right]==myNums[right-1]) right--;
                    right--;
                }
            }
            while(i<myNums.size()-2 && myNums[i]==myNums[i+1]) i++;
            i++;
        }
        return store;
    }
};