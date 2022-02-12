// https://binarysearch.com/problems/Making-List-Values-Equal

/**
 * LOGIC: Question is about subset not sublist
 * - You can pick literally any number of index and increment
 * - So basically need to find the smallest no & largest no's difference
 * 
 */ 
int solve(vector<int>& nums) {
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i: nums) {
        if(min>i) {
            min=i;
        }
        if(max<i) {
            max=i;
        }
    }
    return max-min;
}
