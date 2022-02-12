// https://binarysearch.com/problems/Reverse-Sublists-to-Convert-to-Target

/**
 * QUESTION: Check if by reversing any no of sublist, reversing any no. of times...
 * you can achieve the given target
 * 
 * LOGIC: If all digits are same in both array
 * - we can always achieve the target
 * 
 * HOW: 
 * Consider [1, 2, 3, 8, 9]
 * Target to achieve [3,2,1,9,8]
 * 
 * THINKING:
 * - At first pos, we want 1 but now it's 3, so let's find 1 and reverse
 * - 1 found at index 3, so reverse 0 to 3
 * - Result [1,2,3,9,8]
 * - Let's move forward to index 2, ah it's at correct pos
 * - Let's move forward to index 3, ah it's at correct pos
 * - Let's move forward to index 4, oops it's wrong it's 9... we want 8 so let's find 8
 * - 8 found @index 4, so reverse elements from 3 to 4
 * - Result [1, 2, 3, 8, 9]
 * 
 * NOTE: This THINKING is only possible when we are sure the all items in both array are same
 * - Then only we can reverse and achieve another
 * 
 * 
 * TIMECOMPLEXITY: O(N)
 */ 
bool solve(vector<int>& nums, vector<int>& target) {
    map<int, int> checker;
    for(int i=0;i<nums.size();i++) {
        checker[nums[i]]++;
    }
    for(int i=0;i<target.size();i++) {
        if(checker.find(target[i])!=checker.end()) {
            checker[target[i]]--;
            if(checker[target[i]]==0){
                checker.erase(target[i]);
            }
        }else {
            return false;
        }
    }
    return checker.empty();    
}
