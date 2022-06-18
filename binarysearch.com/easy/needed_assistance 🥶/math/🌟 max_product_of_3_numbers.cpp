// https://binarysearch.com/problems/Max-Product-of-Three-Numbers

/**
 * LOGIC:
 * - First case is simple - last 3 prod after sorting
 * - Second case is for negatives
 * - First 2 items * last item
 * (First 2 because negative will turn positive)
 * (last item beause we want max positive)
 * 
 * - If last is also negative, means all nums are negative
 * - In that case prod of last 3 will be the result
 * 
 * COMPLEXITY: O(nlogN)
 */ 
int solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int maxEle = *max_element(nums.begin(), nums.end());
    return max(nums[0] * nums[1] * nums[nums.size()-1], nums[nums.size()-1] * nums[nums.size()-2] * nums[nums.size()-3]);
}