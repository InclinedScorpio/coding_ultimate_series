/**
 * QUESTION: Find triplets in GP
 * - Find triplets in i, j, k (i<j<k)
 * - such that numbers on those indices makes a GP
 * - a, ar, ar^2
 * 
 * LOGIC: Think the GP as ->
 * - a with previous term as a/r & next term as a*r
 * - a/r, a, a*r - now left & right can be taken care by map
 * 
 * COMPLEXITY: O(N)
 * 
 */ 

#include<iostream>
#include<vector>
#include<map>
#include<math.h>

using namespace std;

int main() {
    int result=0;
    vector<int> arr = {1,4, 16, 4, 16, 64, 16, 64};
    int r = 4;
    map<int, int> right;
    map<int, int> left;
    for(int i=arr.size()-1;i>1;i--) {
        right[arr[i]]++;
    }
    left[arr[0]]++;
    for(int i=1;i<arr.size();i++) {
        if(left.count(arr[i]/r) && right.count(arr[i]*r)){
            result+= (left[arr[i]/r] * right[arr[i]*r]);
        };
        left[arr[i]]++;
        right[arr[i+1]]--;
        if(right[arr[i+1]]==0) right.erase(arr[i+1]);
    }
    cout<<result;
}