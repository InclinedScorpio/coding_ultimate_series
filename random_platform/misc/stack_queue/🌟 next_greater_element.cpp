// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#

/**
 * QUESTION: Find the next greater on right side
 * 
 * LOGIC: Think of each item as a pole and a pole can see only greater pole at right
 * - First greater pole must be entered.
 * 
 * So, the questions is basically is asking to traverse from last
 * - Keeping the heights in stack
 * - If stack is empty, greater doesn't exists - hence "-1"
 * - If there are items in stack:
 * 1) If top item is greater, means that's the latest greater
 * - print it and push the current height in stack! Why?
 * - because, we need to keep the heights for next pole coming up in left
 * 2) If top item is smaller? That means current is bigger and top of stack can be thrown away!
 * - Why thrown away? Because from further left, current will be visible first, rather than stack's top one
 * - Hence we will keep removing the top ones till we get the height which is bigger
 * - Once we get it, print it and push the current to the stack
 * 
 * ** Why to use stack here is the main logic! (and to keep item from right to left!)
 * 
 * COMPLEXITY: O(N) 
 */
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> heights;
        vector<long long> result(n, 0);
        
        for(long long i=n-1;i>=0;i--) {
            if(heights.empty()) {
                result[i]=-1;
                heights.push(arr[i]);
                continue;
            }
            while(!heights.empty() && heights.top()<arr[i]) {
                heights.pop();
            }
            if(heights.empty()) {
                result[i]=-1;
                heights.push(arr[i]);
                continue;
            }
            // heights non empty
            result[i] = heights.top();
            heights.push(arr[i]);
        }
        return result;
    }
};