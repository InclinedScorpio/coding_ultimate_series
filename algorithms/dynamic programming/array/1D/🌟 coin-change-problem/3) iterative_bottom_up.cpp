


/**
 * QUESTION: Given set of coins & value to be created
 * - find min no of coins required to create that value
 * 
 *  
 * LOGIC: Do recursive approach (Top Down) to understand how we reached to bottom up approach
 * 
 * BOTTOM UP APPROACH (iterative) - array used so we can use previously stored things
 * Q) How to form logic for bottom up?
 * A) We need to think about the recursive appraoch done before
 * - F(n) = min(nums-store[num - coins[0], num - store[num])+1
 * So, same thing we will do in array as well
 * 0th index means 0 coins - can be made by 0 coins
 * Now on 1st index, we have coins {1} -> which satisfies (index-1)>0
 * - Hence we need to check (1-1) -> 0th index(how many min coins required to form it) + 1
 * - Again for index 1, we need to pick next coins {3} -> but this time (1-3)<0 hence can't pick it
 * - Similarly only 1 will work out in 1st index
 * 
 * So, basically we are keeping array which indicates minimum coins required on each index
 * - We will keep founding till value given so min Value can be found that minimum Value 
 * 
 * COMPLEXITY: O(value*No.of.coins)
 */ 

#include<iostream>
#include<vector>
#include<climits> 
#include<unordered_map>
#include<cstring>

using namespace std;

int findMinCoins(vector<int> coins, int totalVal) {

    int minCoins[totalVal+1];
    memset(minCoins, 0, totalVal+1);
    for(int i=1;i<=totalVal;i++) {
        int minValue=INT_MAX;
        for(int j=0;j<coins.size();j++) {
            if(i-coins[j]<0) continue;
            minValue = min(minValue, minCoins[i-coins[j]]+1);
        }
        if(minValue==INT_MAX)continue;
        minCoins[i]=minValue;
    }
    return minCoins[totalVal];
}

int main() {
    // coins - {1, 3, 7, 10}
    // to create -> 15 | find minimum no of coins required
    vector<int> coins  = {1, 3, 7, 10};
    int totalVal = 10;
    cout<<findMinCoins(coins, totalVal);
}
