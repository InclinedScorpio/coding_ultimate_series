// https://leetcode.com/problems/meeting-rooms-ii/description/

struct Cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) const {
        return a.second > b.second;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> store;
        sort(intervals.begin(), intervals.end());

        int ind=0;
        int room=0;
        while(ind<intervals.size()) {
            if(store.empty() || intervals[ind][0]>=store.top().second) {
                if(store.empty()) {
                    store.push({intervals[ind][0], intervals[ind][1]});
                } else {
                    while(!store.empty() && intervals[ind][0]>=store.top().second) store.pop();
                    store.push({intervals[ind][0], intervals[ind][1]});
                }
            }else {
                store.push({intervals[ind][0], intervals[ind][1]});
            }
            room = max(room, (int)store.size());
            ind++;
        }
        return room;
    }
};

//  [[0,30],[5,10],[15,20]]

//  0 ------------------> 30
//    5-->10
//              15 ->20
           

//    5-->10 -> 1 room allocated
//    top 10
//    pop
//    15 -> 20 -> 1 room
//    0 ----> 30 icoming first <top -> push