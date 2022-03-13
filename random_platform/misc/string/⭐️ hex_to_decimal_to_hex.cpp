#include <iostream>
#include <string.h>
#include <sstream>
#include<bitset>

using namespace std;

string decimalToHexa(string str) {
    int decimal = stoi(str);
    stringstream sso;
    sso<<hex<<decimal; // point to note, give it to sso with hex
    return sso.str(); // sso item can be returned as str()
}

string hexaToDecimal(string str) {
    stringstream sso;
    int value;
    sso<<hex<<str; // important to put hex
    sso>>value; // it will change it to int
    return to_string(value);

}

int main() {
    string num = "9";
    string hexaNum = decimalToHexa(num);
    cout<<hexaNum<<endl;
    cout<<hexaToDecimal(hexaNum);
}
