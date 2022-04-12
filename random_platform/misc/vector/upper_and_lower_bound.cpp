/**
 * Q) Find upper and lower bound in vector in less than linear
 * A) It's not similar to lower and upper bound function in cpp
 * - We can make use of binary search to find both in O(logN)
 * 
 */ 
#include<iostream>
#include<vector>

using namespace std;

int vec_lower_bound(vector<int>&  arr, int num) {
    int left=0, right=arr.size()-1, ans=-1;
    while(left<=right) {
        int mid = (left+right)/2;
        if(arr[mid]==num) {
            ans=mid;
            right=mid-1;
        } else if (arr[mid] > num ) {
            right=mid-1;
        } else {
            left=mid+1;
        }
    }
    return ans;
}

int vec_upper_bound(vector<int>& arr, int num) {
    int left=0, right = arr.size()-1, ans=-1;
    while(left<=right) {
        int mid = (left+right)/2;
        if(arr[mid]==num) {
            ans = mid;
            left=mid+1;
        } else if(arr[mid]<num) {
            left=mid+1;
        } else {
            right=mid-1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1,1,1,1,1,1,2,2,2,2,3,5,77,888,999,999,999};
    cout<<"lower_bound: "<<vec_lower_bound(arr, 999)<<endl;
    cout<<"upper_bound: "<<vec_upper_bound(arr, 999)<<endl;
    cout<<"*********"<<endl;
  
    // built in method of cpp
    cout<<lower_bound(arr.begin(), arr.end(), 999) - arr.begin()<<endl;
    cout<<upper_bound(arr.begin(), arr.end(), 999) - arr.begin() - 1<<endl;
}
