// https://leetcode.com/problems/group-anagrams/
/**
 * Alternative: Rather than matching vector<int>
 * We can also sort the string and match them instead
 * 
 * For sorting we can create a custom method
 * - As it will take only O(n) to sort as it's only smaller alphabets
 *  
 */ 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> store;
        
        for(int i=0;i<strs.size();i++) {
            vector<int> vec(26, 0);
            for(int j=0;j<strs[i].length();j++) {
                vec[strs[i][j] - 'a'] = vec[strs[i][j] - 'a']+1;
            }
            store[vec].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for(auto&s: store) {
            result.push_back(s.second);
        }
        return result;
    }
};