// https://leetcode.com/problems/longest-consecutive-sequence/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/**
 * LOGIC: Basic, just sort and check for longest sequence
 * COMPLEXITY: O(NlogN)
 * 
 * BETTERSOLUTION: O(N) - find
 * 
 */ 
int longestSequence(vector<int> &arr) {
    if(arr.size()==1) {
        return 1;
    }

    sort(arr.begin(), arr.end());
    
    int result=0;
    int counter=0;
    for(int i=1;i<arr.size();i++) {
        if(arr[i-1]+1==arr[i]) {
            counter++;
            if(result<counter) {
                result = counter;
            }
        }else {
            counter=0;
        }   
    }
    return result+1;
}


int main() {
    vector<int> arr = {1,9,3,0,18,5,2,4,10,7,12,6};
    cout<<longestSequence(arr);
}