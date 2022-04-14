/**
 * QUESTION: Maximize the minimum subarray (Game of Greed Problem)
 * - Question similar to Angry Bird problem - Monotonic Binary Search implementation
 * 
 * PROBLEM: We are given with coins value and k group of friends will take some subarray
 * - It's known that k-1 friends will take the largest chunk available and you will be left with least one
 * - Maximize your chunk(subarray), other chunks must be equal or greater than yours
 * Q) [10, 20, 30, 40]
 * A) Let's say these are coin value given!
 * - Now, how to know how to maximize my chunk? 
 * - Ok let's see if I can get atleast 1 coins 
 * (10), (20), (30) - all 3 friends are satisfied with 1, so I atleast got 1
 * - Now let's try 2 as well....
 * - Now let's try 30 as well
 * (10 + 20), (30), (40) -> Coins received are -> (30), (30), (40)
 * - I atleast got 30 which is my maximum, others got equal or more :)
 * 
 * - Now, if we take 31, it won't work as (10+20+30), (40) -> for 3rd friend no coins left!
 * - So, 30 became the answer.
 * 
 * - But we observed we took from 1...2..3..4..5..6..7......30
 * - Which is monotonic, and we need to maximize it! Hence we used monotonic Binary Search
 * 
 * - Rather than taking 1...2...3...4..5 we will make use of Binary Search to maximize it!
 * - Idea: Binary search will move left if a point is not possible and right if it's possible
 * - The idea that it moves right if it's possible is the whole logic of monotonic Binary Search
 * 
 * COMPLEXITY: O(NlogN)
 * 
 */ 

#include<iostream>
#include<vector>

using namespace std;

bool checkMinCoinPossible(vector<int>& coins, int totalPartition, int minCoins) {
    int currSum=0;
    int currPartition=0;
    for(int i=0;i<coins.size();i++) {
        currSum+=coins[i];
        if(currSum>=minCoins) {
            currPartition++;
            currSum=0;
            if(currPartition==totalPartition) {
                return true;
            }
        }
    }
    return false;
}

int maximizingMinimumCoins(vector<int>& coins, int partition) {
    int totalCoinsPossible=0;
    for(int i: coins) {
        totalCoinsPossible+=i;
    }
    int left=1, right=totalCoinsPossible;
    int latestAns=-1;
    while(left<=right) {
        int mid = (left+right)/2;
        bool isPartitionPossible = checkMinCoinPossible(coins, partition,  mid);
        if(isPartitionPossible) {
            latestAns = mid;
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return latestAns;
}

int main() {
    vector<int> coins = {10, 23, 20, 40, 30, 100, 22, 54, 87, 93, 23};
    int partition=3;
    cout<<maximizingMinimumCoins(coins, partition);
}