// https://leetcode.com/problems/candy/

/**
 * NOTE: Gives TLE (just for understanding)
 * 
 * LOGIC: We can clearly see in scratch that backtracking is what we are doing
 * 
 */ 
class Solution {
public:
    bool helper(vector<int>& ratings, vector<int>& candies, int ind, int& sum) {
        if(ind>=ratings.size()) return true;
        int startFrom=1;
        
        if(ind!=0 && ratings[ind-1]<ratings[ind]) {
            startFrom = candies[ind-1]+1;
        }
        
        for(int i=startFrom;i<=20001;i++) {
            if(ind!=0 && ratings[ind-1]>ratings[ind] && candies[ind-1]<=i) { // edge
                return false;
            }
            candies[ind]=i;
            sum+=i;
            bool res = helper(ratings, candies, ind+1, sum);
            if(res) return true;
            sum-=i;
        }
        return false;
    }
    
    int candy(vector<int>& ratings) {
        int sum=0;
        vector<int> candies(ratings.size(), 1);
        helper(ratings, candies, 0, sum);
        return sum;
    }
};