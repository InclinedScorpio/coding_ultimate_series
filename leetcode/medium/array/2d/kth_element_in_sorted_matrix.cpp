// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

/**
 * LOGIC: Basic use of vector
 * - Needs improvement as space can be brought to O(1) 
 * 
 */
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> store;
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[i].size();j++) {
                store.push_back(matrix[i][j]);
            }
        }
        sort(store.begin(), store.end());
        return store[k-1];
    }
};