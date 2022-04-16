/**
 * QUESTION: Make all possible subsequence possible of the string
 * LOGIC: Use recursion
 * - Along with string, we can similarly make all subsequence of any array as well
 * 
 */ 
#include <iostream>

using namespace std;

void findAllSubsets(string str, string currStr, int currInd=0) {
    if(currInd>=str.length()) {
            cout<<currStr<<" ";
            return;
    };
    findAllSubsets(str, currStr+str[currInd], currInd+1);
    findAllSubsets(str, currStr, currInd+1);
}

int main() {
    string str="abc";
    findAllSubsets(str, "");
}