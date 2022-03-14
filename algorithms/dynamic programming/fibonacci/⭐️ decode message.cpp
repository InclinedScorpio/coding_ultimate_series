// https://binarysearch.com/problems/Decode-Message

/**
 * LOGIC: (Let X means non zero)
 * - At some point we will be concerned about index and previous index combined
 * - Why? coz range is 1-26
 * - Main point to understand:
 * 1. If current is X and previous is X....
 *  This means we can append current X to all previous soln found in (index-1)
 *  Or else we can take both combined and can append it to solutions found out in (index-2)
 *  So, total solutions will be solution_in_prev_step + solution_in_prev_to_prev_step
 *  
 * NOTE: If you append current index alphabet 'a' to previous solution- that means previous solution = current no of solution
 * - WHY? because we are just adding 'a' to solution we have already found out
 * - If we take combination _X_ _X_ - then this alphabet we will be apending to solutions found out in prev to prev step
 * - Hence the total solutions at any index is solution_in_prev_step + solution_in_prev_to_prev_step
 * 
 * - But it will also depend upon where is '0' coming
 * 1.
 * - (NoN-ZERO(X), ZERO) - This means current index '0' can't take, so take combination only that means current solutions...
 * - ...will be previous to previous no. of solutions
 * 
 * 2.
 * - (ZERO, NoN-ZERO(X)) - This means current would be a single character only as previous can't be taken in combined - it's 0
 * - Hence solutions will be whatever no. of soln found previously
 * 
 * 3.
 * - (ZERO, ZERO) - can't decode 
 * 
 * 4.
 * - X, X - This is our base case discussed at top
 * 
 * SO, We need to take care of these 4 scenarios
 * - The no. of conditions are more hence it's little complicated
 * 
 * TIMECOMPLEXITY: O(N)
 * SPACECOMPLEXITY: O(N)
 * - A vector is taken for DP which stores the solution at current index
 * 
 */ 
int solve(string message) {
    if(
        message.length()==0 
    || (message.length()>0 && message[0]=='0')
    ) return 0; // empty string or 0 at staring

    // logic
    vector<int> store(message.length()+1, 0);
    store[0]=1;
    store[1]=1;
    for(int i=1;i<message.length();i++) {
        // 4 cases | (X)-> means not 0
        int storeInd=i+1; // index for store will be 1 ahead of message
        if (message[i-1]=='0' && message[i]=='0') { // 0, 0
            return 0;
        } else if (message[i-1]=='0' && message[i]!='0') { // 0, X
            store[storeInd]=store[storeInd-1];
        } else if (message[i-1]!='0' && message[i]=='0' && (message[i-1]=='1' || message[i-1]=='2')) { // X, 0
            store[storeInd]=store[storeInd-2];
        } else if (message[i-1]!='0' && message[i]!='0') { // X, X
            if((message[i-1]=='2' && message[i]>'6') || message[i-1]>'2') store[storeInd]=store[storeInd-1];
            else store[storeInd]=store[storeInd-1]+store[storeInd-2];
        } else return 0; // in any weird case when nothing matches
    }

    return store[message.length()];
    
}