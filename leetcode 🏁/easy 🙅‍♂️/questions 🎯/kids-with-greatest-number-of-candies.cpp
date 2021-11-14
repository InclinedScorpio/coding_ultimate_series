// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int greatestNo=-1;
        for(int i=0;i<candies.size();i++) {
            if(greatestNo<candies[i]) {
                greatestNo=candies[i];
            }
        }
        
        vector<bool> result;
        for(int i=0;i<candies.size();i++) {
            if(candies[i]+extraCandies>=greatestNo) {
                result.push_back(true);
            }else {
                result.push_back(false);
            }
        }
        return result;
    }
};