// https://binarysearch.com/problems/Range-Query-on-a-List

/**
 * LOGIC: Use Prefix Sum! to reduce the time complexity significantly
 * TIMECOMPLEXITY: O(N)
 * 
 */ 
class RangeSum {
    public:
    vector<int> prefix;
    RangeSum(vector<int>& nums){
        int sum=0;
        for(int num: nums) {
            sum = sum + num;
            prefix.push_back(sum);
        }
    }

    int total(int i, int j) {
        if(i==0) return prefix[j-1];
        else return prefix[j-1] - prefix[i-1];
    }
};
