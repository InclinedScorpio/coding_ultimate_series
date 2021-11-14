#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout<<"hello"<<endl;
    vector<int> alpha;
    alpha.push_back(1);
    cout<< alpha.capacity();
    alpha.push_back(2);
    cout<< alpha.capacity();
}