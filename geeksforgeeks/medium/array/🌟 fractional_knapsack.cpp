// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#

/**
 * LOGIC: THis is not 0/1Knapsack Problem. Here fractions can also be considered
 * - This is a GREEDY PROBLEM
 * 
 * - Here as we need to maximimze the value in knapsack
 * - Hence we need to consider the ones with max (value/wt) first
 * - Also need to check that weight shouldn't extend than given one
 * - For current one if wt exceeds the allowed weight then just take a fraction of it
 * 
 * COMPLEXITY: O (NlogN)
 * 
 */ 
class Solution {
   public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        vector<pair<double, double>> store;
        for(int i=0;i<n;i++) {
            store.push_back({arr[i].value/(double)arr[i].weight, arr[i].weight});
        }
        sort(store.begin(), store.end(), greater<pair<double, double>>());
        
        double result=0, wtKept=0;
        for(int i=0;i<n;i++) {
            if((wtKept+store[i].second)<=W) {
                wtKept+=store[i].second;
                result+=(store[i].first * store[i].second);
            } else {
                double remainingWt = W - wtKept;
                result+=(store[i].first * (remainingWt));
                break;
            }
        }
        return result;
    }
};