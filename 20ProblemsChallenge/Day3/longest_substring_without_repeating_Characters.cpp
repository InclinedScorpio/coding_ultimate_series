// https://leetcode.com/problems/longest-substring-without-repeating-characters


/**
 * 
 * Blind 75 Problem
 * Sliding window problem
 * 
 */
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if(s.length()==0) return 0;
    
            int left=0;
            int right=0;
            unordered_map<int, int> store;
    
            store[s[0]]++;
            right++;
    
            int result=1;
            while(right<s.length()) {
                while(right<s.length() && store.find(s[right])==store.end()) {
                    store[s[right]]++;
                    right++;
                    result = max(result, (right-left));
                }
                if(right>=s.length()) break;
                while(left<s.length()&& s[left]!=s[right]) {
                    // cout<<"s[left] -> "<<s[left]<<" ";
                    if(store[s[left]]==1) {
                        store.erase(s[left]);
                    }else {
                        store[s[left]]--;
                    }
                    left++;
                }
                if(store[s[left]]==1) {
                        store.erase(s[left]);
                }else {
                        store[s[left]]--;
                }
                left++;
            }
    
            return result;
        }
    };