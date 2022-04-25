/**
 * LOGIC: Both greater<int> or own Class can be used as a comparator
 * priority_queue is Max heap by default
 * 
 * Can be changed to min heap while declaration
 * priority_queue<int, vector<int>, greater<int>> store;
 * OR - if using own comparator
 * priority_queue<int, vector<int>, Comparator_Class> store;
 * 
 * COMPLEXITY:O(NlogN)
 */ 


#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class Comparator {
    public:
        bool operator()(int a, int b) { // operator overloading
            return a>b;
        }
};

int main() {
    // priority_queue<int, vector<int>, greater<int>> heap;
    priority_queue<int, vector<int>, Comparator> heap;
    vector<int> vec={23,56,32,1,66,86,35,56};

    for(int i: vec) {
        heap.push(i);
    }

    while(!heap.empty()) {
        cout<<heap.top()<<" ";
        heap.pop();
    }
}


