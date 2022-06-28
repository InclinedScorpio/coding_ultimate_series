// https://binarysearch.com/problems/Kth-Smallest-Element

/**
 * LOGIC: Quick Select (Similar to Quick Sort) - just that here after finding num at right index we choose to see left or right
 * 
 * BEST CASE COMPLEXITY: O(N)
 * WORSE CASE COMPLEXITY: O(N^2)
 */ 
int helper(int i, int j, vector<int>& nums, int k) {
    if(i==j) return i;
    cout<<i<<" "<<j<<" ";
    int left = i, right=i, pivot = j;
    while(right<pivot) {
        if(nums[right]<nums[pivot]) {
            swap(nums[left], nums[right]);
            left++; right++;
        } else {
            right++;
        }
    }
    swap(nums[left], nums[pivot]);
    cout<<left<<endl;
    return left;
}

int solve(vector<int>& nums, int k) {
    int left = 0,right = nums.size()-1;
    if(left==right) return nums[left];
    int ind = helper(left, right, nums, k);
    while(ind!=k) {
        if(ind<(k)) {
            left = ind+1;
        } else {
            right = ind-1;
        }
        ind = helper(left, right, nums, k);
    }
    return nums[k];
}