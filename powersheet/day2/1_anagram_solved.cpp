// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> copyStr = strs;
        for(int i=0;i<copyStr.size();i++) {
            sort(copyStr[i].begin(), copyStr[i].end());
        }

        unordered_set<int> taken;
        vector<vector<string>> output;
        for(int i=0;i<strs.size();i++) {
            if(taken.find(i)!=taken.end()) {
                continue;
            }
            vector<string> newly={strs[i]};
            taken.insert(i);
            for(int j=i+1;j<strs.size();j++) {
                if(taken.find(j)!=taken.end()) {
                    continue;
                }
                if(copyStr[i]==copyStr[j]){
                    taken.insert(j);
                    newly.push_back(strs[j]);
                }
            }
            output.push_back(newly);
        }
        return output;
    }
};