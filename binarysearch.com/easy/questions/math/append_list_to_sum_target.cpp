// https://binarysearch.com/problems/Append-List-to-Sum-Target

int solve(vector<int>& nums, int k, int target) {
    int sums=0, result=0;
    for(int num: nums) sums+=num;
    if(target<=sums)
        if(target>=0) 
            while(target<sums && ++result) sums-=abs(k);
        else 
            while(target<sums && ++result) sums= sums+ (-1* abs(k));
    else
        if(target>=0) 
            while(target>sums && ++result) sums +=abs(k);
        else
            while(target>sums && ++result) sums+= (abs(k));
    return result;
}