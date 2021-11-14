// https://leetcode.com/problems/shuffle-string/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string response;
        vector<char> result;
        map<int, char> charIntMap;
        for(int i=0;i<indices.size();i++) {
            charIntMap[indices[i]] = s[i];
        }
        
        for(int i=0;i<indices.size();i++) {
            response+=charIntMap[i];
        }
        
        return response;
    }
};