/**
 * QUESTION:
Given a stream of characters (lowercase alphabets), find the first non-repeating character from stream. You need to tell the first non-repeating character in O(1) time at each index. If for a current index there is no such character return '0' for that particular index.

Input Format:

A String S of length N passed as a parameter to the given function.

Output Format:

Return a vector of characters of length N where V[i] character represents first non-repeating character from S[0] to S[i].

Constraints:

1<=N<=100

Expected time complexity:

O(N) where N is the total number of input characters in one testcase. (Use the property of queue)



Sample Testcase :

Input:

aabcbcd

Output:

a 0 b b c 0 d

Explanation:

At index 0, 'a' is the only character we have and hence non repeating.

At index 1, we have 2 characters till now and they are same, hence no non-repeating character.

At index 2, 'b' is the only non repeating character till now.

At index 3, 'b' and 'c' are non repeating characters, but 'b' is the FIRST non repeating character till now.

At index 4, 'c' is the only non repeating character till now.

At index 5, there is no non repeating character till now.

At index 6, 'd' is the only and first non repeating character.
**/

/**
 * LOGIC: is to use queue +  map
 * - Why?
 * - because we need to keep a note which among first needs to be picked
 * - also, if that can't be picked, which among next needs to be picked then
 * - This is clear case of queue
 * - But to check if that front in queue can be taken or not has to be done from map
 * - Hence, we use queue + map!
 * 
 * 
 * COMPLEXITY: O(N)
 */ 

#include<bits/stdc++.h>
using namespace std;

vector<char> FindFirstNonRepeatingCharacter(string S){
    queue<char> q;
    map<char, int> store;
    q.push(S[0]);
    store[S[0]]++;
    vector<char> result = {S[0]};
    for(int i=1;i<S.length();i++) {
        store[S[i]]++;
        while(!q.empty() && store[q.front()]>1) {
            q.pop();
        }
        if(store[S[i]]==1) {
            q.push(S[i]);
        }
        if(q.empty()) {
            result.push_back('0');
            continue;
        }
        result.push_back(q.front());
    }
    return result;
}
