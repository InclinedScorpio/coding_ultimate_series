// https://binarysearch.com/problems/Greatest-Common-Divisor

/**
 * LOGIC: Use __gcd(a, b) - to find gcd of 2 items
 * 
 */ 
int solve(vector<int>& nums) {
    int num = nums[0];
    for(int i=1;i<nums.size();i++) num = __gcd(num, nums[i]);
    return num;
}

/**
 * LOGIC: Without using __gcd method
 * 
 */ 
int solve(vector<int>& nums) {
    if(nums.size()==1) {
        return nums[0];
    }
    int minValue=INT_MAX;
    bool divByTwo=true;
    for(int i=0;i<nums.size();i++) {
        if(nums[i]%2!=0) {
            divByTwo = false;
        }
        if(minValue>nums[i]) {
            minValue = nums[i];
        }
    }
    int result=1;
    for(int divBy=2;divBy<=minValue;divBy++) {
        bool divByAll = true;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]%divBy) {
                divByAll = false;
                break;
            }
        }
            if(divByAll) {
                result =  divBy;
            }
    }
    return result;    
}
