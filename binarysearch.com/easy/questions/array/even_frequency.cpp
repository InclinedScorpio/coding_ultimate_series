// https://binarysearch.com/problems/Even-Frequency

/**
 * LOGIC: Use property of array O(1) as no. of items are limited 100,000
 * - Use map to save size
 * 
 */ 
bool solve(vector<int>& nums) {
    bool isOdd = true;
    int arr[100000] = {0};
    int noOfOdds=0;
    for(int i=0;i<nums.size();i++) {
        if(arr[nums[i]]==1) {
            arr[nums[i]]=0;
            noOfOdds--;
        }else {
            arr[nums[i]]=1;
            noOfOdds++;
        }
    }
    return noOfOdds==0;
}
