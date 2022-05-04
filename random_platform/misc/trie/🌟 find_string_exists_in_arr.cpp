/***
 * QUESTION: Find if string exists in the array
 * 
 * LOGIC: 
 * 1) Using unordered_set we can find easily
 * 2) Using Trie Data Structure We can find
 * 
 * 2) Trie
 * - Trie is basically tree with many children
 * - Children are shown as a unordered_map which contains address of children 
 * - Here we can store the string character by ch from top to bottom
 * - This will help us to store any new string in O(N) - N is size of string 
 * - Also while searching we just have to go from top to bottom - O(N) - N is size of string
 * 
 * NOTE: Let's say we have both "apple" and "app"
 * - Now going from top to bottom we will find app but it's not the end, so we need to have some flag
 * - so we have used isTerminating flag to mention that any particular node if that substring also exists
 * 
 * - First string can be mentioned as '\0' so that initial ch can be stored in unordered_map of it
 * 
 * 
 * COMPLEXITY: Searching string exists in array - O(N)
 * Forming the Trie will take time and size - O(A + B + C ....) - sum of size of all strings
 * 
 */ 

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Node {
    public:
        int data;
        unordered_map<char, Node*> store;
        bool isTerminating;
        Node(int data) {
            this->data = data;
            this->isTerminating = false;
        }
};

class Trie {
    public:
        Node* node;
        Trie() {
            this->node= new Node('\0');
        }
        
        void insert(string str) {
            Node* node = this->node;
            int ind=0;
            while(ind<str.length() && node->store.count(str[ind])) {
                node = node->store[str[ind]];
                ind++;
            }
            while(ind<str.length()) {
                Node* newNode = new Node(str[ind]);
                node->store[str[ind]]=newNode;
                node = newNode;
                ind++;
            }
            node->isTerminating=true;
        }

        bool search(string str) {
            Node* node = this->node;
            int ind = 0;
            while(ind<str.length() && node->store.count(str[ind])) {
                node = node->store[str[ind]];
                ind++;
            }
            if(ind!=str.length() || !node->isTerminating) {
                return false;
            }
            return true;
        }
};

int main() {
    Trie t;
    vector<string> str = {"apple", "ape", "no", "news", "not", "never"};
    for(string& s: str) {
        t.insert(s);
    }
    string search;
    cin>>search;
    cout<<t.search(search);
}