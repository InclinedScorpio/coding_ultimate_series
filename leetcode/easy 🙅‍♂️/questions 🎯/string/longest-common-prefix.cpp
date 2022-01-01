// https://leetcode.com/problems/longest-common-prefix/

/**
 * Was stuck at one of the if condition. 
 * 
 * 
 */ 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        string result = "";
        
        //find min length string
        int minLenIndex = 0;
        for(int i=0;i<strs.size();i++) {
            if(strs[i].length()<strs[minLenIndex].length()) {
                minLenIndex = i;
            }
        }
        
        // was stuck here- memory issue otherwise
        if(strs[minLenIndex].length()==0) {
            return "";
        }
        
        // multiple times need to iterate over the array
        while(true) {
            for(int i=0;i<strs.size();i++) {
                
                // if curr index string is not eq to 0th string taken
                if(strs[i][index]!=strs[minLenIndex][index]){
                    return result;
                }
            }
            result += strs[minLenIndex][index];
            if(index == strs[minLenIndex].length()-1) {
                return result;
            }
            index++;
        }
        
    }
};