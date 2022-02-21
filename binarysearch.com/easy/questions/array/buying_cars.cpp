// https://binarysearch.com/problems/Buying-Cars

int solve(vector<int>& prices, int k) {
    sort(prices.begin(), prices.end());
    int result=0;
    for(int price: prices) {
        k = k-price;
        if(k>=0) result++;
    }
    return result;
}