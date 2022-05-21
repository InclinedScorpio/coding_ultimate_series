/**
 * LRU Cache: Least Recently used Cache 
 * 
 * - Here we remove least recently used data
 * - Cache is limited in size
 * - So for data least recently used we remove it
 * 
 * - If data is asked for, we shift it to top
 * - If more data comes, last one in the list gets removed
 * 
 * LOGIC: We used linked list (list in cpp) + Hashing
 * - Hashing is used to carry the key and node address
 * - So that operations can be done in O(1)
 * 
 */ 

#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

class Node {
    public:
        string name;
        int value;
        Node(string name, int value) {
            this->name = name;
            this->value = value;
        }
};

class LRUCache {
    private:
        int size;
        unordered_map<string, Node*> cache;
        list<Node*> list;
    
    public:
        LRUCache(int size) {
            this->size = size;
        }
    
        void insert(string key, int value) {
            if(cache.count(key)) {
                auto existingNode = cache[key];
                existingNode->value = value;
            } else {
                Node* newNode = new Node(key, value);
                // check if cache is full
                if(cache.size()==size) {
                    cache.erase(list.back()->name);
                    list.pop_back();
                }
                list.push_front(newNode);
                cache[key] = newNode;
            }            
        }

        int get(string name) {
            if(!cache.count(name)) {
                return -1;
            }
            // available
            Node* it = cache[name];
            Node* temp = new Node(it->name, it->value);
            list.push_front(temp);
            list.remove(it);
            return temp->value;
        }

        int mostRecentlyUsed() {
            if(list.empty()) {
                cout<<"No data present"<<endl;
                return -1;
            }
            return (*list.begin())->value;
        }
};

int main() {
    LRUCache myLRU(3);

    while(true) {
        cout<<endl<<"Enter 1 (insertion), 2(getting), 3(top Item fetch): ";
        int input;
        cin>>input;
        string myStr; 
        int value;
        switch(input) {
            case 1:
                cout<<endl<<"Enter string to enter cache: ";
                cin>>myStr;
                cout<<endl<<"Enter it's value:";
                cin>>value;
                myLRU.insert(myStr, value);
                break;
            case 2:
                cout<<"Enter string for which value required: ";
                cin>>myStr;
                cout<<myLRU.get(myStr);
                break;
            case 3:
                cout<<endl<<"Top item present is: "<<myLRU.mostRecentlyUsed();
                break;
            default:
                cout<<endl<<"Wrong input, Exiting...";
                return 0;
        }
    }
}