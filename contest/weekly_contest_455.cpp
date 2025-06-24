// https://leetcode.com/contest/weekly-contest-455/problems/check-if-any-element-has-prime-frequency/

/**
 * Logic is to understand
 * 0, 1 are not prime numbers
 * 2 is the only even prime number
 * All other even numbers are not prime numbers
 * All odd numbers greater than 2 are prime numbers if they are not divisible by any odd number from 3 to sqrt(n)
 */
class Solution {
    public:
        bool isPrime(int num) {
            if(num<2) return false;
            if(num==2) return true;
            if(num%2==0) return false;
            for(int i=3;(i*i)<=num;i+=2) {
                if(num%i==0) return false;
            }
            return true;
        }    
        
        bool checkPrimeFrequency(vector<int>& nums) {
            map<int, int> freq;
            for(int num: nums) {
                freq[num]++;
            }
            vector<int> counter;
            for(auto freqItem: freq) {
                bool isTrue = isPrime(freqItem.second);
                if(isTrue) return true;
            }
            return false;
        }
    };