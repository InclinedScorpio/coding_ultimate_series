// https://leetcode.com/problems/evaluate-reverse-polish-notation/

/**
 * LOGIC: Simple postfix notation - use stack
 *
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> store;
        int i=0;
        while(i<tokens.size()) {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/") {
                int first = store.top();
                store.pop();
                int second = store.top();
                store.pop();
                if(tokens[i]=="+") {
                    store.push(first+second);
                } else if(tokens[i]=="-") {
                    store.push(second-first);
                } else if(tokens[i]=="*") {
                    store.push(second*first);
                } else if(tokens[i]=="/") {
                    store.push(second/first);
                }
            } else {
                store.push(stoi(tokens[i]));
            }
            i++;
        }
        return store.top();
        
    }
};