// https://binarysearch.com/problems/Mixed-Sorting

vector<int> solve(vector<int>& nums) {
    vector<int> even;
    vector<int> odd;
    vector<bool> flag(nums.size());
    int index=0;
    for(int num: nums) {
        if(num%2==0) {
            even.push_back(num);
            flag[index] = true;
        }
        else {
            odd.push_back(num);
            flag[index]=false;
        }
        index++;
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    int evenPtr=0;
    int oddPtr=odd.size()-1;
    vector<int> result;
    for(int i=0;i<flag.size();i++) {
        if(flag[i]) { //even
            result.push_back(even[evenPtr++]);
        }else { //odd
            result.push_back(odd[oddPtr--]);
        }
    }
    return result;
}