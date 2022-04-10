https://binarysearch.com/problems/List-Equality-with-Increments

/**
 * LOGIC: Increment all others, other than current
 * - is equivalent to decrement current only!
 * - But decrementing to 0 doesn't make sense as we need to find minimum
 * - So, rather than making everything 0, make everything the min item present
 * 
 * COMPLEXITY: O(N)
 */ 
int solve(vector<int>& nums) {
    int minElement = *min_element(nums.begin(), nums.end());
    int steps=0;
    for(int i=0;i<nums.size();i++) {
        steps+= (nums[i]-minElement);
    }
    return steps;   
}