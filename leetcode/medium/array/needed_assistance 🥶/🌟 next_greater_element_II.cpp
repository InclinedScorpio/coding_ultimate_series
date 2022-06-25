// https://leetcode.com/problems/next-greater-element-ii/

/**
 * LOGIC: First do next greater element to get better understanding
 * Question is easy itself
 * - We just need to use stack in order to keep track of next greater
 * - As soon as we will get a greater number, we will pop out data from stack till we get a lesser item
 * 
 * - Here we are required CYCLIC Search - hence we can repeat the array
 * - Rather than repeating we can use %N to do the same
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        stack<int> st;
        vector<int> result(nums.size());
        for(int i=(2*N)-1;i>=0;i--) {
            while(!st.empty() && st.top()<=nums[i%N]) st.pop();
            if(!st.empty()) {
                if(i<N) result[i]=st.top();
            } else {
                if(i<N) result[i]=-1;
            }
            st.push(nums[i%N]);
        }
        return result;
    }
};