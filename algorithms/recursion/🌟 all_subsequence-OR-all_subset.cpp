#include<iostream>
#include<set>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

void findAllSubsets(string str, string curr, int ind,  vector<string>& res) {
    if(ind>=str.length()) {
        res.push_back(curr);
        return;
    }
    findAllSubsets(str, curr + str[ind], ind+1, res);
    findAllSubsets(str, curr, ind+1, res);
    return;
}

bool compare(string a, string b) {
    if(a.length() == b.length()) {
        return a<b;
    } else {
        return a.length()<b.length();
    }
}

int main() {
    vector<string> store;
    string input;
    cin>>input;
    findAllSubsets(input, "", 0, store);
    sort(store.begin(), store.end(), compare);
    for(string str: store) {
        cout<<str<<" ";
    }
}
