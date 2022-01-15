// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1) {
            return { {1} };
        }
        
        vector<vector<int>> pasTri{ {1}, {1,1} };
        if(numRows==2) {
            return pasTri;
        }
        
        int lastPasTriIndex = 1;
		
		//a formal loop to loop through the numbers
        while(numRows-3 >=0) {
		    // take lastIndex so that we can calculate nth + (nth+1) - that's what pascal is
            vector<int> curr = pasTri[lastPasTriIndex];
            int ithPasTriIndex = curr.size();
			
			// push changes in this vector
            vector<int> newRow;
            
			// we will need 1 at front and back so manually doing it
            newRow.push_back(1);
			// iterate and do n + (n+1) and each new row will be created
            for(int i=0;i<ithPasTriIndex-1;i++) {
                newRow.push_back(curr[i]+curr[i+1]);
            }
            newRow.push_back(1);
            
			// new row is created so now push it
            pasTri.push_back(newRow);
			
			// increment and decrement required variables
            lastPasTriIndex++;
            numRows--;
        }
        return pasTri;
    }
};
