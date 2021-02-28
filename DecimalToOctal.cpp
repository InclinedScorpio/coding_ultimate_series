#include <bits/stdc++.h>
using namespace std;

int main() {

    long long a = 16;
    string ans = "";

    while(a!=0) {
        int num = a%9;
        ans = to_string(num) + ans;
        a = a/9;
    }

    cout<<ans;


// Do Not Delete *********************
cout<<endl;
// Above Line ************************
}