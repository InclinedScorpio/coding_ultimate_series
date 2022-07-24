// https://binarysearch.com/problems/Longest-1s-After-One-Swap

/**
 * LOGIC: Greedy problem!
 * - 0 111 0 111 0 1
 * - keep record of previous and current 1's and check max at each step
 * - If 0 is encountered, just give curr to prev and curr 0
 * - Also keep a count for the total
 * 
 * - At last if the max is less than total that means there is some 1 other than max containing curr and prev
 * - Hence add 1 if tot > maxVal
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
int solve(string s) {
    int curr=0, prev=0, total=0, maxVal=0;
    for(char i: s) {
        if(i=='1') {
            curr++;
            total++;
        } else {
            prev = curr;
            curr=0;
        }
        maxVal = max(maxVal, prev+curr);
    }
    return maxVal + (maxVal < total);
}