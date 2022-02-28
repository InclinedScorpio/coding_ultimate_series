// https://binarysearch.com/problems/Remove-One-Letter

bool solve(string s0, string s1) {

    if(s0.length()!=s1.length()+1) return false;

    int right=0;
    int left=0;
    int count=0;
    while(right < s1.length()) {
        if(s0[left]!=s1[right]) {
            if(s0[left+1]!=s1[right]) {
                return false;
            }
            right--;
            count++;
        }
        if(count>1) {
            return false;
        }
        left++;
        right++;
    }
    return true;
    
}