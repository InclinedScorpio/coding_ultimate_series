// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1/#

/**
 * LOGIC: We need to understand that solutions range is limited
 * - It's min value to max value given in the matrix
 * 
 * - Hence, the question is a variant of Monotonic binary search!
 * - Extremely important to understand that- we don't care even if some num doesn't exists
 * - Why? because our BS will take care of that - as when will try to shift left(towards requiredNumsOnLeft) will get the existing number
 * - The above 👉 LINE IS THE CRUX WHY PEOPLE DON'T UNDERSTAND THIS QUESTIONS!"
 * - LOGIC: (of this question) We can easily count the nums to the left of the number (& hence we can reach medium like this)
 * 
 * - Through scratch, we can understand that left will be the one which will point to the result at last (as right will go towards left of left)
 * 
 * COMPLEXITY: O(rows * logM)
 * 
 */ 
class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int minValue=INT_MAX, maxValue=INT_MIN;
        for(int i=0;i<r;i++) {
            if(matrix[i][0]<minValue) minValue = matrix[i][0];
            if(matrix[i][c-1]>maxValue) maxValue = matrix[i][c-1];
        }
        
        int left = minValue, right = maxValue;
        while(left<=right) {
            int mid = left + (right-left)/2;
            int requiredCount = (r*c-1)/2;
            int currCount=0;
            for(int i=0;i<r;i++) {
                currCount+=upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(currCount>requiredCount) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};