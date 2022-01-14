

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) {
            return {1};
        }
        if(rowIndex==1) {
            return {1,1};
        }
        vector<vector<int>> pasTri{ {1}, {1,1} };
        
        int lastPasTriIndex=1;
        vector<int> returnBack;
        while((rowIndex-2)>=0) {
            vector<int> ithPasTri = pasTri[lastPasTriIndex++]; 
            vector<int> newRow;
            
            newRow.push_back(1);
            for(int i=0;i<ithPasTri.size()-1;i++) {
                newRow.push_back(ithPasTri[i] + ithPasTri[i+1]);
            }
            newRow.push_back(1);
            pasTri.push_back(newRow);
            returnBack = newRow;
            rowIndex--;
        }
        return returnBack;
    }
};