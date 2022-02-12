// https://binarysearch.com/problems/Reverse-Sublists-to-Convert-to-Target

bool solve(vector<int>& nums, vector<int>& target) {
    map<int, int> checker;
    for(int i=0;i<nums.size();i++) {
        checker[nums[i]]++;
    }
    for(int i=0;i<target.size();i++) {
        if(checker.find(target[i])!=checker.end()) {
            checker[target[i]]--;
            if(checker[target[i]]==0){
                checker.erase(target[i]);
            }
        }else {
            return false;
        }
    }
    return checker.empty();    
}
