#include <iostream>
#include <vector>
using namespace std;

/**
 * QUESTION: Find all possible palindrome substring in given string
 * LOGIC: Main logic is: X_____X will be palindrome only if...
 * - first and last are equal - X
 * - and stuff in btw X, X is also palindome...
 * So,
 * - If using DP we can know about ___ then it will be easy
 * - So using 2D Matrix we can
 * - Diagonal will be representing 1 char which is palindrome only
 * - Rest we keep moving up the diagonal and implementing the main logic
 * - Remember, for 2 char - we can directly check it as __ part is not there
 * - For anything above 2 char, we can implement main logic of X___X
 * - ___ part will be already calculated at (i+1, j-1)
 * 
 * COMPLEXITY: O(N)
 */ 
int main() {
    string str = "sdkfjlkjkkskskjsdfjsldkflskdjf";
    // str: string to find no. of Palindromes in

    vector<vector<bool>> store(str.length(), vector<bool>(str.length()));
    
    int count=0;
    int incBy=0;
    for(int outer=0;outer<store.size();outer++) {//i
        for(int i=0;i<store.size()-outer;i++) {  
            int j = i+outer; //gap
            if(i>j) continue;
            if(i==j)  {
                store[i][j]=true;
                count++;
            } else if(j==i+1) {
                if(str[i]==str[i+1]) {
                    store[i][j]=true;
                    count++;
                }
            } else {
                if(str[i]==str[j] && store[i+1][j-1]) {
                    store[i][j]=true;
                    count++;
                }
            }
        }
    }
    cout<<"No. of palindromes: "<<count;
}