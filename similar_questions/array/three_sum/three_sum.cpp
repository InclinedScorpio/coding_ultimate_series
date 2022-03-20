#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

/**
 * LOGIC: Just use a iterator - O(N) +  Apply 2 pointer approach from iterator+1 to end - so you basically get 3 ptrs :)
 * - 2 Pointer Approach - O(N)
 * 
 * TIMECOMPLEXITY: O(N^2)
 * - For 2 pointer approach sorting is required i.e O(NlogN) but as our approach is O(N^2) > O(NlogN), sorting won't make any difference to TC
 * 
 */ 
vector<vector<int>> threeSum(vector<int> myNum, int target) {
    if(myNum.size()<3) { //edge case, not possible to pick 3 ptr
        return {};
    }

    sort(myNum.begin(), myNum.end());
    vector<vector<int>> result;

    for(int i=0;i<myNum.size()-2;i++) {
        if(i>0 && myNum[i]==myNum[i-1]) {
            continue;
        }

        int left=i+1, right=myNum.size()-1;
        /**
         * - 2 POINTER APPROACH - O(N)
         * - FOR 2 POINTER APPROACH - JUST THAT ARRAY MUST BE SORTED
         * - 2 POINTER APPROACH - Using 2 ptr we can tell if a sum exists by moving both ptr forward, backward
         */ 
        while(left<right) {
            int currSum = myNum[i]+myNum[left]+myNum[right];
            if(currSum==target) {
                result.push_back({myNum[i], myNum[left], myNum[right]});
                /**
                 * - These 2 while loops used so that we can skip duplicates as(1,2,2,2,3,3,3,3,4,4,4,4....) can fetch multiple (2,7,9) or (1,2,15) etc!
                 * - These 2 while loops are not part of 2 Pointer approach but rather to help us skip getting duplicates
                 */ 
                while(left<myNum.size()-1 && left<right && myNum[left]==myNum[left+1]) {left++;}
                while(right>0 && left<right && myNum[right]==myNum[right-1]) {right--;}
                // above while will take the ptr to edge of duplicates, below will take 1 step forward/backward.
                left++;
                right--;
            }else if(currSum < target) {
                left++;
            }else {
                right--;
            }
        }
    }
    return result;
}

int main() {
    vector<int> num = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    int target=18;
    auto result = threeSum(num, 0);
    cout<<"[";
    for(vector<int> vec: result) {
        cout<<"[";
        for(int num: vec) {
            cout<<num<<", ";
        }
        cout<<"],"<<endl;
    }
    cout<<"]";
}
