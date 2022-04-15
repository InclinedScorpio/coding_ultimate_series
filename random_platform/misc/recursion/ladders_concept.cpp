/**
 * QUESTION: How many ways can you reach step N of ladder if you can take 1,2,3 step at once
 * LOGIC: There can be many ways and at each point we can do 3 things
 * - "At each point we can do 3 things" - ! Recursion
 * - Hence we go for recursion
 * - So at each level we are having 3 things
 * COMPLEXITY: O(3^n)
 * 
 * IMPROVE: If you look closely...
 * - We are multiple times calculating some things multiple times
 * (Talking in case of bottom up, same can be implemented with top down)
 * - Let's say solutions from '2' onwards, we are calculating solutions from from (2 to 4) from both "0+1+1" onwards and "0+2" onward
 * - So, rather than doing again, store result somewhere & check
 * - This is DYNAMIC PROGRAMMING !
 * 
 */ 

#include <iostream>
#include <map>

using namespace std;

int countTotalSteps(int totalLadders, int currTotal, map<int, int> store) {
    if(currTotal==totalLadders) return 1;
    if(currTotal>totalLadders) return 0;
    if(store.find(totalLadders)!=store.end()) {
        return store[totalLadders];
    }
    int oneStepAdd = countTotalSteps(totalLadders, currTotal+1, store);
    int twoStepAdd = countTotalSteps(totalLadders, currTotal+2, store);
    int threeStepAdd = countTotalSteps(totalLadders, currTotal+3, store);
    store[totalLadders]=oneStepAdd + twoStepAdd + threeStepAdd; 
    return oneStepAdd + twoStepAdd + threeStepAdd;
}

int countStepsTopDown(int totalLadders) {
    if(totalLadders==0) return 1;
    if(totalLadders<0) return 0;
    return countStepsTopDown(totalLadders-1) + countStepsTopDown(totalLadders-2) + countStepsTopDown(totalLadders-3);
}

int main() { 
    int totalSteps = 4;
    map<int, int> store;
    
    // Bottom up approach - start from 0 and go till 4...
    cout<<countTotalSteps(totalSteps, 0, store);

    // Top down appraoch - start from totalSteps and go down to 0...
    // cout<<countStepsTopDownO(totalSteps);
}