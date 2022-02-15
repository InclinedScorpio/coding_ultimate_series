// https://binarysearch.com/problems/Integer-to-Base-3

string solve(int n) {
    if(n==0) return "0";
    string ans= "";
    while(n) {
        ans+=to_string(n%3);
        n=n/3;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}