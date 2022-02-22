// https://binarysearch.com/problems/Unix-Path-Resolution

vector<string> solve(vector<string>& path) {
    vector<string> store;
    for(int i=0;i<path.size();i++)
        if(path[i][0]!='.') store.push_back(path[i]); 
        else if (path[i]==".." && store.size()) store.pop_back();
    return store;
}
