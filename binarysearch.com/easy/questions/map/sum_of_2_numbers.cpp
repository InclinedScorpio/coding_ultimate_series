// https://binarysearch.com/problems/Sum-of-Two-Numbers-Online-Version

/**
 * LOGIC: Iterate over map and check for alternative number
 */ 
class TwoSum {
    public:
    unordered_map<int,int> checker;
    TwoSum() {

    }

    void add(int val) {
        checker[val]++;
    }

    bool find(int val) {
        for(auto f: checker) {
            int toFind = val - f.first;
            if(f.first==toFind) {
                if(checker.find(toFind)!=checker.end() && checker[toFind]==2) {
                    return true;
                }
                return false;
            }

            if(checker.find(toFind)!=checker.end()) {
                return true;
            }
        }
        return false;
        
    }
};