// https://binarysearch.com/problems/123-Number-Flip

int solve(int n) {
    vector<int> store;
    int cpyn = n;
    while(n) {
        store.push_back(n%10);
        n=n/10;
    }
    for(int i=store.size()-1;i>=0;i--) {
        if(store[i]!=3) {
            store[i]=3;
            break;
        }
    }
    int currInd=0;
    int num=0;
    for(int i=0;i<store.size();i++) {
        num = num + (store[i] * pow(10, currInd++));
    }
    return num;
}