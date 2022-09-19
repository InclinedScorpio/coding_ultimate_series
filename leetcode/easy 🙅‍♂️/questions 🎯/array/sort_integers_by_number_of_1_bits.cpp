// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

/**
 * LOGIC: Imp to note how to use comparator
 * - Make use of sorting whenever required, go to optimization at last!
 */
bool comparator(pair<int, int> a, pair<int, int> b) {
    if(b.second==a.second) return a.first<=b.first;
    return a.second<=b.second;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> store;
        for(int i=0;i<arr.size();i++) {
            int currNum = arr[i];
            int totalOnes=0;
            while(currNum>0) {
                if(currNum%2!=0) totalOnes++;
                currNum/=2;
            }
            store.push_back({arr[i], totalOnes});
        }
        
        sort(store.begin(), store.end(), comparator);
        vector<int> result;
        for(pair<int, int> s: store) {
            result.push_back(s.first);
        }
        return result;
    }
};