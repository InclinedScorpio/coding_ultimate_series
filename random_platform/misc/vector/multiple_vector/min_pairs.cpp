/**
 * QUESTION: Given 2 array, find two num- one from each whose absolute diff is least
 * LOGIC: We can absolutely take one by one from one of the vector and check least by comparing....
 * - ...with each from the other - Complexity o(N*M)
 * -  LET's OPTIMIZE IT!
 * - We can sort one of them - NlogN
 * - Now just pick and one from other and do Binary search in sorted one
 * - As we would use lower_bound(logM)
 * - So total complexity would be - O(nLogn) + O(mLogn)
 * 
 * COMPLEXITY: O(NlogN) + O(MLogN)
 * Sorting + comparing using lower_bound
 * 
 */ 
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

pair<int,int> min_pair(vector<int>& s1, vector<int> s2) {
    sort(s1.begin(), s1.end());
    // one is sorted, use lower_bound now to check nearest num
    // lower_bound returns first occurance or first just greater
    // so check both lower_bound and one less than that :)
    pair<int, int> leastOnePair;
    int leastDiff=INT_MAX;

    for(int i=0;i<s2.size();i++) {
        int rightOne = abs(s2[i] - *lower_bound(s1.begin(), s1.end(), s2[i]));
        int leftOne = abs(s2[i] - *(lower_bound(s1.begin(), s1.end(), s2[i])-1));
        if(min(leftOne, rightOne)<leastDiff) {
            leastDiff = min(leftOne, rightOne);
            if(rightOne<leftOne) {
                leastOnePair = {*lower_bound(s1.begin(), s1.end(), s2[i]), s2[i]};
            } else {
                leastOnePair = {abs(s2[i] - *(lower_bound(s1.begin(), s1.end(), s2[i])-1)), s2[i]};
            }
        }
    }
    return leastOnePair;
}

int main() {
    vector<int> s1= {-1, 5, 10, 20, 3};
    vector<int> s2= {26, 134, 135, 15, 17};
    pair<int, int> result = min_pair(s1, s2);
    cout<<result.first<<" "<<result.second;
}