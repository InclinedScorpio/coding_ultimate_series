// https://leetcode.com/problems/implement-trie-prefix-tree/

/**
 * LOGIC: Must understand these things
 * - 1) We need a class to implement the node
 * - 2) TrieNode* val[123] -> array pointing to complete different array (important)
 * - 3) TrieNode* val[123] = {}; use {} else error is thrown
 * - 4) node pointed as the end is the next node basically (why? - because it's the exact character which is last)
 * ⭐️ > previously I had marked the complete node with array[123] as the last and not the character inside it as the last due to which some test cases failed
 * 
 */ 
class TrieNode {
    public:
    TrieNode() {
        memset(val, NULL, 123);
    }
    TrieNode* val[123] = {};
    bool isTheEnd = false;
};

class Trie {
    TrieNode* root;
    
    public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        for(int i=0;i<word.length();i++) {
            if(!current->val[word[i]]) {
                current->val[word[i]] = new TrieNode();
            }
            current = current->val[word[i]];
        }
        current->isTheEnd=true;
    }
    
    bool search(string word, bool startsWith=false) {
        TrieNode* current = root;
        for(int i=0;i<word.length();i++) {
            if(!current->val[word[i]]) return false;
            current = current->val[word[i]];
        }
        if(!startsWith && !current->isTheEnd) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */