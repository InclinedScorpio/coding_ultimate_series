// https://binarysearch.com/problems/Pascal's-Triangle

vector<int> solve(int n) {
    vector<int> prev;
    prev.push_back(1);
    if(n==0) return prev;
    prev.push_back(1);
    if(n==1) return prev;

    int index=2;
    for(int i=index;i<=n;i++) {
        vector<int> temp {1};
        for(int j=0;j<prev.size()-1;j++) {
            temp.push_back(prev[j]+prev[j+1]);
        }
        temp.push_back(1);
        prev = temp;
    }
    return prev;
}