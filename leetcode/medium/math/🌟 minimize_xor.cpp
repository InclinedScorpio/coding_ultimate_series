// https://leetcode.com/submissions/detail/813424088/


/**
 * LOGIC: Question is easy, don't get initimidated by math terms!
 * 
 */ 
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        int noOfBits = 0;
        int copyNum2=num2;
        while(num2>0) {
            int bit = num2%2;
            if(bit) noOfBits++;
            num2 = num2/2;
        }
        num2 = copyNum2;
        
        // make string of num1 and count 1
        int countBits=0;
        string str="";
        while(num1>0) {
            int bit = num1%2;
            if(bit) {
                countBits++;
                str="1"+str;
            } else {
                str="0"+str;
            }
            num1 = num1/2;
        }
                
        if(countBits<=noOfBits) {
            // need more 1
            int moreBitWanted = noOfBits - countBits;
            for(int i=str.length()-1;i>=0&&moreBitWanted;i--) {
                if(str[i]=='0') {
                    str[i] = '1';
                    moreBitWanted--;
                }
            }
            if(moreBitWanted) { // if more bits wanted
                while(moreBitWanted--) {
                    str="1"+str;
                }
            }
        } else {
            for(int i=0;i<str.length();i++) {

                if(noOfBits<=0) {
                    str[i]='0';
                }
                if(str[i]=='1') noOfBits--;
            }
        }

        
        int integer = 0;
        int power = 0;
        for(int i=str.length()-1;i>=0;i--) {
            if(str[i]=='1')
                integer+=pow(2, power);
            power++;
        }
        
        return integer;
    }
};


    
