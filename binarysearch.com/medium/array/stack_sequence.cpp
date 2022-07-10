// https://binarysearch.com/problems/Stack-Sequence

/**
 * LOGIC: Basic use of stack
 * 
 */ 
bool solve(vector<int>& pushes, vector<int>& pops) {
    if(pushes.size()!=pops.size()) return false;
    stack<int> store;
    int ind = 0;
    for(int i=0;i<pushes.size();i++) {
        store.push(pushes[i]);
        if(store.top()==pops[ind]) {
            while(store.size()) {
                if(store.top()==pops[ind]) {
                    store.pop();
                    ind++;
                } else {
                    if(i==pushes.size()-1) return false;
                    break;
                }
            }
        }
    }
    if(store.size()) return false;
    return true;    
}