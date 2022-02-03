// https://leetcode.com/problems/longest-mountain-in-array/

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
            if(i==0 || i==arr.size()-1) {
                if(i==0) { //first item
                    counter++;
                    continue;
                }
                if(top==1) { // last item
                    top=0;
                    counter++;
                    if(counter>maxCounter) {
                        maxCounter=counter;
                    }
                    counter=1;
                }
                break;
            }
            // check if top
            if(arr[i-1]<arr[i] && arr[i+1]<arr[i]) {
                top = 1;
                counter++;
                continue;
            }else if(arr[i-1]>arr[i] && arr[i+1]>=arr[i]) {
                if(top==1) {
                    counter++;
                    if(counter>maxCounter) {
                        maxCounter=counter;
                    }
                }
                top=0;
                counter=1;
            }else if(arr[i]==arr[i-1]){
                counter=1;
                top=0;
            }else {
                counter++;
            }
        }
        return maxCounter;
    }
};