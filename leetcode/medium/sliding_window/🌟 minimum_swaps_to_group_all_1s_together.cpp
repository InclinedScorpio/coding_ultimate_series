// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/

/**
 * QUESTION: We need to group all ones together given in [1, 0, 0, 1, 0, 1] with minimum swaps
 * LOGIC: Obviously we need to check all the cases but what are the range of cases? - range is no. of ones
 * - That means if we have 3 1's in total then we need to pick a window of 3 and keep shifting it
 * - While shifting we need to keep count of 0's and that would be the number of swaps we would require.. to have all 1's in that window
 * 
 * COMPLEXITY: O(N)
 *
 */ 
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones=0, zeroes=0;
        for(int i: data) {
            if(i==1) ones++;
        }
        
        for(int i=0;i<ones;i++) 
            if(data[i]==0) zeroes++;
        
        int swaps=zeroes;
        for(int i=ones;i<data.size();i++) {
            // sliding window reduce from left
            if(data[i-ones]==0) zeroes--;

            // sliding window increase to curr ind
            if(data[i]==0) zeroes++;
            
            // if no. of zeros in curr window is less - update!
            if(zeroes<swaps) swaps = zeroes;
        }
        return swaps;
    }
};