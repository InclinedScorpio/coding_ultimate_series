// https://binarysearch.com/problems/Subsequence-Sum

/**
 * DP Solution given at last (intruiging but gave TLE!)
 * 
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
 * GREEDY (less intruiging)
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

/*******************************************
            DP Approach
********************************************/ 

int helper(vector<int>& nums, int ind, vector<int>& isVisited) {
    if(isVisited[ind]!=-1) return isVisited[ind];
    int maxVal=0;
    for(int i=ind+1;i<nums.size();i++) {
        if(nums[i]>nums[ind] && (i-ind == nums[i]-nums[ind]))
            maxVal = max(maxVal, helper(nums, i, isVisited));
    }
    return isVisited[ind] = maxVal +  nums[ind];
}

int solve(vector<int>& nums) {
    vector<int> isVisited(nums.size(), -1);
    int maxVal=0;
    for(int i=0;i<nums.size();i++) {
        maxVal = max(maxVal, helper(nums, i, isVisited));
    }
    return maxVal;
}