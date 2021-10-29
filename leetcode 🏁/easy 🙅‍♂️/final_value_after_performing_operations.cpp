// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/submissions/

/**
 * @param {string[]} operations
 * @return {number}
 */
var finalValueAfterOperations = function(operations) {
    let final_value=0;
    for(let i=0;i<operations.length;i++) {
        switch(operations[i]) {
            case "X++":
                final_value++;
                break;
            case "++X": 
                ++final_value;
                break;
            case "--X": 
                --final_value;
                break;
            case "X--":
                final_value--;
                break;
        }
    }
    return final_value;
};

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int final_value=0;
        
        for(int i=0;i<operations.size();i++) {
            if(operations[i]=="--X") {
                --final_value;
            }else if(operations[i]=="X--") {
                final_value--;
            }else if(operations[i]=="X++") {
                final_value++;
            }else if(operations[i]=="++X") {
                ++final_value;
            }
        }
        return final_value;
    }
};