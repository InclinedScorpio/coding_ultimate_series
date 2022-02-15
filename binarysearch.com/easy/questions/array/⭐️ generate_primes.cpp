// https://binarysearch.com/problems/Generate-Primes

bool checkPrime(int num) {
    if(num%2==0) return false;
    for(int i=3;i<=pow(num,0.5);i=i+2) {
        if(num%i==0) return false;
    }
    return true;
}

vector<int> solve(int n) {
    if(n==0 || n==1) return {};
    
    vector<int> primes;
    if(n==2) return {2};
    primes.push_back(2);

    for(int i=3;i<=n;i=i+2) {
        if(checkPrime(i)) primes.push_back(i);
    }

    return primes;
}