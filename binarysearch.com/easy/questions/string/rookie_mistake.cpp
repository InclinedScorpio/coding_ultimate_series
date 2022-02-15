// https://binarysearch.com/room/Rabin-Karp-OjjZpRIYM3

/**
 * LOGIC: Basic
 * 
 */ 
bool solve(string s) {
    bool leftBlock=false, rightBlock=false, numReached=false;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='R' && !leftBlock) return true;
        if(s[i]=='R') numReached=true;
        if(s[i]=='B') if(leftBlock && numReached) rightBlock=true; 
        else if(!leftBlock) leftBlock=true;
    }
    if(rightBlock) return false;
    return true;
}