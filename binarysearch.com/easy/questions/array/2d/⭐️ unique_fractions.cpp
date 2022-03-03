// https://binarysearch.com/problems/Unique-Fractions

/**
 * LOGIC: understanding vector<pair<float, vector<int>>> store;
 * sort() will sort the vector based on first item in pair(float value)
 * 
 * 
 */ 
vector<vector<int>> solve(vector<vector<int>>& fractions) {

    vector<pair<float, vector<int>>> store;
    vector<vector<int>> result;
    set<float> checker;

    for(int i=0;i<fractions.size();i++) {
        int first = fractions[i][0];
        int second = fractions[i][1];

        while(first%2==0 && second%2==0) {
            first = first/2;
            second = second/2;
        }

        int index=0;
        int minBtwFirstAndSecond = min(abs(first), abs(second));
        for(int i=3;i<=minBtwFirstAndSecond;i=i+2) {
            while(first%i==0 && second%i==0) {
            first = first/i;
            second = second/i;
            }
        }
        float divisionResult = (float)first/second;
        if(divisionResult<0) {
            second = abs(second);
            first = -1 * abs(first);
        }
        if(checker.find(divisionResult)==checker.end()) store.push_back({divisionResult, {first, second}});
        checker.insert(divisionResult);
    }

    sort(store.begin(), store.end());

    for(int i=0;i<store.size();i++) {
        cout<<store[i].first<<" ";
        result.push_back({store[i].second[0], store[i].second[1]});
    }
    return result;
}