// https://binarysearch.com/problems/Longest-Common-Prefix

string solve(vector<string>& words) {
    int index=0;
    int iterator=0;
    string commonPrefix="";
    while(true) {
        char toCheck='0';
        for(int i=0;i<words.size();i++) {
            if(words[i].length()<=index)  {
                return commonPrefix;
            }
            if(toCheck=='0') {
                toCheck=words[0][index];
            } else {
                if(toCheck!=words[i][index]) return commonPrefix;
            }
        }
        commonPrefix+=words[0][index];
        index++;
    }
    return commonPrefix;
}