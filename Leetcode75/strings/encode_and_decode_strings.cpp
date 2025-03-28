// https://leetcode.com/problems/encode-and-decode-strings/

/**
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

You are not allowed to solve the problem using any serialize methods (such as eval).

 

Example 1:

Input: dummy_input = ["Hello","World"]
Output: ["Hello","World"]
Explanation:
Machine 1:
Codec encoder = new Codec();
String msg = encoder.encode(strs);
Machine 1 ---msg---> Machine 2

Machine 2:
Codec decoder = new Codec();
String[] strs = decoder.decode(msg);
Example 2:

Input: dummy_input = [""]
Output: [""]
 */
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";
        for(string currStr: strs) {
            int length = currStr.length();
            result += to_string(length) + "(" + currStr + ")";
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int iter = 0;
        while(iter<s.length()) {
            string numInStr="";
            cout<<(int)s[iter]<<"| ";
            while((int)s[iter]>=48 && (int)s[iter]<=57) {
                numInStr+=s[iter];
                iter++;
            }
            int numInInt = stoi(numInStr);
            iter++; // skip '('
            string toPush="";
            for(int i=iter;i<(iter+numInInt);i++) {
                toPush+=s[i];
            }
            iter = iter+numInInt + 1; // skip ')'
            result.push_back(toPush);
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));