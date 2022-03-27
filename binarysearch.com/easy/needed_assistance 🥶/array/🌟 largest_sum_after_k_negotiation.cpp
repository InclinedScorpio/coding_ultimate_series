// https://binarysearch.com/problems/Largest-Sum-After-K-Negations

/**
 * LOGIC: Think Greedily!
 * - Sorting as first step is genuine
 * - ... It will help to pick neg first!
 * - Once all negative are done... (Important)
 * - We need to pick the smallest num now! (LOGIC⭐️)
 * - This is the greedy approach
 * - Code as you think
 * - Now if k is even means - take minNum as it is 
 * - If k is odd means - take minNum as -ve.
 * 
 * COMPLEXITY: O(NlogN) - BS
 * 
 */ 
int solve(vector<int>& nums, int k) {

    sort(nums.begin(), nums.end());

    int sum=0;
    for(int i=0;i<nums.size();i++) {
        if(k<=0) break;
        if(nums[i]<0) {
            nums[i] = abs(nums[i]);
        } else if (nums[i]==0) {
            k=0;
            continue;
        } else break;
        k--;
    }

    int minNum=0;
    if(k>0 && k%2!=0) {
        minNum = *min_element(nums.begin(), nums.end());
        if(k%2!=0) minNum = (-1 * minNum);
        minNum *= 2;
    }

    for(int i: nums) {
        sum += i;
    }

    sum +=minNum;
    return sum;
}