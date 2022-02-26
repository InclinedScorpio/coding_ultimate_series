// https://binarysearch.com/problems/Happy-Numbers

bool solve(int n) {
    map<int,int> store;
    while(n!=1) {
        int temp=n;
        int sum=0;
        while(temp) {
            int value = temp%10;
            sum+=pow(value, 2);
            temp/=10;
        }
        n=sum;
        if(store.find(n)!=store.end()) {
            return false;
        }
        store[n]=1;
    }
    return true;   
}