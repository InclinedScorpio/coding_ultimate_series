// https://binarysearch.com/problems/Furthest-From-Origin

/**
 * LOGIC: Basic
 * - L can be considered as -1
 * - R to be +1
 * - and ? to be decided at last based on the value
 * 
 */ 
int solve(string s) {
    int farFromOrigin=0, addTheseMany=0;
    for(int i: s) {
        if(i=='L') farFromOrigin+=-1;
        else if(i=='R') farFromOrigin++;
        else addTheseMany++;
    }
    return abs(farFromOrigin) + addTheseMany;
}
