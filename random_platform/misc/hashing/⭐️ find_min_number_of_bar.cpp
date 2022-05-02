/**
 * QUESTION: Find number of minimum bars which can be kept so all strings are covered
 * 
 *
 * LOGIC: As multiple cases are possible while thinking...
 * ... it's clear case of recursion
 * - It's important to understand that while recursion call we still need to keep evaulating curr string
 * - Map can be used to implement DP as we are evaluating same thing multiple times
 * 
 * 
 * COMPLEXITY: ??
 * 
 * 
 */ 
#include<iostream>
#include<queue>
#include<set>
#include<climits>
#include<unordered_map>

using namespace std;

int recurseNFindMinBar(string str, set<string>& store, int ind, unordered_map<int, int>& dp) {
    if(ind>=str.length()) return -1; // as division is not possible
    if(dp.count(ind)) return dp[ind];
    string currStr="";
    priority_queue<int, vector<int>, greater<int>> q;
    int minVal  = INT_MAX;
    for(int i=ind;i<str.length();i++) {
        currStr+=str[i];
        if(store.find(currStr)!=store.end()) {
            int res = recurseNFindMinBar(str, store, i+1, dp);
            minVal = min(res, minVal);
        }
    }
    if(minVal==INT_MAX) { // incase division made didn't match anything- means no further recursion was made above
        dp[ind]=0; 
        return 0; // so return 0 as no further division is possible
    }
    dp[ind]=minVal+1;
    return minVal + 1;
}

int minimumBar(string str, vector<string>& store) {
    set<string> storeMap;
    for(string i: store) {
        storeMap.insert(i);
    }
    unordered_map<int, int> dp;
    return recurseNFindMinBar(str, storeMap, 0, dp);
}

int main() {
    string str="thequickbrownfox";
    vector<string> store = {"the","quickbrown", "o", "fox", "quick", "brown"};
    cout<<minimumBar(str, store);
}
