// https://leetcode.com/problems/reorder-data-in-log-files/

/**
 * LOGIC: AMAZON MOST ASKED
 * - Logic is basic, question must be clear.
 * - understand question in scratch before starting
 * 
 */ 
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<string> letter;
        vector<string> digit;
        
        vector<pair<pair<string, string>, int>> stringPair;
        
        for(int i=0;i<logs.size();i++) {
            string str="";
            bool isDigit=false;
            int j=0, jSave=0;
            bool seenSpace=false;
            for(;j<logs[i].length();j++) {
                if(!seenSpace && logs[i][j]==' ') {
                    jSave=j;
                    seenSpace=true;   
                }
                if(seenSpace && logs[i][j]>='0' and logs[i][j]<='9') {
                    isDigit=true;
                    break;
                }
            }
            if(isDigit)
                digit.push_back(logs[i]);
            else
                stringPair.push_back({{logs[i].substr(jSave),logs[i].substr(0, jSave)}, i});
        }
        
        sort(stringPair.begin(), stringPair.end());
        
        for(pair<pair<string, string>, int> sP: stringPair)
            letter.push_back(logs[sP.second]);
            
        for(int i=0;i<digit.size();i++)
            letter.push_back(digit[i]);
        
        return letter;
    }
};