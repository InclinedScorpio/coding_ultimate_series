// https://binarysearch.com/problems/Lexicographic-Swap

string solve(string s) {
    int firstIndex=0;
    char firstChar=s[0];
    for(int i=0;i<s.length()-1;i++) {
        bool isSwapped = false;
        int indexToBeSwapped;
        char toBeComparedWith=s[i];
        for(int j=i+1;j<s.length();j++) {
            if(s[j]!=s[i] && toBeComparedWith>=s[j]) {
                toBeComparedWith = s[j];
                indexToBeSwapped=j;
                isSwapped=true;
                indexToBeSwapped=j;
            }
        }
        if(isSwapped) {
            swap(s[i], s[indexToBeSwapped]);
            return s;
        }
    }
    return s;
}
