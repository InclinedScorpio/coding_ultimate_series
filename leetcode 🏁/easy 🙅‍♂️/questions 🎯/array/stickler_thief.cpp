// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1#

/**
 * COMPLEXITY: O(N)- Dynamic Programming
 * LOGIC: Similar logic to Tree > max subset sum
 * 1. On every index create 2 things...
 * 1.1. Inclusion: take current index + earlier exclusion value
 * 1.2. Exclusion: take max of inclusion/ exclusion from earlier
 * 
 */ 

// Function to find the maximum money the thief can get.
// Theif can't go into adjacent houses
    int FindMaxSum(int arr[], int n)
    {
        // first: inclusion, second: exlusion
        pair<int,int> prevHouse;
        for(int i=0;i<n;i++) {
            pair<int,int> currHouse;
            if(i==0) {
                currHouse.first=arr[i];
                currHouse.second=0;
                prevHouse = currHouse;
                continue;
            }
            
            // inclusion: take current index + earlier exclusion value
            currHouse.first = arr[i] + prevHouse.second;

            // exclusion: take max of inclusion/ exclusion from earlier
            currHouse.second = max(prevHouse.first, prevHouse.second);
            
            // handover data for next iteration
            prevHouse = currHouse;
        }

        // print max of last house inclusion/exclusion
        return max(prevHouse.first, prevHouse.second);
    }