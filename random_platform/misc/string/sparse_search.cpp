/**
 * QUESTION: Sorted array of string is given with empty string in btw
 * - Find the index of required string and see if it exists
 * 
 * LOGIC: Can be done easily using linear but as string is sorted we can do binary search
 * - Main logic is to shift mid to appropriate position so that comparison could take place
 
 * 
 * COMPLEXITY: O(NlogN)
 */ 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int sparseSearch(string str[], int n, string search) {

    int left=0, right=n;
    while(left<=right) {
        int mid=(left+right)/2;
        int leftStrFinder=mid;
        int rightStrFinder=mid;
        while(!str[leftStrFinder].length() && !str[rightStrFinder].length()) {
            if(leftStrFinder>0) leftStrFinder--;
            if(rightStrFinder<n) rightStrFinder++;
        }
        mid = str[leftStrFinder].length()>0 ? leftStrFinder : rightStrFinder;
        if(str[mid]==search) {
            return mid;
        }
        if(str[mid]>search) {
            right=mid-1;
        } else {
            left=mid+1;
        }
    }
    return -1;
}

int main() {
    string str[] = {"ai", "", "", "", "bat", "","", "", "", "","", "", "", "ca", "cat", "","","","","","dog","","","eat"};
    cout<<sparseSearch(str, (sizeof(str)/sizeof(str[0]))-1, "ai");
}