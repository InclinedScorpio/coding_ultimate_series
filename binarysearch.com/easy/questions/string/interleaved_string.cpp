// https://binarysearch.com/problems/Interleaved-String

string solve(string s0, string s1) {
    int first=0, ind=0;
    int leftArr=0, rightArr=0;
    
    string res = "";

    while(leftArr<s0.length() && rightArr<s1.length()) {
        if(first==0) {
            res+=s0[leftArr++];
            first=1;
        }else {
            res+=s1[rightArr++];
            first=0;
        }
    }
    while((leftArr<s0.length())) {
        res+=s0[leftArr++];
    }
    while(rightArr<s1.length()) {
        res+=s1[rightArr++];
    }
    return res;
}