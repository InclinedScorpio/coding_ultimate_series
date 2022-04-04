// https://binarysearch.com/problems/Base-3-to-Integer

int solve(string s) {
    int result=0;
    int power=0;
    for(int i=s.length()-1;i>=0;i--) result += (s[i] - '0')*pow(3, power++);
    return result;
}