/**
 * QUESTION: Find all string combination possible on keys click
 * 
 * LOGIC: As with each click, predefined ways are possible 
 * - Like on pressing 2 we know- "ABC" 1 among these 3 would be possible
 * - So, we can use Recusion to find all possible solutions
 * 
 */ 

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void generateAllPossibleKeypadCombination(map<char, string> keypad, string nums, string result, int index=0) {
    if(index>=nums.length()) {
        cout<<result<<" ";
        return;
    }
    string currStr = keypad[nums[index]];
    for(int i=0;i<currStr.length();i++) {
        generateAllPossibleKeypadCombination(keypad, nums, result+currStr[i], index+1);
    }
}

int main() {
    string keysPressed="23";
    map<char, string> keypad = {
        {'1', ""},
        {'2', "ABC"},
        {'3', "DEF"},
        {'4', "GHI"},
        {'5', "JKL"}, 
        {'6', "MNO"},
        {'7', "PQRS"},
        {'8', "TUV"},
        {'9', "WXYZ"},
    };
    generateAllPossibleKeypadCombination(keypad, keysPressed, "");
}