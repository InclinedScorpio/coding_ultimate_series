// https://leetcode.com/problems/magnetic-force-between-two-balls/

/**
 * Angry Bird Problem - uses monotonic Binary Search
 * 
 * QUESTION: Get the maximum, minimum distance which can be formed btw 2 birds
 * What does it mean?
 * means let's say positions are: 1, 4, 8, 12, 20, 33, 50
 * And only one these positions let's say 3 bird can be kept!
 * - let's say are one after another - (1), (4), (8).....
 * - Although the minimum btw 2 is 4, but it's not maximum, so how to find max?
 * (1)......(20).......(50)
 * - So 20, is the max! Although 30 is also there but 20 is the max we have
 * - And this 20 is the max value we were required to find!
 * 
 * So how to do it??
 * Let's see naeive approach is: first take distance as 1...
 * - And see if all birds can be kept - then 1 is definitely answer
 * - Then try 2... then 3... then 4... once num no longer can accomodate all then the latest saved ans is returned
 * 
 * 
 * How to optimize??
 * - This 1...2..3..etc are ordered numbers so rather than taking one by one we can do Binary Search
 * - Above 1 and 50 are extreme values so Binary Search will run from 1 to 49
 * - So first 24 will be taken, if all birds can't be accomodated in 24 then reject right and take left
 * - Now check 12 and accordingly move 
 * - This is O(logN)
 * - & is called Monotonic Binary Search! 
 * 
 * COMPLEXITY: O(NlogN)
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/**
 * LOGIC: Understanding Question is important
 * Above logic is mentioned
 * - Basically, we need to think the simple approach
 * - and then use Monotonic Binary Search where applicable
 * 
 * COMPLEXITY: O(NlogN)
 */ 
int canBirdsBePlacedWithDiff(vector<int>& nests, int birds, int diffCheck) {
    int latestPlaced=0;
    int birdsPlaced=1;
    int currSum=0;
    for(int i=1;i<nests.size();i++) {
        currSum+=(nests[i]-nests[i-1]);
        if(currSum>=diffCheck) {
            latestPlaced=i;
            currSum=0;
            birdsPlaced++;
            if(birdsPlaced == birds) return true;
        }
    }
    return false;
}

int findMaxMinDistBetweenTwo(vector<int>& nests, int birds) {
    int left = *min_element(nests.begin(), nests.end()), right=*max_element(nests.begin(), nests.end())-left;
    int currentMaxMinDistance=-1;
    while(left<=right) {
        int mid=(left+right)/2;
        bool areBirdsPlaced = canBirdsBePlacedWithDiff(nests, birds, mid);
        if(areBirdsPlaced) {
            left=mid+1;
            currentMaxMinDistance=mid;
        } else {
            right=mid-1;
        }   
    }
    return currentMaxMinDistance;
}

int main() {
    vector<int> nests = {1, 2, 4, 8, 9, 10, 23, 55, 67, 99, 393, 234234, 2334344,343243423};
    int birds=10;
    cout<<findMaxMinDistBetweenTwo(nests, birds);
}