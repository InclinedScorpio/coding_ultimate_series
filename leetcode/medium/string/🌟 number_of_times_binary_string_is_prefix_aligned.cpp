// https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/

/**
 * LOGIC: If we check 1 to left and right each time then it will be O(N^2)
 * - But we can simply create a set and insertion will be logN + checking previous(logN) + checkingNext(logN)
 * - Hence, resultant is O(NlogN)
 * - Also, imp to understand lower_bound, upper_bound and we can do -- operator on pointers as well to get previous item
 * COMPLEXITY: O(NlogN)
 */
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        set<int> store;
        store.insert(0);
        int diff=0;
        int result=0;
        for(int i=0;i<flips.size();i++) {
            store.insert(flips[i]);
            auto nextOne = store.upper_bound(flips[i]);
            auto lowerOne = store.lower_bound(flips[i]);
            if(nextOne!=store.end()) //next exists
                diff--;
            else { //next not exists 
                lowerOne--; //NOTE! This can be done
                diff+=(flips[i] - (*lowerOne) - 1);
            }
            if(diff==0) result++;
        }
        return result;
        
    }
};