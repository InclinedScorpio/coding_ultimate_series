// https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string output="";

        if(strs.size()==0 || strs[0].size()==0) return "";

        int iter=0;
        for(int i=0;i<strs[0].length();i++) {
            for(int j=1;j<strs.size();j++) {
                if(strs[j].length()<=iter || strs[0][iter]!=strs[j][iter]) return output;
            }
            output+=strs[0][iter++];
        }
        return output;
    }
};