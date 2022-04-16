/**
 * QUESTION: Find all possible permutation
 * 
 * LOGIC: If we see we basically need to swap elements and can get the required answer
 * - So in abc - we will get abc & if we swap b and c  & will get acb
 * - Now we would swap b with a, bac - print bac and then check a, c and swap - bca
 * 
 * - But while returning make sure to BACKTRACK! Means as string is swapped, turn it back to how it was
 * - This part is important as without backtracking it won't give correct result! 
 * 
 * - Here we don't require backtracking as params passed by value
 * - In case of pass by reference we do need to backtrack!
 * 
 * 
 */ 
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

void findPermutations(string str, set<string>& store, int index=0) {
    if(index>=str.length()) {
        store.insert(str);
        return;
    }    
    // string strCopy = str; // Use in case of backtracking

    for(int i=index;i<str.length();i++) {
        swap(str[i], str[index]);
        findPermutations(str, store, index+1);
        // str=strCopy;
    }
}

int main() {
    string str = "abc";
    set<string> store;
    findPermutations(str, store, 0);
    for(auto i=store.begin();i!=store.end();i++) {
        cout<<*i<<endl;
    }
}