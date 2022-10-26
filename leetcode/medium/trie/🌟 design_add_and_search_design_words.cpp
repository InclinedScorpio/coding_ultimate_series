// https://leetcode.com/problems/design-add-and-search-words-data-structure/

/**
 * LOGIC: Trie basic problem
 * - Recursive approach is taken for searching with items with '.'
 * - Make sure to limit memory to 27 or else Memory Limit will Exceed
 *
 */
class Trie {
  public:
    Trie() {
        memset(myTrie, NULL, 27);
        isEnded=false;
    }
    Trie* myTrie[27]={};
    bool isEnded;
};

class WordDictionary {
public:
    Trie* rootTrie;
    WordDictionary() {
        rootTrie = new Trie();
    }
    
    void addWord(string word) {
        Trie* iterTrie = rootTrie;
        for(int i=0;i<word.length();i++) {
            if(iterTrie->myTrie[word[i] - 'a']) {
                iterTrie = iterTrie->myTrie[word[i] - 'a'];
            } else { // it's null
                iterTrie->myTrie[word[i] - 'a'] = new Trie();
                iterTrie = iterTrie->myTrie[word[i] - 'a'];
            }
        }
        iterTrie->isEnded = true;
    }
    
    bool searchTrie(string& word, int ind, Trie* trie) {
        if(ind>=word.size() && (trie && !trie->isEnded)) return false;
        if(ind>=word.size()) return true;
        if(!trie) return false;
        for(int i=ind;i<word.length();i++) {
            if(word[i]!='.' && !trie->myTrie[word[i] - 'a']) return false;
            if(word[i]=='.') {
                for(int j=97;j<=122;j++) {
                    if(trie->myTrie[j - 'a'])
                        if(searchTrie(word, i+1, trie->myTrie[j - 'a'])) return true;
                }
                return false;
            } else trie = trie->myTrie[word[i] - 'a'];
        }
        if(trie->isEnded) return true;
        return false;
    }
    
    bool search(string word) {
        Trie* iterTrie = rootTrie;
        return searchTrie(word, 0, iterTrie);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */