// https://binarysearch.com/problems/Consecutively-Descending-Integers

/**
 * LOGIC: Rather than checking all numbers
 * - Rather pick initial subset and append smaller ones
 * - Stop when length is equal ore more than s
 * - coz that is when you we need to check if string formed is similar
 * 
 */ 
bool solve(string s) {
    for(int i=0;i<s.length()/2;i++) {
        int currNum=stoi(s.substr(0, i+1));
        string res=to_string(currNum);
        while(res.length()<s.length()) {
            res+=to_string(--currNum);
        }
        if(res==s) return true;
    }
    return false;
}