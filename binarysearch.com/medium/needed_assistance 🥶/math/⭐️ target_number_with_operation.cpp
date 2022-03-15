// https://binarysearch.com/problems/Target-Number-with-Operations

/**
 * LOGIC: Go from end -> start
 * - Keep /2 till it's more than start
 * - Once /2 is going less than start, we can just go one step at a time (-1) to reach there
 * - This approach would be fastest! (IMPORTANT)
 * 
 */ 
int solve(int start, int end) {
    int count=0;
    while(end>start) {
        if((floor(end/2))<start) return count+(end-start);
        if(end%2==0) {
            end=end/2;
        } else {
            end--;
        }
        count++;
    }
    return count;
}
