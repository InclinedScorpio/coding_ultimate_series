// https://leetcode.com/problems/find-the-town-judge/

/**
 * LOGIC: 
 * - Decrement who is giving vote
 * - Increment who is receiving vote
 * 
 * IMPORTANT: (LOGIC)
 * - At end iterate and check if any value is (n-1)...
 * ... means all others have given the vote to that person
 * 
 */ 
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 and n==1) return 1;
        else if(trust.size()==0 and n>1) return -1;
        
        vector<int>store(n+1, 0);
        for(int i=0;i<trust.size();i++) {
            store[trust[i][0]]--;
            store[trust[i][1]]++;
        }
        
        for(int i: store) {
            cout<<i<<" ";
        }
        
        for(int i=0;i<n+1;i++) {
            if(store[i]==n-1) {
                return i;
            }
        }
        return -1;
    }
};
