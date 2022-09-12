// https://leetcode.com/problems/largest-number/

/**
 * LOGIC: Trick is to use a+b > b+a in order to check if 30, 3 should be ordered as 3, 30
 *
 */
int checker(string a, string b) {
    return a+b>b+a; //trick!
}

class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        
        vector<string> result;
        for(int i=0;i<nums.size();i++) {
            result.push_back(to_string(nums[i]));
        }
        
        sort(result.begin(), result.end(), checker);
        string res="";
        for(string i: result) {
            res+=i;
        }
        string removeZeroes="";
        int zerosAt=0;
        for(int i=0;i<res.length();i++) {
            if(res[i]=='0') zerosAt=i;
            else break;
        }
        return zerosAt==res.length() ? "0" : res.substr(zerosAt);
    }
};