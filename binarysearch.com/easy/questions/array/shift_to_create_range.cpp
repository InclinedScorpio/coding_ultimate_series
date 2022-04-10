// https://binarysearch.com/problems/Shift-to-Create-Range

bool solve(vector<int>& nums) {
    if(nums.size()==0) return false;

    int maxElement = *max_element(nums.begin(), nums.end());
    bool foundMax=false;
    int i, maxIndex=0;
    for(i=0;i<nums.size();i++) {
        if(nums[i]==maxElement) {
            maxIndex = i;
            break;
        }
    }
    bool increasing;
    if(maxIndex==nums.size()-1) {
        if(nums[0]==1) increasing = true;
        else increasing = false;
    } else {
        if(nums[maxIndex+1]==1) {
            increasing=true;
        } else increasing=false;
    }

    if(increasing) {
        i++;
        int matcher=1;
        for(;i<nums.size();i++) {
            if(nums[i]!=matcher) return false;
            matcher++;
        }

        for(i=0;i<maxIndex;i++) {
            if(nums[i]!=matcher) return false;
            matcher++;
        }
    } else {
        i++;
        int matcher=nums[maxIndex];
        matcher--;
        for(;i<nums.size();i++) {
            if(nums[i]!=matcher) return false;
            matcher--;
        }

        for(i=0;i<maxIndex;i++) {
            if(nums[i]!=matcher) return false;
            matcher--;
        }
    }

    return true;
    
}