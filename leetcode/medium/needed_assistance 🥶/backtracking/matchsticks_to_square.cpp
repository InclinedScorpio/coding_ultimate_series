// https://leetcode.com/problems/matchsticks-to-square/

/**
 * LOGIC: First thing - it's easy to understand it's a core recursion, backtracking problem
 * - As we need to check multiple things
 * - But we don't need to play with number here, rather think about the ideal scenarion how we would have done in reality
 * - Keeping and checking the sticks on 4 sides and then checking and backtracking
 * - That's exactly what we are supposed to do here
 * 
 * COMPLEXITY: O(4^N)
 */
class Solution {
public:
    bool helper(vector<int>& matchsticks, int ind, int top, int bottom, int left, int right, int lenReq) {
        if(top == bottom && bottom == left && left == right && right == lenReq) return true;
        if(ind>=matchsticks.size()) return false;
        if(top>lenReq || bottom>lenReq || left>lenReq || right>lenReq) return false;
        
        int res = helper(matchsticks, ind+1, top+matchsticks[ind], bottom, left, right, lenReq);
        if(res) return res;
        
        res = helper(matchsticks, ind+1, top, bottom+matchsticks[ind], left, right, lenReq);
        if(res) return res;
        
        res = helper(matchsticks, ind+1, top, bottom, left+matchsticks[ind], right, lenReq);
        if(res) return res;

        res = helper(matchsticks, ind+1, top, bottom, left, right+matchsticks[ind], lenReq);
        if(res) return res;

        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int sum = 0;
        for(int i: matchsticks) sum+=i;
        if(sum%4!=0) return false;
        sum=sum/4;
        return helper(matchsticks, 0, 0, 0, 0, 0, sum);
    }
};