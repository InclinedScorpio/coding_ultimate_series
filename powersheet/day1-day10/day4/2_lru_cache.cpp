// https://leetcode.com/problems/lru-cache/description/

class Node {


public:
    // Node(int val, Node* next=NULL, Node* prev=NULL) {
    //     this->val;
    //     this->next = next;
    //     this->prev = prev;
    // }
    Node* next;
    Node* prev;
    int val;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


class LRUCache {
private:
    int capacity, current;
    Node* head;

    map<int, pair<int, Node*>> store;

    void shiftToFront(Node* curr) {
        if(curr==head) return; // already present

        Node* currPrev = curr->prev;
        Node* currNext = curr->next;

        currPrev->next = currNext;
        currNext->prev = currPrev;

        curr->next = head;
        curr->prev = head->prev;
        head->prev->next = curr;
        head->prev=curr;
        head = curr;
    }

    void removeLRU() {
        if(current==0) return;
        if(current==1) {
            store.erase(head->val);
            this->head=NULL;
            --current;
            return;
        }
        int toRemove = head->prev->val;
        Node* savePrev = head->prev->prev;
        head->prev->prev->next = head;
        head->prev = head->prev->prev;
        this->store.erase(toRemove);
        --current;
    }

    void addNewItem(int key, int val) {
        if(capacity==current) this->removeLRU();
        Node* newNode = new Node(key);
        newNode->next = newNode;
        newNode->prev = newNode;
        if(!head) {
            head = newNode;
            ++current;
            store[key] = {val, head};
            return;
        }
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
        store[key] = {val, head};
        ++current;
    }

    void updateVal(int key, int val) {
        if(store.find(key)==store.end()) {
            addNewItem(key, val);
            return;
        }
        pair<int, Node*> s = store[key];
        store[key] = {val, s.second};
        shiftToFront(s.second);
    }

    int getVal(int key) {
        if(store.find(key)==store.end()) return -1;
        this->updateVal(key, store[key].first);
        return store[key].first;
    }

public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        this->current=0;
        head=NULL;
    }
    
    int get(int key) {
        return this->getVal(key);
    }
    
    void put(int key, int value) {
        this->updateVal(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */