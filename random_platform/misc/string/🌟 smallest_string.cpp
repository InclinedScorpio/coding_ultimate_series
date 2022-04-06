/**
 * NOTE: Do checkout Alternative(quick) way to do it! - At last mentioned
 * 
 * QUESTION_OTHER_WORDS: Given set of strings, combine them in such a way that initial most string in dictionary is formed!
 * - Sorting won't help!
 * 
 * QUESTION: Given set of strings, concat them in a way, the first sorted dictionary word gets formed...
 * LOGIC: If you try sorting, that won't help as it will just sort lexicographically
 * - So, we need to do somthing else
 * - In merge sort, we take 2 items at a time and see which will come first always
 * 
 * - So, what if we take 2 string and check (1string + 2string) > (2string) + (1string)
 * - If 1string + 2string is > that means lexicographically 2string should come first as it's smaller
 * - Hence we can modify merge sort and place the logic to first take that string which is lexicohraphically smaller
 * 
 * - Similarly the string will be checked with all other string lexicographically and at last will be sorted as required (dictionary first letter)
 * 
 * COMPLEXITY: O(NlogN) - same as Merge sort
 * 
 */ 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void mergeString(string str[], int left, int right) {
    int mid = (left+right)/2;
    int i=left, j=mid+1;
    string store[right-left+1];
    int index=0;
    while(i<j && i<=mid && j<=right) {
        if(str[i]+str[j] > str[j]+str[i]) { // LOGIC !!
            store[index] = str[j];
            j++;
        } else {
            store[index] = str[i];
            i++;
        }
        index++;
    }
    while(i<=mid) {
        store[index] = str[i];
        index++;i++;
    }
    while(j<=right) {
        store[index] = str[j];
        index++;j++;
    }

    index=left;
    for(i=0;i<right-left+1;i++) {
        str[index] = store[i];
        index++;
    }
}

void mergeSortString(string str[], int left, int right) {
    if(left>=right) return;
    int mid = (left+right)/2;
    mergeSortString(str, left, mid);
    mergeSortString(str, mid+1, right);
    mergeString(str, left, right);
}

int main() {
    string ch[] = {"c", "cb", "cba"};
    mergeSortString(ch, 0, (sizeof(ch)/sizeof(ch[0]))-1);

    for(string str: ch) {
        cout<<str;
    }
}

// ALTERNATIVE: use comparator! It does same thing we did in merge to sort it

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comparator(string s1, string s2) {
    if(s1+s2 > s2+s1) {
        return false;
    }
    return true;
}

int main() {
    vector<string> ch=  {"a", "ab", "aba"};
    sort(ch.begin(), ch.end(), comparator);
    for(string c: ch) cout<<c;
}