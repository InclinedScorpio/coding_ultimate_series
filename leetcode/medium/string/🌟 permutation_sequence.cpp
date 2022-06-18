// https://leetcode.com/problems/permutation-sequence/

/**
 * LOGIC: Similar to Next permutation/ Next greatest problem
 * Q) But what's the logic to next greatest?
 * A) 'From right' check if num is smaller than next one
 * - But why we are checking it?
 * - Think about the last possible permutation? - It will be decreasing order
 * - Decreasing order means each index will be greatest than next
 * - We can't find next greatest from here
 * 
 * - That's why we need at least one num to be smaller than next one
 * - So we can swap it and make the next permutation/next greater
 * 
 * - !NEXT_STEP!
 * - Now we will find the just greater number from current index to the right
 * - Why? so that we are finding the immediate next greater number only
 * - Once we find, we will SWAP!
 * 
 * - LAST_STEP!
 * - Now SORT all numbers from index swapped to right!
 * - Why? To make sure it's next immediate greatest
 * 
 * COMPLEXITY: O(N^2logN)
 * 
 */ 
class Solution {
public:
    string nextPermutation(string str) {
        int ind=-1;
        for(int i=str.length()-2;i>=0;i--) {
            if(str[i]<str[i+1]) {
                ind = i;
                break;
            }
        }
        if(ind==-1) return str;
        char moreThan = str[ind];
        char swapWith = 'a'; // so while comparison, it's always greatest(initial_val)
        int swapInd=0;
        for(int i=ind+1;i<str.length();i++) {
            if(str[i]>moreThan && str[i]<swapWith) {
                swapWith = str[i]; swapInd = i;
            }
        }

        swap(str[ind], str[swapInd]);
        sort(str.begin()+ind+1, str.end());
        return str;
    }
    
    string getPermutation(int n, int k) {
        string str = "";
        while(n) {
            str=to_string(n)+str;
            n--;
        }
        
        k--;
        while(k--) {
            str = nextPermutation(str);
        }
        
        return str;
    }
};