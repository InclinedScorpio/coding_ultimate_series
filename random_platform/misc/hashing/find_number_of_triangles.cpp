/**
 * QUESTION: We are given points on X-Y plane
 * - Find right angled triangle parallel to either axis
 * 
 * LOGIC: Think the basic first
 * - We would like to run 3 loops to get the 3 points
 * - And checking if 2 of them lye on the line & one of them lye perpendicular to either of them
 * COMPLEXITY: O(N^3)
 * 
 * OPTIMISATION:
 * - Now the part where we check if perpencidular lye to either side of the base can be optimised
 * - How?
 * - We can keep track of the points lying on axis & at right time can make use of them to check if any point lie where required
 * - Make use of unordered map as it uses hashing - O(1) 
 * 
 * COMPLEXITY: O(N^2) 
 * 
 */ 

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Points {
    public:
        int x, y;
        Points(int x, int y){
            this->x = x;
            this->y = y;
        }
};

int countRightTrianglesParallelToAxis(vector<Points> arr) {
    unordered_map<int, int> countX;
    unordered_map<int, int> countY;
    for(int i=0;i<arr.size();i++) {
        countX[arr[i].x]++;
        countY[arr[i].y]++;
    }

    int triangles=0;

    for(int i=0;i<arr.size()-1;i++) {
        for(int j=i+1;j<arr.size();j++) {
            if(arr[i].x==arr[j].x) {
                if(countY.count(arr[i].y)) {
                    triangles+=countX[arr[i].y];
                    triangles--;
                }
                if(countY.count(arr[j].y)) {
                    triangles+=countX[arr[j].y];
                    triangles--;
                }
            }
            if(arr[i].y==arr[j].y) {
                if(countX.count(arr[i].x)) {
                    triangles+=countX[arr[i].x];
                    triangles--;
                }
                if(countX.count(arr[j].x)) {
                    triangles+=countX[arr[j].x];
                    triangles--;
                }
            }
        }
    }
    return triangles;
}

int main() {
    Points p1(1, 2);
    Points p2(2, 0);
    Points p3(2, 2);
    Points p4(2, 3);
    Points p5(4, 2);
    vector<Points> arr = {p1, p2, p3, p4, p5};
    cout<<countRightTrianglesParallelToAxis(arr);
}
