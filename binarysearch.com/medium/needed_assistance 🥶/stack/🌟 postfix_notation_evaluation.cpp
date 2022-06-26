// https://binarysearch.com/problems/Postfix-Notation-Evaluation

/**
 * LOGIC: We can see we are required to pick two data at once
 * - But operators can come anytime (king of nested) 2, 3, +, 4, 5, +, +
 * - Hence use stack so that we can do op and store result back to stack
 * - That will take care of complete postfix condition
 * 
 * COMPLEXITY: O(N)
 */ 
int solve(vector<string>& exp) {
    int left=INT_MIN, right=INT_MIN;
    stack<long long int> stack;
    for(int i=0;i<exp.size();i++) {
        if(exp[i]=="+") {
            long long int left = stack.top();
            stack.pop();
            long long int right = stack.top();
            stack.pop();
            stack.push(left + right);
        } else if(exp[i]=="-") {
            long long int left = stack.top();
            stack.pop();
            long long int right = stack.top();
            stack.pop();
            stack.push(right - left);
        } else if(exp[i]=="*") {
            long long int left = stack.top();
            stack.pop();
            long long int right = stack.top();
            stack.pop();
            stack.push(left * right);
        } else if(exp[i]=="/") {
            long long int left = stack.top();
            stack.pop();
            long long int right = stack.top();
            stack.pop();
            stack.push(right/left);
        } else {
            stack.push(stoi(exp[i]));
        }
    }
    return stack.top();
}