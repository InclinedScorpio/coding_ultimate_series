// https://leetcode.com/problems/course-schedule/description/?utm_source=chatgpt.com

class Solution {
public:

    bool iter(unordered_map<int, unordered_set<int>> &store, unordered_map<int, int>& seen, int i) {
        if(seen[i]==1) return false;
        if(seen[i]==2)  return true;

        seen[i]=1;
        unordered_set<int> ss = store[i];
        for(int nextOne: ss) {
            if(!iter(store, seen, nextOne)) return false;
        }
        seen[i]=2;
        return true;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        //create graph

        unordered_map<int, unordered_set<int>> store;
        for(int i=0;i<prerequisites.size();i++) {
            store[prerequisites[i][1]].insert(prerequisites[i][0]);
        }

        unordered_map<int, int> seen;
        for(int i=0;i<numCourses;i++) {
            seen[i]=0;
        }

        for(int i=0;i<numCourses;i++) {
            if(!iter(store, seen, i)) return false;
        }
        return true;
    }
};

// a <- b

// no circle