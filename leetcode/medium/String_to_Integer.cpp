// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        int result = 0;

        //Discard whitespaces in the beginning
        while (i < s.length() && s[i] == ' ')
            i++;

        // Check if optional sign if it exists
        if (i < s.length() && (s[i] == '+' || s[i] == '-'))
            sign = (s[i++] == '-') ? -1 : 1;

        // Build the result and check for overflow/underflow condition
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            if (result > INT_MAX / 10 ||
                    (result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + (s[i++] - '0');
        }
        return result * sign;
    }
};
