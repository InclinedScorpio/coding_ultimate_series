// https://leetcode.com/problems/get-equal-substrings-within-budget/description/

/**
 * LOGIC: Think of sliding window as we need to find the max substring within budget
*/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int first=0, second=0;
        int existingCost = maxCost;
        int maxLength=0;
        while(second<s.length()) {
            if(
                (
                    existingCost - abs(s[second]-t[second])
                ) >= 0
            ) {
                maxLength = max(maxLength, (second - first + 1));
                existingCost -= abs(s[second]-t[second]);
                second++;
            } else { // can't be taken
                if(first==second) {
                    first++;
                    second++;
                } else {
                    existingCost += abs(s[first]- t[first]);
                    first++;
                }
            }
        }
        return maxLength;
    }
};