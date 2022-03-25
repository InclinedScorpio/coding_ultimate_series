// https://binarysearch.com/problems/Add-Binary-Numbers

/**
 * LOGIC: Basic, only catch is to understand 2 things:
 * - How string works - "abc" - a is 0th index
 * - And how addition of binary takes place (REVERSE need to be used), Example
 * 1 0
 * + 1 = 
 * 1 1
 * 
 * But as per what we get in params is
 * 1 0
 * 1 +
 * - Incorrect, HENCE HAS TO BE REVERSED !
 * - This line helps to not reverse it again 
 * .... result = numInBin[1] + result;
 * - It's understand through scratch
 * 
 */ 
string intToBin(int num) {
    if(num==0) return "00";
    if(num==1) return "01";
    if(num==2) return "10";
    else return "11";
}

string solve(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int i=0;
    int carry=0;
    string result="";
    while(i<a.length() || i<b.length() || carry) {
        int numSum = carry;
        if(i<a.length()) numSum += (a[i]-48);
        if(i<b.length()) numSum += (b[i]-48);
        string numInBin = intToBin(numSum);
        carry = numInBin[0]-48;
        result = numInBin[1] + result;
        i++;
    }

    return result;
}