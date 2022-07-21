// https://binarysearch.com/problems/Longest-Common-Substring

/**
 * LOGIC: Simple 2d array required, can be judged through scratch!
 * 
 * COMPLEXITY: O(N^2)
 *  
 */ 
int solve(string s0, string s1) {
    vector<vector<int>> store(s0.length()+1, vector<int>(s1.length()+1, 0));
    int maxValue = INT_MIN;

    for(int ind=1;ind<=s0.length();ind++) {
        for(int jnd=1;jnd<=s1.length();jnd++) {
            int i=ind-1, j=jnd-1;
            if(s0[i]==s1[j]) {
                store[ind][jnd] = max(store[ind-1][jnd], store[ind-1][jnd-1]+1);
                maxValue = max(maxValue, store[ind][jnd]);
            }
        }
    }
    return maxValue==INT_MIN?0:maxValue;
}