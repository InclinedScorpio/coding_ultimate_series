/**
 * QUESTION: Find collection of all integers resulting to given num
 * LOGIC: Use recursion & find all subsequences
 * 
 */ 

#include <iostream>
#include <vector>
using namespace std;

int subsetSum(vector<int>& subset, int currSum, int findSum, int index) {
    if(index>=subset.size()) {
        if(currSum==findSum) return 1;
        return 0;
    }
    int isSumEqual=0;
    int leftResults = subsetSum(subset, currSum+subset[index], findSum, index+1);
    int rightResult = subsetSum(subset, currSum, findSum, index+1);
    return leftResults + rightResult;
}

int main() {
    vector<int> store = {10, 12, 15, 6, 19, 20, 5, 1};
    int sumRequired=6;
    cout<<subsetSum(store, 0, sumRequired, 0);
}