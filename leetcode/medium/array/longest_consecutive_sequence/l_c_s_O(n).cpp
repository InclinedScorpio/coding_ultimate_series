// https://leetcode.com/problems/longest-consecutive-sequence/


/**
 * 
 * NOTE: BETTER VERSION OF THIS CODE IS BELOW (SCROLL DOWN)
 * - Issue with this version is it will take O(NlogN)
 * 
 * LOGIC: We know map gives the keys sorted when asked 
 * - Store the items in map 
 * - Now start iterating and keep checking if earlier number was already there or not in map - O(1)
 * - If it was there, increment counter (and save counter if it's maximum)
 * - If it wasn't decrement counter
 * 
 * - At last return the max counter and do +1 as the first element in longest sequence was not taken into account in above strategy
 * 
 * COMPLEXITY: O(NlogN)
 * - CAN BE BETTER !!!! (Scroll down)
 * 
 */ 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0) { //edge case, bad practice :)
            return 0;
        }
        
        map<int, int> store; //store will keep the keys which are present
        
        for(int i=0;i<nums.size();i++) { //fill up the store
            store[nums[i]]=1;
        }
        
        int maxCounter=0, counter=0; //will help us to store max counter value and current counter
        for(auto i: store) { //start iterating over store
            if(store.find(i.first -1) != store.end()) { // check for previous key in store, if present that means it's part of sequence
                counter++;
                if(maxCounter<counter) {
                    maxCounter = counter;
                }
            }else { // if chain breaks, i.e previous value is not present in store, just reset the counter
                counter=0;
            }
        }
        return maxCounter+1;
    }
};

/**
 * BETTER VERSION
 * - As we shouldn't sort it
 * - We can make use of hashing to keep all numbers
 * - And then iterate over that hash to check if previous number exists
 * 
 * - Important to check if previous exists as if previous exist, then we won't start checking the sequence
 * - So that we are not checking sequence every time we are iterating over
 * - This prevents doing O(N^2) rather than O(N) ⭐️
 * 
 * COMPLEXITY: O(N)
 * SPACE: O(N)
 * 
 */ 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> storage;
        for(int num: nums)
            storage.insert(num);
        
        int maxRes = 0;
        for(int store: storage) {
            int temp = store-1;
            int count=1;
            if(storage.find(temp)==storage.end()) {
                temp+=2;
                while(storage.find(temp)!=storage.end()) {
                    count++;
                    temp++;
                }
                if(count>maxRes) maxRes = count;   
            }
        }

        return maxRes;
    }

};