// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        // keep the max item count and total item count, and if replacement won't
        // work then move left pointer forward
        int left=0, right=0, maxVal=0, totalLen=0, result=0;
        unordered_map<char, int> store;

        while(right<s.length()) {
            // check curr char is existing, if not add it to store
            // if exists, increment it and check if this is curr max
            // increment length
            store[s[right]]++;
            maxVal = max(store[s[right]], maxVal);
            totalLen++;

            if((totalLen-maxVal)<=k) {
                result = max(totalLen, result);
            } else {
                while((totalLen-maxVal)>k) {
                    store[s[left]]--;
                    totalLen--;
                    if((store[s[left]]+1)==maxVal) {
                        // make sure to pick the next maxVal
                        maxVal=store[s[left]];
                        for(auto a: store) {
                            maxVal = max(maxVal, store[a.first]);
                        }
                    }
                    left++;
                }
            }
            right++;
        }
        return result;
    }
};