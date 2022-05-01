/**
 * QUESTION: Find number of rectanges(parallel to both axis) which can be formed
 * 
 * LOGIC: Take 2-2 points and consider them as the diagonal points
 * - And see if other two points exists.
 * 
 * Q) What are the other two points?
 * A) One of the other will be on one's X & other's Y
 * - And other will be on one's Y and other's X
 * (As rectangle sides needs to be parallel to sides of rectangle)
 * 
 * COMPLEXITY: O(N^2logN)
 * 
 * - Although we could have run 4 loops and checked if other 2 exists 
 * - But checking these other 2 can be done in less time by using set
 * 
 */ 

#include<iostream>
#include<map>
#include<vector>
#include<set>

using namespace std;

class Points {
    public:
        int x, y;
        Points(int x, int y){
            this->x = x;
            this->y = y;
        }

};

// Class is required to compare user defined class objects in set
class Compare {
    public:
        bool operator()(const Points a, const Points b) {
            if(a.x==b.x) {
                return a.y<b.y;
            }
            return a.x<b.x;
        }
};

int countRectanglesParallelToAxis(vector<Points> arr) {
    int rectangles=0;
    set<Points, Compare> store;
    for(Points point: arr) store.insert(point);
    for(int i=0;i<arr.size()-1;i++) {
        for(int j=i+1;j<arr.size();j++) {
            if(arr[i].x==arr[j].x || arr[i].y==arr[j].y 
            || arr[i].x==arr[j].x || arr[i].y==arr[j].y) {
                continue; // we need to pick diagonal points
            }
            // Derive the other 2 points
            Points otherFirst(arr[i].x, arr[j].y);
            Points otherSecond(arr[j].x, arr[i].y);
            if(store.find(otherFirst)!=store.end() && store.find(otherSecond)!=store.end()) {
                rectangles++;
            }
        }
    }
    return rectangles/2; // because rectangles will be counted 2 times
}

int main() {
    Points p1(0,0);
    Points p2(0,1);
    Points p3(1,1);
    Points p4(1,0);
    Points p5(2,1);
    Points p6(2,0);
    Points p7(3,1);
    Points p8(3,0);
    vector<Points> arr = {p1, p2, p3, p4, p5, p6, p7, p8};
    cout<<countRectanglesParallelToAxis(arr);
}