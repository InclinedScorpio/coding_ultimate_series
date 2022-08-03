// https://leetcode.com/problems/my-calendar-i/

/**
 * LOGIC: No need of using sorting here, just think the basic thing
 * - Don't jump to advance level initially
 * - Here, simple checking with all the intervals worked fine
 *  
 */ 
class MyCalendar {
public:
    vector<pair<int, int>> store;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for(pair<int, int>s: store) {
            if((s.first>start && s.first<end) || 
              (s.first<=start && start<s.second)) {
                return false;
            }
        }
        store.push_back({start, end});
        return true;
    }
};