// https://binarysearch.com/problems/Making-Change

int solve(int n) {
    vector<int> prices = {25, 10, 5, 1};
    int count=0;
    int ind =0;
    while(n) {
        if(n>=prices[ind]) {
            count+=(n/prices[ind]);
            n = n%prices[ind];
        }
        ind++;
    }
    return count;
}