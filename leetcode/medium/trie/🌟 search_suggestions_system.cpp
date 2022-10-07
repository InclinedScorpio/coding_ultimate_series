// https://leetcode.com/problems/search-suggestions-system/

/**
 * LOGIC: Basic Trie Problem! Must be done before to do it timely :)
 * 
 */ 
class Trie {
    public: 
        Trie() {
            memset(trie, NULL, 127);
        }
        Trie* trie[127] = {};
        vector<string> store;
};

class Solution {
public:
    void insertIntoTrie(string str, Trie* paramCurrent) {
        Trie* current = paramCurrent;
        for(char i: str) {
            if(!current->trie[i]) {
                current->trie[i] = new Trie();
            }
            current = current->trie[i];
            current->store.push_back(str);
        }
    }
    
    vector<string> search(string str, Trie* paramCurrent) {
        Trie* current = paramCurrent;
        for(char c: str) {
            if(current->trie[c]) {
                current = current->trie[c];
            } else {
                return {};
            }
        }
        return current->store;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* myTrie = new Trie(); // base trie
        sort(products.begin(), products.end());
        for(string str: products) {
            insertIntoTrie(str, myTrie);
        }
        // check
        string str="";
        vector<vector<string>> result;
        for(char i: searchWord) {
            str+=i;
            vector<string> res = search(str, myTrie);
            int ind=0;
            vector<string> temp;
            while(ind<3 && ind<res.size()) {
                temp.push_back(res[ind]);
                ind++;
            }
            result.push_back(temp);
        }
        return result;
    }
};