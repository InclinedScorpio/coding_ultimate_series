// https://binarysearch.com/problems/Reverse-Words-Sequel

/**
 * LOGIC: Main logic was to understand that stack and deque will be required
 * - Deque advantage comes during these times when operations from both end needs to be performed
 * - once understood, only coding part and checking edge cases is there
 * 
 * COMPLEXITY: O(N*Del)
 * 
 */ 
bool isCharAlpha(vector<string>& delimiters, char ch) {
    string toComp = "";
    toComp+=ch;
    for(int i=0;i<delimiters.size();i++) {
        if(toComp == delimiters[i]) return false;
    }
    return true;
}

string solve(string sentence, vector<string>& delimiters) {
    deque<string> delim;
    string str="";
    stack<string> store;
    bool isFirstDel = false;
    
    if(!isCharAlpha(delimiters, sentence[0])) isFirstDel = true;
    for(int i=0;i<sentence.length();i++) {
        if(!isCharAlpha(delimiters, sentence[i])) {
            if(str=="") {
                string s="";
                if(delim.size())
                    s = delim.back();
                s+=sentence[i];
                if(delim.size())
                    delim.pop_back();
                delim.push_back(s);
                continue;
            }
            string delpush ="";
            delpush+=sentence[i];
            delim.push_back(delpush);
            store.push(str);
            str = "";
        } else if(i==sentence.length()-1) {
            str+=sentence[i];
            store.push(str);
        } else {
            str+=sentence[i];
        }
    }


    // arrange the result from stack and queue
    str="";
    if(isFirstDel && !delim.empty()) {
            str+=delim.front(); 
            delim.pop_front();
    }
    while(store.size()>0 || delim.size()>0) {
        if(!store.empty()) {
            str+=store.top(); 
            store.pop();
        }
        if(!delim.empty()) {
            str+=delim.front(); 
            delim.pop_front();
        }
    }
    return str;
}