// https://practice.geeksforgeeks.org/problems/minimum-swaps

/**
 * LOGIC: First swap items to atlease know where is the real pos of items
 * 1. Brute force approach
 * - Check which is the next item which is smaller which we can swap... O(N^2)
 * - This is not minimum swap obviously
 * 
 * 2. Using pair<int,int> to keep the record of real index of items
 * - Sort the items containing the index
 * - Traverse and check if the current item is at it's current index
 * - If not swap it to it's correct index
 * 
 * NOTE: After swapping, keep index at curr pos, as new item at curr index may not belong there
 * Hence i--; is done to again check the new item came after swapping
 * 
 */
class Solution 
{
    public:
    
	int minSwaps(vector<int>&nums)
	{
	    int count=0;
	    vector<pair<int,int>> store;
	    for(int i=0;i<nums.size();i++) store.push_back({nums[i], i});
	    
		vector<pair<int,int>> sortedStore = store;
	    sort(sortedStore.begin(), sortedStore.end());
	    
	    for(int i=0;i<sortedStore.size();i++) {
	        if(sortedStore[i].second == store[i].second) {
	            continue;
	        } else { //if curr item not belong to correct pos, take it to it's real pos
	            swap(sortedStore[i], sortedStore[sortedStore[i].second]);
	            count++; i--;
	        }
	    }
	    return count;
	}
};