// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

/**
 * LOGIC: Question is different than the one "how many max meeting can happen"
 * - Here we are required to find the "number of platforms so that no has to keep waiting"
 * - If you see closely, we don't even require the pairs
 * - What that means?
 * - Think in perspective of rail guard
 * 
 * - In his diary he will just see what's the next train timing & if before that any train is leaving then it's fine
 * - Or else he will increment the plaform
 * 
 * - Hence initially he will sort the arrival array
 * - Then he will sort the departure array
 * - Now we keep 2 pointers in arr and dep arrays
 * - And increase platform only if any arrival is scheduled before departure of train with least time
 * 
 * COMPLEXITY: O(NlogN)
 * SPACE: O(1)
 * 
 */
class Solution {
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	int currPlatforms=1, maxPlatforms=1;
    	sort(arr, arr+n);
    	sort(dep, dep+n);
        int arrInd=1, depInd=0; 
    	while(arrInd<n) {
    	   if(arr[arrInd]<=dep[depInd]) {
    	       currPlatforms++;
    	       //cout<<currPlatforms<<endl;
    	       arrInd++;
    	       if(currPlatforms > maxPlatforms) {
    	           maxPlatforms = currPlatforms;
    	       }
    	   } else {
    	       depInd++;
    	       currPlatforms--;
    	   }
    	}
    	return maxPlatforms;
    }
};
