// https://practice.geeksforgeeks.org/problems/subset-sums2234/1#

/**
 * LOGIC: V.Imp to understand this way of calling recursively
 * - Earlier I was using for loop which is not at all required
 * - We can simply skip the current and take next one - that would also consider all subsets
 * - Important to understand how we are generating all the subsets here
 * 
 * COMPLEXITY: O(2^N) - either we will consider or won't
 * 
 */ 
class Solution {
public:
    void helper(vector<int> arr, int N, int iter, int currSum, vector<int>& res) {
        if(iter>=N) return;
        res.push_back(currSum + arr[iter]);
        helper(arr, N, iter+1, arr[iter] + currSum, res);
        helper(arr, N, iter+1, currSum, res);
        return;
    }

    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> res = {0};
        helper(arr, N, 0, 0, res);
        return res;
    }
};