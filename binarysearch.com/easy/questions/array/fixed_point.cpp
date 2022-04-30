// https://binarysearch.com/problems/Fixed-Point

int solve(vector<int>& nums) {
    int left=0, right = nums.size()-1;
    int minValue=INT_MAX;
    while(left<=right) {
        int mid = (left+right)/2;
        if(mid==nums[mid] && minValue>nums[mid]) {
            minValue = nums[mid];
        } 
        if(mid<=nums[mid]) {
            right = mid-1;
        } else {
            left=mid+1;
        }
    }
    return minValue==INT_MAX ? -1 : minValue;
}
