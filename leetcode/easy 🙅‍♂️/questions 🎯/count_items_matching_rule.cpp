// https://leetcode.com/problems/count-items-matching-a-rule/

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int res=0;
        int member;
        if(ruleKey=="type") {
            member=0;
        }else if(ruleKey=="color") {
            member=1;
        }else {
            member=2;
        }
        for(int i=0;i<items.size();i++) {
            if(items[i][member] == ruleValue) {
                res++;
            }
        }
        return res;
    }
};