// https://binarysearch.com/problems/Unique-Occurrences

/**
 * LOGIC: Basic
 * - Use map to store occurances
 * - Shift all occurances to set
 * - Now compare map and set's size
 * - If different means any one of them was same
 * 
 * COMPLEXITY: O(NlogN)
 * 
 */ 
bool solve(vector<int>& nums) {
    map<int, int> occurance;
    for(int i=0;i<nums.size();i++) {
        occurance[nums[i]]++;
    }
    set<int> storeOccurance;
    for(auto oc: occurance) {
        storeOccurance.insert(oc.second);
    }
    if(occurance.size()==storeOccurance.size()) return true;
    return false;
}