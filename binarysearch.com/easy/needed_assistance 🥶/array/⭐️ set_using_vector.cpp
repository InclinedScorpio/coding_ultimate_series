// https://binarysearch.com/problems/Set

/**
 * LOGIC:
 * - lower_bound(vec.begin(), vec.end(), value) - returns the first addr of index where val is >= value
 * - binary_search(vec.begin(), vec.end(), value) - returns boolean based on search result
 * - vec.insert(indexAddr, value) - insert value at addr 
 * 
 */ 
class CustomSet {
    public:

    vector<int> vec;
    CustomSet() {
    }

    void add(int val) {
        if(binary_search(vec.begin(), vec.end(), val)) {
            return;
        }
            vector<int>:: iterator itr = lower_bound(vec.begin(), vec.end(), val);
            vec.insert(itr, val);
    }

    bool exists(int val) {
        return binary_search(vec.begin(), vec.end(), val);
    }

    void remove(int val) {
        if(!binary_search(vec.begin(), vec.end(), val)) {
            return;
        }
        auto itr = lower_bound(vec.begin(), vec.end(), val);
        if(itr!=vec.end()) vec.erase(itr);
    }
};
