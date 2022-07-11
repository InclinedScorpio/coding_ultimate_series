// https://binarysearch.com/problems/The-Accountant

/**
 * LOGIC: Important to understand that as A-Z (1 indexed)
 * - At each iteration we need to convert it to 0 based by n--
 * - That's the crux of the problem
 * 
 * NOTE: Rather than n--, we can simply do (n-1) as well everywhere with condition of n>=1
 * 
 */ 
string solve(int n) {
    string res="";
    while(n>0) {
        n--;
        int add=(n%26);
        res+='A' + add;
        n=n/26;
    }
    reverse(res.begin(), res.end());
    return res;
}
