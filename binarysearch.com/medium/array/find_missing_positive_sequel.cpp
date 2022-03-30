// https://binarysearch.com/problems/First-Missing-Positive-Sequel

/**
 * LOGIC: Basic
 * - Read question carefully, no. has to be found from [1, n+1]
 * 
 */ 
int solve(vector<int>& arr) {
    int checker=1;
    int i=0;
    if(arr[0]==0) i=1;
    for(;i<arr.size();i++) {
        if(arr[i]!=checker) return checker;
        checker++;
    }
    return arr[0]==0 ? arr.size(): arr.size()+1;
}