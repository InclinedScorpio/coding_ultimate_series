// https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        nextGreater[nums2[nums2.size()-1]]=-1;
        stack<int> greater;
        greater.push(nums2[nums2.size()-1]);
        
        for(int i=nums2.size()-2;i>=0;i--) {
            while(!greater.empty() && greater.top()<nums2[i]) greater.pop();
            
            if(!greater.empty()) nextGreater[nums2[i]]=greater.top();
            else nextGreater[nums2[i]]=-1;
            greater.push(nums2[i]);
        }
        
        vector<int> result(nums1.size());
        for(int i=0;i<nums1.size();i++) result[i] = nextGreater[nums1[i]];
        return result;
    }
};