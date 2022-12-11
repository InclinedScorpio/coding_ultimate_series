// https://leetcode.com/problems/my-calendar-iii/description/


/**
 * LOGIC: Important to understand the starting and ending point of inteval is important
 * - As counting the initial points we can come to know what's the max overlapping values
 * - We can simply use a map and keep count of starting and ending
 * - Important to try in scratch once
 */ 
class MyCalendarThree {
public:
    map<int, int> store;

    MyCalendarThree() {
    }
    
    int book(int startTime, int endTime) {
        this->store[startTime] += 1;
        this->store[endTime] += -1;

        int maxVal = 0;
        int currTotal=0;
        for(auto s: store) {
            currTotal+=s.second;
            if(currTotal>maxVal) {
                maxVal = currTotal;
            }
        }
        return maxVal;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */