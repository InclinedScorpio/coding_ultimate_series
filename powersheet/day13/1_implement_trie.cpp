// https://leetcode.com/problems/implement-trie-prefix-tree/

class Node {

public:
    char c;
    unordered_map<char, Node*> mapper;
    bool isEnd;

    Node(char c) {
        this->c = c;
        this->isEnd=false;
    }
};

class Trie {
private:
    Node* head;
    char starter='/';

public:
    Trie() {
        head = new Node(starter);
    }
    
    void insert(string word) {
        Node* nextOne=NULL;
        for(int i=0;i<word.size();i++) {
            if(!nextOne) {
                if(head->mapper.find(word[0])==head->mapper.end()) {
                    head->mapper[word[0]] = new Node(word[0]);
                    nextOne = head->mapper[word[0]];
                } else {
                    nextOne = head->mapper[word[0]];
                }
            } else {
                if(nextOne->mapper.find(word[i])==nextOne->mapper.end()) {
                    nextOne->mapper[word[i]] = new Node(word[i]);
                    nextOne = nextOne->mapper[word[i]];
                } else {
                    nextOne = nextOne->mapper[word[i]]; 
                }
            }
        }
        nextOne->isEnd=true;
    }
    
    bool search(string word, bool isPrefix=false) {
        Node* nextOne=NULL;

        for(int i=0;i<word.size();i++) {
            if(!nextOne) {
                if(head->mapper.find(word[0])==head->mapper.end()) return false;
                nextOne=head->mapper[word[0]];
            } else {
                if(nextOne->mapper.find(word[i])==nextOne->mapper.end()) return false;
                nextOne = nextOne->mapper[word[i]];
            }
        }
        
        if(isPrefix) return true;
        return nextOne->isEnd;
        
    }
    
    bool startsWith(string prefix) {
        return this->search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */