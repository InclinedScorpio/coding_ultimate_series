// https://binarysearch.com/problems/Word-Machine

int solve(vector<string>& ops) {

    stack<int> result;

    for(int i=0;i<ops.size();i++) {
       if(ops[i]=="POP") {
           if(result.size()==0) return -1;
           result.pop();
       } else if(ops[i]=="DUP") {
            if(result.size()==0) return -1;
            int topItem = result.top();
            result.push(topItem);
       } else if(ops[i]=="+") {
            if(result.size()==0) return -1;
            int first = result.top();
            result.pop();
            if(result.size()==0) return -1;
            int second = result.top();
            result.pop();
            result.push(first+second);
       } else if(ops[i]=="-") {
            if(result.size()==0) return -1;
            int first = result.top();
            result.pop();
            if(result.size()==0) return -1;
            int second = result.top();
            result.pop();
            result.push(first-second);
       } else {
           result.push(stoi(ops[i]));
       }
    }
    return result.top();
}
