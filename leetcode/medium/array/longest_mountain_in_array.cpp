// https://leetcode.com/problems/longest-mountain-in-array/

/**
 * LOGIC: Basic But Good Question
 * - You basically have to think about 2 conditions, when at bottom and when at top
 * - When at bottom you must start counting
 * - When at top you must mention that top is passed and now bottom should come
 * 
 * - As soon as you get next bottom, check if "top was passed (top==1)"
 * - If yes, check the counter and see if it's maximum till now
 * - If not, just counter=1 as you are at bottom and reset the top (top=0)
 * 
 * EDGECASES:
 * - At last point, see if have come through top! (That means its the bottom) and see if counter is maximum
 * - At starting point, just reset the top as:
 * 1. If top comes after starting point then it will set it to 1 and next bottom will get counter i.e from starting
 * 2. If bottom comes after starting point (bottom resets the top and does counter=1) so again the process starts from there
 * 
 * - Points can be EQUAL, in this case we make sure to reset both top and counter=1 as condition of mountain is
 * There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
 * arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 * 
 * TIMECOMPLEXITY: O(N)
 * SPACECOMPLEXITY: O(1)
 */ 
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()<3) {
            return 0;
        }
        int top=0;
        int counter=0;
        int maxCounter=0;
        for(int i=0;i<arr.size();i++) {
            // start OR end
            if(i==0 || i==arr.size()-1) { // starting or end point
                if(i==0) { // starting item
                    counter++;
                    continue;
                }
                if(top==1) { // end item
                    top=0;
                    counter++;
                    if(counter>maxCounter) {
                        maxCounter=counter;
                    }
                    counter=1;
                }
                break;
            }

            if(arr[i-1]<arr[i] && arr[i+1]<arr[i]) { // TOP
                top = 1; // set the top 
                counter++;
                continue;
            }else if(arr[i-1]>arr[i] && arr[i+1]>=arr[i]) { // BOTTOM use Equal for the case when points equal (arr[i+1]>=arr[i]) to cover the point where bottom is reached but next of bottom is also equal to bottom :)
                if(top==1) { // at bottom, check if top came through while reaching at this point
                    counter++;
                    if(counter>maxCounter) {
                        maxCounter=counter;
                    }
                }
                top=0; // reset top and counter at bottom
                counter=1;
            }else if(arr[i]==arr[i-1]){ // If point eq. to last point
                counter=1; // reset top and counter at point eq. to last
                top=0;
            }else { // Just increase the counter
                counter++;
            }
        }
        return maxCounter;
    }
};