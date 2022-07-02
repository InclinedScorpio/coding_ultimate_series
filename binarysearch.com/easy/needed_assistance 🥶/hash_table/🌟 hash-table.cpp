// https://binarysearch.com/problems/Hash-Table

/**
 * LOGIC: To create hash table -> use vector and key as index
 * - Now as we take vector size limited, keys can result in collision
 * - Hence at each index we form a linked list (here a vector)
 * 
 * ⭐️ MAKE SURE:
 * - Hash function is optimised , here 900 gave the most optimized answer for me
 * 
 * 
 * AMOTIZEDCOMPLEXITY: O(1)
 * COMLEXITY: O(N)
 * 
 */ 
class HashTable {
    public:
    vector<vector<pair<int, int>>> store;

    HashTable() {
        store = vector<vector<pair<int, int>>>(900);    
    }

    void put(int key, int val) {
        int ind = key%900;
        for(int i=0;i<store[ind].size();i++) {
            if(store[ind][i].first==key) {
                store[ind][i].second = val; return;
            }
        }
        store[ind].push_back({key, val});
    }

    int get(int key) {
        int ind = key%900;
        for(int i=0;i<store[ind].size();i++) {
            if(store[ind][i].first==key) return store[ind][i].second;
        }
        return -1;
    }

    void remove(int key) {
        int ind = key%900;
        for(int i=0;i<store[ind].size();i++) {
            if(store[ind][i].first==key) store[ind].erase(store[ind].begin()+i);
        }
        return;
    }
};