// https://binarysearch.com/problems/Greatest-Common-Divisor

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
