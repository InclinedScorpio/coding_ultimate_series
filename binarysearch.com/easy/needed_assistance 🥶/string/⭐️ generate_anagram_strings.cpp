
/**
 * QUESTION: Get all substrings in string which are anagram of each other
 * LOGIC: We can simply find all possible substrings
 * - And then sort and keep them with their index
 * - As we are sorting the anagrams will be inside same map key
 * - Also we will store the index!
 * - Hence the keys which have more than one index...
 * - ...mean we have the anagram hence can be included in the result!
 * 
 * COMPLEXITY: O(N^3logN)
 * - Large complexities work when input is small ~100, 1000
 */ 
vector<string> generateSubstring(string s) {
    vector<string> result;
    for(int i=0;i<s.length();i++) {
        string str="";
        for(int j=i;j<s.length();j++) {
            str+=s[j];
            result.push_back(str);
        }
    }
    return result;
}

vector<string> solve(string s) {
    vector<string> subStrings = generateSubstring(s);
    map<string, vector<int>> store;
    for(int i=0;i<subStrings.size();i++) {
        string str = subStrings[i];
        sort(str.begin(), str.end());
        store[str].push_back(i);
    }
    vector<string> result;
    for(auto items: store) {
        if(items.second.size()>1) {
            for(int i=0;i<items.second.size();i++) {
                result.push_back(subStrings[items.second[i]]);
            }
        }
    }
    sort(result.begin(), result.end());
    return result;
}