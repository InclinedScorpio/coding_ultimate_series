// https://binarysearch.com/problems/ASCII-String-to-Integer

int solve(string s) {
    vector<string> store;
    string str="";
     int result=0;

    for(char i: s){
        if(!isalpha(i)) str+=i;
        else {
            store.push_back(str);
            if(str.length()) 
            result = result + stoi(str);
            
            str="";
        }
    }
    if(str.length()>0) {
        store.push_back(str);
        result = result + stoi(str);
    }
    return result;
}
