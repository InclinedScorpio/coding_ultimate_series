#include <bits/stdc++.h>
using namespace std;

int main() {

    long a = 1010110; // binary
    long long value = 0; //ans-store.

    int twoPow = 0; //2's pow

    while(a!=0) {
        int num = a%10;
        value+= num*(pow(2, twoPow));
        twoPow++;
        a = a/10;
    }

    cout<<value;

// Do Not Delete *********************
cout<<endl;
// Above Line ************************
}