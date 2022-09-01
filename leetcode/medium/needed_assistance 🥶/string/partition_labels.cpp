// https://leetcode.com/problems/partition-labels/

/**
 * LOGIC: Intuition was litte tedious but easy
 * - We just need to precalculate when the char is last occuring
 * - and now till that ind, we need to check if any in btw char is having even further occurance
 * - If yes update last occurance
 * 
 * - If you reach last occurance - just store the count and start over!
 * 
 */ 
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> store;
        for(int i=0;i<s.length();i++) store[s[i]] = i;
        
        int end = -1;
        vector<int> result;
        int counter=0;
        
        for(int i=0;i<s.length();i++) {
            counter++;
            if(end==i) {
                result.push_back(counter);
                counter=0;
            }
            if(store[s[i]]>end) {
                end = store[s[i]];
                if(end==i) {
                    result.push_back(counter);
                    counter=0;
                }
            }
        }
        return result;
    }
};