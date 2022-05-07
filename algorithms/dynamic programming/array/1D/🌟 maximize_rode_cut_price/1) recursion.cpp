/**
 * QUESTION: Cut the rod in such a way that maximum profit is generated
 * 
 * LOGIC: Multiple cases to choose from - case of recursion
 * - Hence we are doing simple recursion
 * 
 * 
 * COMPLEXITY: O(rateSize^RodSize) (assuming{1} is rod size - to worse case will turnout to be Rod Size)
 * 
 */ 

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// Top Down Approach
int cutRodForMaxProfit(vector<int>& rate, int rodSize, int cutPrice=0) {
    if(rodSize==0) return cutPrice;
    int maxValue=INT_MIN;
    for(int i=0;i<rate.size();i++) {
        if(rodSize-(i+1)<0) continue;
            maxValue = max(maxValue, cutRodForMaxProfit(rate, rodSize-(i+1), rate[i]));
    }
    return cutPrice+maxValue;
}

int main() {
    vector<int> rate = {1, 5, 8, 9, 10, 17, 17, 20};
    int rodSize = 8;
    cout<<cutRodForMaxProfit(rate, rodSize);
}