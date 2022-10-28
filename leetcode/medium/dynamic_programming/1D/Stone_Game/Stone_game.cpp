//Question: https://leetcode.com/problems/stone-game/

//Solution

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

//Trick

//Whoever does the next picking (True for Alice, False for Bob) will try to get the max results from that pile state (starting and eding indices),
//so we keep track of turn using a boolean and assign the best value to right person in any given state using turn boolean.
