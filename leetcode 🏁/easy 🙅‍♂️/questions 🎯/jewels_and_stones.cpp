// https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int jewel_in_stone=0;
        
        map<char,int> jewel_map;
        for(int i=0;i<jewels.length();i++) {
                jewel_map[jewels[i]] = 1;
        }
        for(int i=0;i<stones.length();i++) {
            if(jewel_map.count(stones[i])==1) {
                jewel_in_stone++;
            }
        }
        return jewel_in_stone;
    }
};