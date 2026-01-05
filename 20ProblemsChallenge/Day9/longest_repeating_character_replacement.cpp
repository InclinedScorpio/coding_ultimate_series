// https://leetcode.com/problems/longest-repeating-character-replacement/

/**
 * 
 * LOGIC:
 * the math is important
 * understanding that each subset we need to see if length - maxFreq <=k, if yes then length is valid
 * just check max valid length, thats the answer
 * 
 * Use 2 pointer approach, when <=k is not satisified that means that subset can't be picked so increase left
 * This way it will be only O(n)
 * 
 */
class Solution {
public:
    int characterReplacement(string s, int k) {

        int left=0,right=0;
        int maxFound=0;

        unordered_map<char, int> store;


        while(right<s.length()) {
            store[s[right]]++;

            int maxFreq=0;
            for(auto st: store) {
                maxFreq=max(maxFreq, st.second);
            }

            int toChange = (right - left + 1) - maxFreq;
            if(toChange<=k) {
                maxFound = max(maxFound, (right - left + 1));
                right++;
            } else {
                store[s[left]]--;
                store[s[right]]--;
                left++;
            }
        }
        return maxFound;
    }
};

