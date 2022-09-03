// https://leetcode.com/problems/decode-string/

/**
 * LOGIC: 1) thing is Intuition-  is to use stack
 * 2) thing is to push back the resultant after finding
 * - 2) point I couldn't understand
 */
class Solution {
public:
    string decodeString(string s) {
        stack<char> store;
        for(int i=0;i<s.length();i++) {
            char currChar = s[i];
            if(currChar!=']') {
                store.push(currChar);
            } else { //it's ]
                // firstPop the characters
                string strFormed="";
                while(store.top()!='[') {
                    strFormed=store.top() + strFormed;
                    store.pop();
                }

                // remove []
                store.pop();
                
                // now check the numbers
                int num=0;
                int pwer=0;
                while(!store.empty() && store.top()>='0' && store.top()<='9') {
                    num=(store.top()-'0') * pow(10, pwer) + num;
                    pwer++;
                    store.pop();
                }
                
                // make string
                string strCreate="";
                for(int i=0;i<num;i++) strCreate+=strFormed;
                for(int i=0;i<strCreate.length();i++) store.push(strCreate[i]);
            }
        }
        string result="";
        cout<<store.size();
        while(!store.empty()) {
            result= store.top() + result;
            store.pop();
        }
        return result;
    }
};


