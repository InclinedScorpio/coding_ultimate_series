// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/

/**
 * LOGIC: Main logic is just to understand how to create postSum, rest of the problem is basic DP!
 * - Postsum means from an index, we are checking the apples to right-lower part of 2d matrix starting from there
 * - This we can find by adding total apples from right and lower part
 * - But when we take lower part, it will overlap the right part and will give more apples (not correct answer)
 * - Hence we need to subtract Union of(lower and right part )- i.e [ind+1][jnd+1]
 * - Also we need to do + 1 if at current position we have an apple!
 * 
 * - Once above postSum matrix is done, now just do the question as per given condition and start cutting from each row and col
 * - But make sure to memoize as there will be multiple sub problem created
 * 
 */ 
class Solution {
public:
    long long helper(vector<string>& pizza, int ind, int jnd, vector<vector<int>>& postSum, int k, vector<vector<vector<int>>>& dp) {
        if(ind>=pizza.size() || jnd>=pizza[ind].size()) return 0; 
        
        if(dp[ind][jnd][k]!=-1) {
            return dp[ind][jnd][k];
        }
        
        //cuts are done and ending section has apple remaining then return 1
        if(k==0 && postSum[ind][jnd]>0) return dp[ind][jnd][k]=1;
        // cuts are done but ending section doesn't hava apple remaining
        if(k==0 && postSum[ind][jnd]==0) return dp[ind][jnd][k]=0;
        
        long long sum=0;
        
        // cut from row
        for(int i=ind; i<pizza.size();i++) {
            // check the upper part if possible
            int isPizzaAvailableAtTop = postSum[ind][jnd] - postSum[i+1][jnd];
            if(isPizzaAvailableAtTop<=0) continue;
            // can be cut horizontally at i
            sum=(sum+helper(pizza, i+1, jnd, postSum, k-1, dp))%1000000007;
        }
        
        // cut from col
        for(int j=jnd;j<pizza[ind].size();j++) {
            int isPizzaAvailableAtLeft = postSum[ind][jnd] - postSum[ind][j+1];
            if(isPizzaAvailableAtLeft<=0) continue;
            // can be cut vertically at j
            sum=(sum+helper(pizza, ind, j+1, postSum, k-1, dp))%1000000007;
        }
        //memoize!
        return dp[ind][jnd][k] = sum;
    }
    
    
    int ways(vector<string>& pizza, int k) {
        
        // create the postsum(from index think of a 2d matrix going right-down)
        vector<vector<int>> postSum(pizza.size()+1, vector<int>(pizza[0].size()+1, 0));
        for(int i=postSum.size()-2;i>=0;i--) {
            for(int j=postSum[i].size()-2;j>=0;j--) {
                postSum[i][j] = postSum[i+1][j] + postSum[i][j+1] + (pizza[i][j]=='A') - postSum[i+1][j+1];
            }
        }
        
        // create 3d vector to memoize! Without this-TLE!
        vector<vector<vector<int>>> dp(pizza.size()+1, vector<vector<int>>(pizza[0].size()+1, vector<int>(k+1, -1)));
        
        // use postsum to cut the pizza
        return helper(pizza, 0, 0, postSum, k-1, dp);
    }
};