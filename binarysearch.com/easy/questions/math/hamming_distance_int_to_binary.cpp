// https://binarysearch.com/problems/Hamming-Distance

int solve(int x, int y) {
    // char first[1000], second[1000];
    string first = bitset<32>(x).to_string();
    string second = bitset<32>(y).to_string();

    int count=0;
    for(int i=0;i<min(first.length(), second.length());i++) {
        if(first[i]!=second[i]) count++;
    }  
    return count;
}