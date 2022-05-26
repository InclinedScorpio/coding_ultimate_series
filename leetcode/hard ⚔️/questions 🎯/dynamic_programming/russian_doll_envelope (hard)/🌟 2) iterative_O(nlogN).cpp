// https://leetcode.com/problems/russian-doll-envelopes/

/**
 * LOGIC: This is a trick question
 * - Here we can sort using the width and pick height in LIS - that will be answer
 * - BUT! if we do that same width can come in answer, hence in order to prevent that we need to sort reverse the height where width is same
 * - ⭐️ The line above is the main logic of this problem 
 * 
 * COMPLEXITY: O(NlogN)
 * 
 */
class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b) {
        return a[0]==b[0]? (a[1]>b[1]): a[0]<b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comparator);
        
        vector<int> store(envelopes.size());
        for(auto envelope: envelopes) {
            store.push_back(envelope[1]);
        }
        
        vector<int> result = {store[0]};
        // Apply LIS on height
        for(int i=0;i<store.size();i++) {
            if(store[i]>result[result.size()-1]) {
                result.push_back(store[i]);
            } else {
                int ind = lower_bound(result.begin(), result.end(), store[i]) - result.begin();    
                result[ind]=store[i];
            }
        }
        return result.size()-1;
    }
};