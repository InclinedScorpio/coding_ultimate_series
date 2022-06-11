// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

/**
 * LOGIC: Here, we need to understand that profit needs to be maximized
 * - Hence it's a greedy problem
 * 
 * - Now to sorting based on profit makes sense as we need to maximize profit
 * - But the timing is also important
 * - Hence let's say =>  time1: profit2, time1:profit4  is there
 * - Hence obviously we will pick time1:profit4
 * 
 * - Now let's say time 5: profit 12 is there
 * - Hence we will do this work at 5th time interval (so that we can accomodate previous deadlines(1-4))
 * 
 * - To store which interval is done, we will take an array(-1 filled) and will fill it with the work which we need to do
 * - Now let's say time 5: profit 11 came...
 * - Hence we can start traversing from 5...4...3...2...1
 * - And whenever we get empty slow we would fill it! ⭐️
 * 
 * COMPLEXITY: O(NlogN) + O(N*M)
 * - Don't worry about N^2 problems, for this problem it would work fine
 *  
 */ 
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comparator(Job a, Job b) {
        return a.profit>b.profit;
    } 

    vector<int> JobScheduling(Job arr[], int n) 
    {
        int maxDeadline=0;
        for(int i=0;i<n;i++) {
            if(arr[i].dead>maxDeadline) maxDeadline = arr[i].dead;
        }
        vector<int> deadlines(maxDeadline+1, -1);
        // cout<<maxDeadline<<endl;
        
        sort(arr, arr+n, comparator);
        int maxProfit=0, count=0;
        for(int i=0;i<n;i++) {
            int dead = arr[i].dead;
            while(dead>=1 && deadlines[dead]!=-1) {
                dead--;
            }
            if(dead==0) continue;
            deadlines[dead]=arr[i].id;
            maxProfit+=arr[i].profit;
            count++;
        }
        return {count, maxProfit};
    }
};