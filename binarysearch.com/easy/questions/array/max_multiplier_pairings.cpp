// https://binarysearch.com/problems/Max-Multiplied-Pairings

/**
 * LOGIC: There are 2 ways pair can happen for max: 
 * - Either top low, bottom low <OR> 
 * - top right, bottom right
 * 
 * COMPLEXITY: O(N)
 */ 
int solve(vector<int>& nums, vector<int>& multipliers) {
    int leftTop=0, rightTop=nums.size()-1;
    int leftBottom=0, rightBottom=multipliers.size()-1;
    int sum=0;
    sort(nums.begin(), nums.end());
    sort(multipliers.begin(), multipliers.end());

    while(leftTop<=rightTop && leftBottom<=rightBottom) {
        if(
            (nums[leftTop]*multipliers[leftBottom]) > (nums[rightTop]*multipliers[rightBottom])
        ) {
            sum = sum + nums[leftTop]*multipliers[leftBottom];
            leftTop++; leftBottom++;
        }else {
            sum = sum + nums[rightTop]*multipliers[rightBottom];
            rightTop--; rightBottom--;
        }
    }
    return sum;
}
