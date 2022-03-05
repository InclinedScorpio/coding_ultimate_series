// https://binarysearch.com/problems/Run-Length-Decoded-String-Iterator

/**
 * LOGIC: 2 vectors can be used to keep num and it's adjacent char!
 * - Map can't be used as sequence of char occuring is important also, char can repeat- so can't use map
 * 
 */ 
class RunLengthDecodedIterator {
    private:
    vector<char> myChar;
    vector<long long int> times;
    int currIndex=0;
    public:
    RunLengthDecodedIterator(string s) {
        for(int i=0;i<s.length();i++) {
            string str = "";
            long long int num=0;
            while(s[i]>='0' and s[i]<='9') {
                num = (num*10) + (s[i] - '0');
                i++;
            }
            myChar.push_back(s[i]);
            times.push_back(num);
        }
    }

    string next() {
        long long int currCount = this->times[this->currIndex];
        char strToReturn = myChar[this->currIndex];
        this->times[currIndex]-=1;
        currCount--;
        if(currCount<=0) {
            this->currIndex++;
        }
        string str = "";
        str = str + strToReturn;
        return str;
    }

    bool hasnext() {
        if(this->currIndex<this->myChar.size()) return true;
        return false;
    }
};