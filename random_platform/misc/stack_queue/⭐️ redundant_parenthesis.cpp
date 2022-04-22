/**
 * QUESTION: Check if statement contains redundant parenthesis
 * LOGIC: Keep pushing & start popping once closing bracket received
 * - while popping make sure you check if operator was received
 * 
 * COMPLEXITY: O(N)
 */ 

#include<iostream>
#include<stack>

using namespace std;

bool isRedundantParenthesis(string s) {
    stack<char> store;
    for(int i=0;i<s.length();i++) {
        if(s[i]!=')' && s[i]!='}' &&  s[i]!=']') {
            store.push(s[i]);
        } else {
            // means closing
            bool isOperatorPresent = false;
            while(store.top()!='(' && store.top()!='{' && store.top()!='[') {
                if(store.top()=='+' || store.top()=='*' || store.top()=='-') {
                    isOperatorPresent = true;
                }
                store.pop();
            }
            if(!isOperatorPresent) {
                return true;
            }
            store.pop();
        }
    }
    return false;
}

int main() {
    string str = "(a+(b-c)-3)(3-(3))";
    if(isRedundantParenthesis(str)) {
        cout<<"Redundant present";
    } else {
        cout<<"Redundant not present";
    }
}