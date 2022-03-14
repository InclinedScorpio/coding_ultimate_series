// https://binarysearch.com/problems/K-Longest-Show-Durations

int solve(vector<string>& shows, vector<int>& durations, int k) {
    map<string, int> store;
    for(int i=0;i<shows.size();i++) {
        if(store.find(shows[i])!=store.end()) {
            store[shows[i]] += durations[i];
        } else {
            store[shows[i]] = durations[i];
        }
    }

    vector<int> duration;
    for(auto item: store) {
        duration.push_back(item.second);
    }
    sort(duration.rbegin(), duration.rend());
    int sum=0;
    for(int i=0;i<k;i++) {
        sum+=duration[i];
    }
    return sum;
}