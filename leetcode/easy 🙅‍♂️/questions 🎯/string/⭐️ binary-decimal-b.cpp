// https://github.com/InclinedScorpio?tab=overview&from=2022-01-01&to=2022-01-05s

// not working- WIP

class Solution {
public:
    int changeBinaryToInt(string binaryString) {
        // int binary = stoi(binaryString);
        long long int sum = 0;
        long long int index = 0;
        
        for(long long int i=binaryString.length()-1;i>=0;i--) {
            long long int myV = binaryString[i] - '0';
            sum+= myV*pow(2,index++);
        }
        cout<<"For "<<binaryString<<" Value-- "<<sum<<endl;
        return sum;
    }
    
    string changeIntegerToBinary(long long int decimal) {
        long long int aa = decimal;
        string myValue = "";
        
        while(decimal>0) {
            long long int num = decimal%2;
            myValue = to_string(num) + myValue;
            decimal = decimal/2;
        }
        if(myValue=="") {
            return "0";
        }
        cout<<" FOOO "<<aa<<" Value-- "<<myValue<<endl;
        return myValue;
    }
    
    
    string addBinary(string a, string b) {
        return this->changeIntegerToBinary(
            this->changeBinaryToInt(a) + this->changeBinaryToInt(b) 
        );
    }
};