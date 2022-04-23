#include<iostream>
#include<stack>

using namespace std;

bool isBalanced(string str) {
    stack<char> store;

    for(int i=0;i<str.length();i++) {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[') {
            store.push(str[i]);
        } else {
            if((str[i]==')' || str[i]=='}' || str[i]==']') && store.empty()) {
                return false;
            }
            char atTop = store.top();
            if(str[i]==')' && atTop!='(') {
                return false;
            }
            else if(str[i]=='}' && atTop!='{') {
                return false;
            }
            else if(str[i]==']' && atTop!='[') {
                return false;
            }
            if(str[i]==')' || str[i]=='}' || str[i]==']') {
                store.pop();
            }
        }
    }
    if(store.size()>0) return false;
    return true;
}

int main() {
    string str = "((a+b+c)+[d])";
    if(isBalanced(str)) {
        cout<<"String is Balanced";
    } else {
        cout<<"String is not balanced";
    }
}