// https://leetcode.com/problems/multiply-strings/description/?envType=problem-list-v2&envId=plakya4j

/**
 * 
 * Problems requires understanding of how multiplication works
 * 
 *     1  2  3 
 *     4  5  6
 * --------------
 *     7  3  8   (6*123) - this is 6*3, 6*2, 6*1
 * 6  1  5     (5*123) - this is 5*3, 5*2, 5*1
 *.......
 * Now focus on where you are keeping the result
 * 6*3 is at index 0
 * 6*2 is at index 1
 * 6*1 is at index 2
 * So, 6*123 is at index 0,1,2
 * Similarly, 5*123 is at index 1,2,3
 * <IMPORTANT_PART>
 * that means we are checking both the indices of the number we are multiplying
 * and adding them to find where to put the result
 * 
 * 
 * 
 * 
 */
class Solution {
    public:
        string multiply(string num1, string num2) {
    
            vector<int> store(num1.length() + num2.length(), 0);
            int maxIndSeen=0;
    
            for(int i=num1.length()-1;i>=0;i--) {
                for(int j=num2.length()-1;j>=0;j--) {
                    int num = (num1[i] - 48) * (num2[j] - 48);
                    store[(num1.length()-i-1)+(num2.length()-j-1)] += num%10;
                    int currNum = (num1.length()-i-1)+(num2.length()-j-1);
    
    
                    store[(num1.length()-i-1)+(num2.length()-j-1) + 1] += num/10;
                }
            }
    
            // everything multiplied, now just check the vector string
            int carry=0;
            for(int i=0;i<store.size();i++) {
                int num = store[i];
                num +=carry;
                if(num>0) maxIndSeen=i;
                store[i] = num%10;
                carry = num/10;
            }
    
            // if carry is remaining, then settle that as well
            if(carry) {
                store[maxIndSeen+1]+=carry;
                maxIndSeen++;
            }
    
            string result="";
            for(int i=maxIndSeen;i>=0;i--) {
                result+=to_string(store[i]);
            }
            
            return result;
        }
    };