// https://binarysearch.com/problems/3-6-9

vector<string> solve(int n) {
    vector<string> result;

    for(int i=1;i<=n;i++) {
        int num=i;
        bool isPrinted= false;
        if(num%3==0 || num%6==0 || num%9==0) {
                result.push_back("clap");
                isPrinted=true;
        }

        while(num>0 && !isPrinted) {
            int temp = num%10;
            if(temp && (temp%3==0 || temp%6==0 || temp%9==0)) {
                result.push_back("clap");
                isPrinted=1;
            }
            num=num/10;
        }

        if(!isPrinted) result.push_back(to_string(i));
    }
    return result;
}
