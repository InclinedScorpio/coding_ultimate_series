#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<string> findSubstrings(string str) {
    vector<string> result;
    for(int i=0;i<str.length();i++) {
        for(int j=1;(i+j-1)<str.length();j++) {
            result.push_back(str.substr(i, j));
        }
    }
    return result;
}

bool checkAnagram(string str1, string str2) {
    if(str1.length()!=str2.length()) return false;
    map<char, int> str1Map;
    map<char, int> str2Map;
    for(int i=0;i<str1.length();i++) {
        str1Map[str1[i]]++;
        str2Map[str2[i]]++;
    }
    for(pair<char,int> mapItem: str1Map) {
        if(str2Map[mapItem.first]!=mapItem.second) return false;
    }
    return true;
}

int findNumberOfAnagramSubstring(string str) {

    // find all substrings to match
    int count=0;
    vector<string> subStrings = findSubstrings(str);
    for(int i=0;i<subStrings.size();i++) {
        for(int j=i+1;j<subStrings.size();j++) {
            if(checkAnagram(subStrings[i], subStrings[j])) count++;
        }
    }
    return count;
}

int main() {
    string str="abba";
    cout<<findNumberOfAnagramSubstring(str);
}