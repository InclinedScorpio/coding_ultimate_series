// https://binarysearch.com/problems/Phone-Number-Combinations

/**
 * LOGIC: Basic recursion
 * - Just know how to convert 'char to int'
 * - char a = '2';
 * -> (a - '0') -> this value is converted to int!
 * 
 */ 
void helper(string digits, vector<string>& store, int ind, vector<string>& result, string str) {
    if(ind>=digits.length()) {
        result.push_back(str);
        return;
    }
    for(int i=0;i<store[(int)(digits[ind] - '0')].length();i++) {
        helper(digits, store, ind+1, result, str+store[(int)(digits[ind] - '0')][i]);
    }
}

vector<string> solve(string digits) {
    vector<string> store(10);
    store[2] = "abc";
    store[3] = "def";
    store[4] = "ghi";
    store[5] = "jkl";
    store[6] = "mno";
    store[7] = "pqrs";
    store[8] = "tuv";
    store[9] = "wxyz";
    vector<string> result;
    helper(digits, store, 0, result, "");
    return result;
}