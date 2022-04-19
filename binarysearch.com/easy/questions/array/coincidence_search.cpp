// https://binarysearch.com/problems/Coincidence-Search

bool binarySearch(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;

    while(lo <= hi) {
        int mid = floor((lo + hi) / 2);
    if(nums[mid] == target)
        return true;
    else if(nums[mid] < target)
        lo = mid + 1;
    else
        hi = mid - 1;
    }
    return false;
}
int solve(vector<int>& nums) {
    int count=0;
    for(int i=0;i<nums.size();i++) {
        if(binarySearch(nums, nums[i])) {
            count++;
        }
    }
    return count;
}