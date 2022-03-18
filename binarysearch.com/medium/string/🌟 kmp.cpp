// https://binarysearch.com/problems/Rotation-of-Another-String

/**
 * LOGIC: Knuth Morris Pratt Algorithm: Used for matching string inside some text
 * WORKING:
 * - Create a piTable which will store the prefix occurances in pattern string
 * - How does prefix occurance work?
 * 1. It will check whereall the suffix, part of suffix is getting repeated
 * 2. So that while searching if next character is not equal to char in text to be searched...
 * 3. Rather than going to index 0 of pattern, we can rather check the sequence which has already occured before
 * 4. It's more clear on scratch paper - so try it
 * 
 * - Once PiTable is created
 * 1. Now take the text string and start searching
 * 2. While searching if next char is not eq to char in pattern...
 * 3. Rather than going to 0 of pattern, we will check if that part is already occured before in the pattern anywhere
 * 4. If yes, compare that char which occured before (use piTable to go to that index)
 * 5. If no, then just go back to 0th index of pattern
 * 
 * USE: In naive´algo, we simply go bck to 0th index of pattern and i+1 of text string which results in O(M*N)
 * - where M -> string length of text, N-> string length of pattern
 * 
 * KMP: Preparing PiTable takes O(M) + searching takes O(N) -> O(M+N) - linear time complexity
 * 
 * COMPLEXITY: O(M+N)
 * 
 */ 
bool solve(string s0, string s1) {
    int strLen=s0.length();
    if(strLen!=s1.length()) return false;

    vector<int> piTable(strLen, 0);
    
    int left=0,right=1;
    piTable[0]=0;

    while(right<strLen) { //creating KMP Pi Table O(N)
        if(s1[right] == s1[left]) {
            piTable[right]=left+1;
            left++;
            right++;
        } else {
            while(left!=0 && s1[left]!=s1[right]) {
                left = piTable[left-1];
            }
            if(left==0 && s1[left]==s1[right]) {
                piTable[right]=1;
                right++;
                left++;
            }
            if(left==0 && s1[left]!=s1[right]) {
                piTable[right]=0;
                right++;
            }
        }
    }

    // PiTable prepared, start comparing s0,s1 using piTable
    s0 = s0+s0; // As per question this line is the logic, as string is rotated, not a part of KMP
    
    int piIndex=0;
    for(int i=0;i<strLen+strLen;i++) { // O(N)
        if(s0[i]==s1[piIndex]) {
            piIndex++;
        }else {
            while(piIndex!=0 && s0[i]!=s1[piIndex]) {
                piIndex=piTable[piIndex-1];
            }            
            if(piIndex==0 && s0[i]==s1[piIndex]) {
                piIndex++;
            }else if(piIndex!=0) {
                piIndex++;
            }
        }
        if(piIndex==strLen) return true;
    }
    
    return false; //pattern not found
}