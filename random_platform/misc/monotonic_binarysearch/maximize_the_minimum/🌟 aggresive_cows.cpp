// https://www.spoj.com/problems/AGGRCOW/

/**
 * LOGIC: Question states to maximize the minimum - hence a monotonic binary search question
 * - We can pick a range from 1 - maxDistancePossible
 * - & can see if mid satisfies the distance and all k cows can come under it
 * - If yes! -> move mid to right -> we want to maximize it
 * - ⭐️ We just need to see if that mid satisfies the k cows, it will automatic pick the max distance of min possible.
 * 
 * COMPLEXITY: O(NlogN)
 * 
 */ 

bool isDistancePossible(vector<int> &stalls, int k, int dist) {
    int cowsPlaced=1, lastCowPlacedAt=stalls[0];
    for(int i=1;i<stalls.size();i++) {
        if(stalls[i]-lastCowPlacedAt >= dist) {
            cowsPlaced++;
            lastCowPlacedAt=stalls[i];
        }
        if(cowsPlaced==k) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int left = 1, right = stalls[stalls.size()-1] - stalls[0];
    
    int result = -1;
    while(left<=right) {
        int mid = left + (right-left)/2;
        if(isDistancePossible(stalls, k, mid)) {
            result = mid;
            left=mid+1;
        } else {
            right = mid-1;
        }
    }
    return result;
}