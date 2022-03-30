// https://binarysearch.com/problems/Check-if-Number-Is-Perfect-Square

bool solve(int n) {
    int left=0, right=n;
    while(left<=right) {
        int mid = (left+right)/2;
        if(pow(mid,2)==n) return true;
        if(pow(mid, 2)<n) left = mid+1;
        else right = mid-1;
    }
    return false;
}