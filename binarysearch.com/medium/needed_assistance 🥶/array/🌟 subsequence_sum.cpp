// https://binarysearch.com/problems/Subsequence-Sum

/**
 * See question first! (to understand what's given)
 * LOGIC: First solution which comes to mind is DP (similar to LIS)
 * - Just an additional constraint which can be done
 * - It gives TLE! (means better solution exists!)
 * 
 * (Greedy approach)
 * - Constraint given is, we can pick 2 nums only if:
 * A[i] - A[j] = i - j (diff btw num is same as diff btw index)
 * which is same as, A[i] - i = A[j] - j
 * - Means whatever number you pick must satisfy this
 * - Hence if A[i] - i ==5 that means all other resulting to 5 must be added
 * - Hence for this we can make use or map!
 * 
 * NOTE: This will work as let's say A[i] - i == 5, then for next indices as i is increased, hence A[i] will definitely will be increased
 * 
 * COMPLEXITY: O(N)
 *
 */ 
int solve(vector<int>& nums) {
    unordered_map<int, int> store;
    int maxVal = 0;
    for(int i=0;i<nums.size();i++) {
        store[nums[i]-i]+=nums[i];
        maxVal = max(maxVal, store[nums[i]-i]);
    }
    return maxVal;
}