class Solution {
public:

    bool isTaken(unordered_set<int>& taken, int& ptr) {
        if(taken.find(ptr)!=taken.end()) {
            return true;
        }
        return false;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        unordered_set<int> taken;
        
        int ptr=0;

        while(ptr<strs.size()) {
            if(this->isTaken(taken, ptr)){
                ptr++;
                continue;
            }
            taken.insert(ptr);
            string currStr=strs[ptr];
            // create map
            vector<int> store(26, 0);
            for(int c: currStr) {
                store[c-97]++;
            }
            vector<string> newly={currStr};

            for(int i=ptr+1;i<strs.size();i++) {
                if(this->isTaken(taken, i)){
                    continue;
                }
                string compStr=strs[i];
                vector<int> compareStore(26,0);
                for(int c: compStr) {
                    compareStore[c-97]++;
                }
                if(store==compareStore) {
                    taken.insert(i);
                    newly.push_back(compStr);
                }
            }
            output.push_back(newly);
        }

        return output;
    }
};

// ["eat","tea","tan","ate","nat","bat"]

// e - 1
// a - 1
// t - 1
