// https://binarysearch.com/problems/Consecutive-Ones

bool solve(vector<int>& nums) {
    bool isOneStarted=false;
    bool isOneEnded=false;
    for(int i=0;i<nums.size();i++) {
        if(!isOneStarted && nums[i]==1) {
            isOneStarted=true; continue;
        }
        if(!isOneEnded && isOneStarted && nums[i]!=1)  {
            isOneEnded=true;continue;
        }
        if(isOneEnded && nums[i]==1) return false;
    }
    return true;
}