// https://binarysearch.com/problems/Narcissistic-Number

bool solve(int n) {
    int save = n, res=0, totalDig=to_string(n).length();
    while(n) {
        int dig=n%10;
        res = res + pow(dig, totalDig);
        n=n/10;
    }
    return res==save;
}
