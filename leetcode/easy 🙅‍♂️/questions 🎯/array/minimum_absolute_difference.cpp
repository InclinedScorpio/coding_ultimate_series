// https://leetcode.com/problems/minimum-absolute-difference/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int currMin = INT_MAX;
        for(int i=1;i<arr.size();i++) {
            currMin=min(currMin, abs(arr[i]-arr[i-1]));
        }
        
        for(int i=1;i<arr.size();i++) {
            if(currMin==(arr[i]-arr[i-1])) {
                vector<int> temp = {arr[i-1], arr[i]};
                result.push_back(temp);
            }
        }
        return result;
    }
};