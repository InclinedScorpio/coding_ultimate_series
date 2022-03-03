/**
 * @QUESTION:
 * Minimum Difference
 * 
 * Implement a function that takes in two non-empty arrays of integers, finds the pair of numbers (one from each array) who absolute difference is closest to zero, and returns a pair containing these two numbers, with the first number from array. Only one such pair will exist for the test.
 * 
 * > Input
 * 
 * Array1 = [23, 5, 10, 17, 30]
 * Array2 = [26, 134, 135, 14, 19]
 * 
 * > Output
 * 
 * [17,19]
 * 
 */ 

/**
 * @LOGIC: Sort both vectors and then use 2 ptr approach
 * - Both ptr will start from the 0th index
 * - check the difference and increment the one which is the reason of more gap (we need to find minimum gap)
 * - Example
 * - If first: 10, second: 15, then increment first one so we could get near 15
 * - Now if next to 10 is 50, then we will increment second(15) so we could get to near to 50 so answer could be near to 0
 * 
 */ 
pair<int,int> minDifference(vector<int> a,vector<int> b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // sorted both- now 2 ptr approach to find the no. nearest to 0
    int aitr = 0;
    int bitr = 0;
    int maxValue = INT_MAX;
    pair<int, int> valToReturn;
    while(aitr<a.size() && bitr<b.size()) {
        if(maxValue> abs(a[aitr] - b[bitr])) {
            maxValue = abs(a[aitr]-b[bitr]);
            valToReturn = {a[aitr], b[bitr]};
        }
        if(a[aitr]>b[bitr]) {
            bitr++;
        } else {
              aitr++;
        }
    }
    return valToReturn;
}
