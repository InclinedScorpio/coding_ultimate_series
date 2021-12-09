#include <bits/stdc++.h>
using namespace std;

int main() {

    int a=9;
    string value;

    while(a/2!=0) {
        int rem = a%2;
        value = to_string(rem)+value;
        a=a/2;
    }
    value = to_string(a)+value;

    cout<<value;

// Do Not Delete *********************
cout<<endl;
// Above Line ************************
}