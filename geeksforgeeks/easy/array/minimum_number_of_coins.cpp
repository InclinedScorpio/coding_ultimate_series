// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1/#

/**
 * LOGIC: As we need to minimize coins
 * - Just pick the greater ones first and see how many of those can be taken
 * - Then pick next smaller if greater one can't accomodate it
 * 
 * COMPLEXITY: O(N) + O(coinsArray)
 * 
 */ 
public:
    vector<int> minPartition(int N)
    {
        vector<int> coin = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        int ind = 0, coins = 0;
        vector<int> result;
        
        while(N) {
            if(N/coin[ind] > 0) {
                coins+=N/coin[ind];
                for(int i=0;i<N/coin[ind];i++) {
                    result.push_back(coin[ind]);
                }
            }
            N = N - (N/coin[ind])*coin[ind];
            ind++;
        }
        return result;
    }
};