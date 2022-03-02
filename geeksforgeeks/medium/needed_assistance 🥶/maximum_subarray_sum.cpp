// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1#

long long maxSubarraySum(int arr[], int n){
    long long int maxSubArraySum=arr[0];
    long long int currSum=arr[0];
    for(int i=1;i<n;i++) {
        if((arr[i]+currSum)<arr[i]) {
            currSum=arr[i];
        } else {
            currSum+=arr[i];
        }
        if(currSum>maxSubArraySum) maxSubArraySum = currSum;
    }
    return maxSubArraySum;
}