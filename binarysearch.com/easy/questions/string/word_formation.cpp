// https://binarysearch.com/problems/Word-Formation

int solve(vector<string>& words, string letters) {
    map<char,int> store;
    for(int i=0;i<letters.length();i++) {
        store[letters[i]]++;
    }
    int maxLength=-1;
    for(string str: words) {
        map<char, int> copyStore = store;
        int i=0;
        int reject=0;
        for(i=0;i<str.length();i++) {
            if(copyStore.find(str[i])!=copyStore.end()) {
                if(copyStore[str[i]]==0) {
                    reject=1;
                    break;
                }
                copyStore[str[i]]--;
            } else {
                reject=1;
                break;
            }
        }
        if(i==str.length() && reject==0) {
            int len = str.length();
            if(len>maxLength) maxLength = str.length();
        }
    }
    return max(maxLength, 0);
}