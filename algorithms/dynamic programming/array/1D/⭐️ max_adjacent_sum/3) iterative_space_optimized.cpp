/**
 * QUESTION: Find maximum sum where no adjacent num is choosen
 * 
 * LOGIC: 
 *  - Similar to 2)
 *  - Only thing done is optimized space
 *  - As dp was taking O(N) as we only required immediateNext & current maximum
 *  - hence, we can remove O(N) and can use only these 2 variables
 * 
 * COMPLEXITY: O(N)
 * SPACE COMPLEXITY: O(1)
 * 
 */   

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main() {
    vector<int> nums = {6, 10, 12, 7, 9, 14};
    int nextOne = nums[nums.size()-2];
    int currMax = nums[nums.size()-1];

    for(int i=nums.size()-3;i>=0;i--) {
        int left = nextOne;
        int right = currMax + nums[i];
        if(nextOne>currMax) currMax = nextOne;
        nextOne = max(left, right);
    }
    cout<<nextOne;
}