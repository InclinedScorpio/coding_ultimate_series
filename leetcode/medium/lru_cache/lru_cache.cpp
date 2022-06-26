// https://leetcode.com/problems/lru-cache/


/**
 * LOGIC: As we require O(1) operations and required nums are first, last and anyone in middle
 * - We should use doubly linked list along with hash map for this
 * 
 * COMPLEXITY: O(1)
 * 
 */ 
class Node {
    public:
    int key, value;
    Node* next;
    Node* prev;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> store;
    int capacity;
    Node* head;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = NULL;
    }
    
    int get(int key) {
        if(store.count(key)==0)  {
            return -1;
        };
        Node* node = store[key];
        int toReturn = node->value;
        
        
        // shift node to front
        shiftNodeToFront(key);
        return toReturn;
    }
    
    void insertNodeAtHead(Node* node) {
        if(!head) { // head doesn't exists
            head = node;
            node->next = head;
            node->prev = head;
            store[node->key] = node;
            return;
        }
        node->next = head;
        node->prev = head->prev;
        Node* headPrev = head->prev;
        head->prev = node;
        headPrev->next = node; // join last to new node
        head = node;
        store[node->key] = node;
    }
    
    void deleteNode(int key) {
        Node* deleteNode = store[key];
        Node* node = deleteNode->prev;
        node->next = deleteNode->next;
        node->next->prev = node;
        store.erase(key);
    }
    
    void deleteLastNode() {
        if(store.size()==1) {
            store.erase(head->key);
            head = NULL;
        } else {
            Node* iter = head->prev->prev;
            store.erase(iter->next->key);
            iter->next = iter->next->next;
            iter->next->prev = iter;
        }
    }
    
    void shiftNodeToFront(int key) {
        Node* node = store[key];
        if(node==head) return;
        deleteNode(key);
        insertNodeAtHead(node);
    }
    
    void put(int key, int value) {
        if(store.count(key)) { // already present
            Node* node = store[key];
            node->value = value;
            shiftNodeToFront(key);
            return;
        }
        if(store.size()==capacity) {
            deleteLastNode();
        }
        // key doesn't exists
        Node* node = new Node(key, value);
        insertNodeAtHead(node);
    }
    
    // void print() {
    //     Node* saveHead = head;
    //     if(!saveHead) {
    //         cout<<" Nothing to print!!";
    //         return;
    //     }
    //     cout<<"** printing list **"<<endl;
    //     cout<<saveHead->key;
    //     saveHead = saveHead->next;
    //     while(saveHead && saveHead!=head) {
    //         cout<<saveHead->key<<" ";
    //         saveHead = saveHead->next;
    //     }
    //     cout<<endl<<" --printed--"<<endl;
    // }
};