// https://github.com/InclinedScorpio?tab=overview&from=2022-01-01&to=2022-01-05s

/**
 * TIME TAKING FOR ME
 * 1. Don't implement long long int! - Waste of time
 * 2. Implement using string itself 
 * 
 */ 

class Solution {
public:
    string carry = "0";
    
    string addCarryWithBinary(string a, string b, string c) {
        if(a=="0" && b=="0" && c=="0") {
            return "0";
        }
        else if(
            (a=="1" && b=="0" &&c=="0")
            || (a=="0" && b=="1" &&c=="0")
            ||  (a=="0" && b=="0" &&c=="1")
        ) {
            return "1";
        }
        else if(
            (a=="1" && b=="1" &&c=="0")
            || (a=="0" && b=="1" &&c=="1")
            ||  (a=="1" && b=="0" &&c=="1")
        ) {
            this->carry="1";
            return "0";
        }else {
            this->carry="1";
            return "1";
        }
    }

    
    string addSingleBinary(string a, string b) {
        if(a=="1" && b == "1") {
            this->carry = "1";
            return "0";
        }
        else if( (a=="1" && b=="0") || (a=="0" && b=="1") ) {
            return "1";
        }
        else {
            return "0";
        }
    }
    
    string addBinary(string a, string b) {
        int indexA = a.length()-1;
        int indexB = b.length()-1;
        string result = "";
        while(indexA>=0 && indexB>=0) {

            //logic
            string binaryA;
            string binaryB;
            binaryA.push_back(a[indexA--]);
            binaryB.push_back(b[indexB--]);
            string additionValue;
            if(this->carry=="1") {
                this->carry ="0";
                additionValue = addCarryWithBinary(binaryA, binaryB, "1");                
            }else {
                 additionValue = addSingleBinary(binaryA, binaryB);    
            }

            result = additionValue+ result;
        }
        // one of them maybe present
        while(indexA>=0) {
            if(this->carry == "1") {
                this->carry = "0";
                
                string binaryA;
                binaryA.push_back(a[indexA--]);

                string additionValue = addSingleBinary(binaryA, "1");
                result = additionValue+ result;
            }else {
                string binaryA;
                binaryA.push_back(a[indexA--]);
                // string additionValue = addSingleBinary(binaryA, "1");
                result = binaryA+ result;
            }
        }
        
        while(indexB>=0) {
            if(this->carry == "1") {
                this->carry = "0";
                
                string binaryB;
                binaryB.push_back(b[indexB--]);

                string additionValue = addSingleBinary(binaryB, "1");
                result = additionValue + result;
            }else {
                string binaryB;
                binaryB.push_back(b[indexB--]);
                // string additionValue = addSingleBinary(binaryB, "1");
                result = binaryB + result;
            }
        }
        
        if(this->carry == "1") {
            result = "1" + result ;
        }
        return result;
    }
};