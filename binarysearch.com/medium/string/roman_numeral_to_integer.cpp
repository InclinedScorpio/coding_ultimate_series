// https://binarysearch.com/problems/Roman-Numeral-to-Integer

/**
 * LOGIC: Basic logic building 
 * 
 * 
 */ 
int solve(string numeral) {

    int result=0;
    for(int i=0;i<numeral.size();i++) {
        if(i!=numeral.size()-1) { // not last
            if(numeral[i]=='I' && numeral[i+1]=='V') {
                result+=4;
                i++; 
                continue;
            }
            if(numeral[i]=='I' && numeral[i+1]=='X') {
                result+=9;
                i++;
                continue;
            }
            if(numeral[i]=='X' && numeral[i+1]=='L') {
                result+=40;
                i++; 
                continue;
            }
            if(numeral[i]=='X' && numeral[i+1]=='C') {
                result+=90;
                i++;
                continue;
            }
            if(numeral[i]=='C' && numeral[i+1]=='D') {
                result+=400;
                i++;
                continue;
            }
            if(numeral[i]=='C' && numeral[i+1]=='M') {
                result+=900;
                i++;
                continue;
            }
        }
        if(numeral[i]=='I') {
            result+=1;
            continue;
        }
        if(numeral[i]=='V') {
            result+=5;
            continue;
        }
        if(numeral[i]=='X') {
            result+=10;
            continue;
        }
        if(numeral[i]=='L') {
            result+=50;
            continue;
        }
        if(numeral[i]=='C') {
            result+=100;
            continue;
        }
        if(numeral[i]=='D') {
            result+=500;
            continue;
        }
        if(numeral[i]=='M') {
            result+=1000;
            continue;
        }
    }

    return result;
}