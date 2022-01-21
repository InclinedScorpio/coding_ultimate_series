// https://leetcode.com/problems/reverse-bits/

/**
 * LOGIC: uinit32_t means its a int which is 32 bits!
 * Even if it's 1 => that means it's -> 000000000000....<31>...1 
 * 
 * THEORY:
 * unint32_t is a type def of unsigned int
 * "typedef" used when alias to a data type is required
 * - typedef unsigned int unint32_t 
 * 
 */ 
class Solution {
public:
    vector<int> createBinary(uint32_t n) {
        vector<int> bin;
        for(int i=0;i<32;i++){
            bin.push_back(n%2);
            n=floor(n/2);    
        }
        return bin;
    }
    
    uint32_t createDigitFromBinary(vector<int>& n) {
        uint32_t sum=0;
        int power = 0;
        for(int i=31;i>=0;i--) {
            sum = sum + (pow(2, power++) * n[i]);
        }
        return sum;
    }
    
    uint32_t reverseBits(uint32_t n) {
        cout<<n;
        vector<int> binary = this->createBinary(n);
        for(auto i:binary) {
            cout<<i;
        }
        return this->createDigitFromBinary(binary);
    }
};