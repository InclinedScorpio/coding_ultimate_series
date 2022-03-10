// https://binarysearch.com/problems/Special-Product-List

/**
 * LOGIC: Use 2 arrays to store multiples from left and from right
 * - Now at any given index, we can find all multiples excluding i, how?
 * - Just do leftArray[i-1] * rightArray[i+1]
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
vector<int> solve(vector<int>& nums) {

    vector<int> left(nums.size());
    vector<int> right(nums.size());
    vector<int> result(nums.size());
    
    int multi=1;
    int lastMulti=1;
    int lastIndex=nums.size()-1;
    for(int i=0;i<nums.size();i++) {
        lastMulti=lastMulti*nums[lastIndex];
        right[lastIndex] = lastMulti; lastIndex--;
        multi=multi*nums[i];
        left[i]=multi;
    }
    result[0]=right[1];
    for(int i=1;i<nums.size()-1;i++) {
        result[i] = left[i-1] * right[i+1];
    }
    result[nums.size()-1] = left[nums.size()-2];
    return result;
}
