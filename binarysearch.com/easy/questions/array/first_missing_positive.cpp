// https://binarysearch.com/problems/First-Missing-Positive

int solve(vector<int>& nums1) {
    if(nums1.size()==0) return 1;
    if(nums1.size()==1 && nums1[0]==1) return 2;
    else if(nums1.size()==1) return 1;
    set<int> nums;
    for(auto i: nums1) {
        if(i>0) {
            nums.insert(i);
        }
    }
    if(nums.size()==0) return 1;
    auto num=nums.begin();
    int previous = *num;
    if(previous>1) return 1;
    num++;
    for(;num!=nums.end();num++) {
        if(previous+1 != *num) {
            cout<<"in here"<<previous<<" "<<*num;
            break;
        }
        previous = *num;
    }
    if(previous<=0) return 1;
    else return previous+1;
}