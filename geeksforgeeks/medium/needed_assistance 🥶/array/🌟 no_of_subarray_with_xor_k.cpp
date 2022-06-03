#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
// QUESTION: find count of subarray with xor as k

/**
 * - Can be done in O(N^2) by finding all subarrays and calculating their XOR's
 * - But can be optimised how we did max subarray with count 0
 * 
 * LOGIC: For O(NlogN)
 * - LogN is taken by map for finding operation
 * 
 
x1, x2, x3, x4, x5, x6, x7
- - - - - -  * 

At 'x4', I found prefix XOR(^ till x4) to be 2
Required is 6 !
But let's say some subarray ending at x4 has XOR 6
so before that subarrray let's XOR be Y
Hence we can say Y ^ taget = XORtillx4
takig ^ taget both sides (or even logically)
So, Y = XORtillx4 ^ taget
Hence, at x4, we can check how many times Y appeared as prefix XOR
and add it to our result
This can be repeated at each index
**/
int countSubarrayWithXORAsK(vector<int>& arr, int target) {
    unordered_map<int, int> store;
    int result=0;
    int prefixXOR=0;
    for(int i=0;i<arr.size();i++) { 
        prefixXOR = prefixXOR ^ arr[i];
        if(prefixXOR == target) {
            result++;
        }
        if(store.count(prefixXOR ^ target)) {
            result+=store[prefixXOR ^ target];
        }
        store[prefixXOR]++;
    }
    return result;
}

int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int target = 6;
    cout<<countSubarrayWithXORAsK(arr, target);
}
