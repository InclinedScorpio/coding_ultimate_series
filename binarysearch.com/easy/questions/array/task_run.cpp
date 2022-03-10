// https://binarysearch.com/problems/Task-Run

int solve(vector<int>& tasks, int k) {
    int currTime=0;
    map<int, int> store;
    for(int i=0;i<tasks.size();i++) {
        if(store.find(tasks[i])!=store.end()) {
            int timeDiff = currTime - store[tasks[i]];
            if(timeDiff<=k) {
                currTime+=(k-timeDiff + 1);
                store[tasks[i]] = currTime;
            } else store[tasks[i]] = currTime;
        } else store[tasks[i]] = currTime;
        currTime++;
    }
    return currTime;
}
