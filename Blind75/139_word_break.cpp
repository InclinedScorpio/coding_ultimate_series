// https://leetcode.com/problems/word-break/description


/**
 * LOGIC:
 * Using of set and recursion is the main point here
 * we need to check for each index if we can break the string from that index or not
 * if we can break then we will check for next index and so on
 * if we can break till end then we return true
 * if we can't break then we will add that index to checker set so that we don't check
 * that index again and return false
 * 
 */
class Solution {
public:
    bool helper(string&s, int ind, unordered_set<string>& store, unordered_set<int>& checker) {
        if(ind==s.length()) return true;
        if(checker.find(ind)!=checker.end()) return false;
        string str ="";
        for(int i=ind;i<s.length();i++) {
            str+=s[i];
            if(store.find(str)!=store.end()) {
                bool check = this->helper(s, i+1, store, checker);
                if(check) return true;
                checker.insert(ind);
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> store;
        unordered_set<int> checker;
        for(string str: wordDict) {
            store.insert(str);
        }
        return this->helper(s, 0, store, checker);

    }
};