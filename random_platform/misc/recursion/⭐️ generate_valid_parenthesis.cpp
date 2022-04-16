/**
 * QUESTION: Generate valid parenthesis
 * - () is valid )( is invalid
 * 
 * LOGIC: At each position we have 2 different choices
 * - We will make both choices and will keep checking the condition...
 * - So in invalid case we can just return back
 * - It's a clear case of recursion!
 * 
 * COMPLEXITY: O(2^N)
 * 
 */ 

#include <iostream>
#include <vector>
using namespace std;

void generateAllValidParenthesis(int currOpened, int currClosed, string currParenthesis) {
    if(currOpened==-1 || currOpened>currClosed) {
        return;
    }
    if(currOpened==0 && currClosed==0) {
        cout<<currParenthesis<<endl;
        return;
    }
    generateAllValidParenthesis(currOpened-1, currClosed, currParenthesis+"(");
    generateAllValidParenthesis(currOpened, currClosed-1, currParenthesis+")");
}

int main() {
    int parenthesis=5;
    generateAllValidParenthesis(parenthesis, parenthesis, "");
}