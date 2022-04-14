// https://binarysearch.com/problems/Social-Distancing

bool solve(string s, int k) {
    int saveK = k;
    k=k+(k-1);
    int count=0;
    bool isDot=false;
    if(s[0]=='.') {
        count=(saveK-1);
    }
    for(int i=0;i<s.length();i++) {
        if(s[i]=='.') {
            if(isDot) {
                count++;
            } else {
                isDot=true;
                count++;
            }
            if(count==k) return true;
        } else {
            isDot=false;
            count=0;
        }
    }
    if(count>(k/2)) return true;
    return false;
}