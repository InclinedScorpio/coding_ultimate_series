// https://binarysearch.com/problems/Rain-Catcher

int solve(vector<int>& nums) {

    vector<int> heighestFromLeft;
    vector<int> heighestFromRight;
    
    int leftHeightTillNow=0;
    int rightHeightTillNow=0;
    // for backward iteration
    int rightIndex = nums.size()-1;

    for(int i=0;i<nums.size();i++) {
        if(nums[i]>leftHeightTillNow) {
            leftHeightTillNow = nums[i];
        }
        if(nums[rightIndex]>rightHeightTillNow) {
            rightHeightTillNow = nums[rightIndex];
        }
        // push max height encountered
        heighestFromLeft.push_back(leftHeightTillNow);
        heighestFromRight.insert(heighestFromRight.begin(), rightHeightTillNow);
        rightIndex--;
    }

    // left right calculated
    int rainDrops=0;
    for(int i=0;i<nums.size();i++) {
        int minHeight = min(heighestFromLeft[i], heighestFromRight[i])-nums[i];
        if(minHeight>0) rainDrops+=minHeight;
    }
    return rainDrops;
}