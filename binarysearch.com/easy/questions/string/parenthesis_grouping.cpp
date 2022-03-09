// https://binarysearch.com/problems/Parentheses-Grouping

vector<string> solve(string s) {
    vector<string> result;
    stack<char> stack;
    string store="";
    for(int i=0;i<s.length();i++) {
        if(s[i]=='(') {
            stack.push('(');
            store+='(';
        } else {
            stack.pop();
            store+=')';
            if(stack.empty()) {
                result.push_back(store);
                store="";
            }
        }
    }
    return result;
}
