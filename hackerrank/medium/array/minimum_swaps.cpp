// https://www.hackerrank.com/challenges/minimum-swaps-2/problem


/**
 * LOGIC: Basic problem
 */ 
int minimumSwaps(vector<int> arr) {
    int swaps=0;
    for(int i=0;i<arr.size();i++) {
        int expectedNum=i+1;
        if(arr[i]!=expectedNum) {
            swap(arr[i], arr[arr[i] - 1]);
            i--;
            swaps++;
        }
    }
    return swaps;
}