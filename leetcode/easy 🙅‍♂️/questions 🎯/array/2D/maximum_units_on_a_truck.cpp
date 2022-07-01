// https://leetcode.com/problems/maximum-units-on-a-truck/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int, int>> store;
        for(int i=0;i<boxTypes.size();i++) {
            store.push_back({boxTypes[i][1], boxTypes[i][0]});
        }
        sort(store.begin(), store.end(), greater<pair<int, int>>());
        int totalUnits=0;
        int totalBoxes=0;
        for(int i=0;i<store.size();i++) {
            int unitsInIndex = store[i].first * store[i].second;
            
            if(totalBoxes+store[i].second<=truckSize) {
                totalUnits+=unitsInIndex;
                totalBoxes+=store[i].second;
            } else {
                totalUnits += ((truckSize-totalBoxes)*store[i].first);
                return totalUnits;
            }
        }
        return totalUnits;
    }
};