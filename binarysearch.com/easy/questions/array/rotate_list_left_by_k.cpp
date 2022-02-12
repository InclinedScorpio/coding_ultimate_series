// https://binarysearch.com/problems/Rotate-List-Left-by-K

vector<int> solve(vector<int>& nums, int k) {
    vector<int> partialVec;
    for(int i=0;i<k;i++) {
        partialVec.push_back(nums[i]);
    }
    int index=0;
    for(int i=k;i<nums.size();i++) {
        swap(nums[index++], nums[i]);
    }
    index=0;
    for(int i=nums.size()-k;i<nums.size();i++) {
        nums[i]=partialVec[index++];
    }
    return nums;
}
