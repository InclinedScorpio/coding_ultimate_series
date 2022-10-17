// https://leetcode.com/problems/course-schedule-ii/

/*
 * LOGIC: Important to understand that we need indegree here to represent which ones to choose
 * - Also rather stack, we will need queue here 
 *
 *
 */

class Solution {
public:
     bool helper(int numCourses, unordered_map<int, vector<int>>& graph, queue<int>& store, int currNum, vector<int>& reached) {
            if(reached[currNum]==2) {
                return true;
            }
            if(reached[currNum]==1) {
                return false; //cycle
            };
            reached[currNum] = 1;

            for(auto g: graph[currNum]) {
                if(!helper(numCourses, graph, store, g, reached)) return false;
            }
    
            store.push(currNum);
            reached[currNum] = 2;
            return true;
        }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> reached(numCourses, 0);
        unordered_map<int, vector<int>> graph;
        
        queue<int> store;
        vector<int> indegree(numCourses, 0);
        // create graph
        for(int i=0;i<prerequisites.size();i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        
        for(int i=0;i<numCourses;i++)
            if(indegree[i]==0)
                if(!helper(numCourses, graph, store, i,reached)) return {};
        
        vector<int> result;
        while(!store.empty()) {
            result.push_back(store.front());
            store.pop();
        }
        vector<int> empty={};
        return result.size()==numCourses?result:empty;
    }
};


/// Another solution.. no need of unordered map, just use 2d vector simply

class Solution {
public:
    bool checkCycle(vector<vector<int>>& prerequisites, int ind, int courses, vector<bool>& isVisited, vector<bool>& isChecked) {
        if(isChecked[ind]==true) return false;
        if(isVisited[ind]==true) return true;
        isVisited[ind] = true;
        for(int adjNode: prerequisites[ind]) {
            if(checkCycle(prerequisites, adjNode, courses, isVisited, isChecked)) return true;
        }
        isChecked[ind] = true;
        return false;
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<bool> isChecked(numCourses,false);
        vector<vector<int>> prerequisites(numCourses);
        for(int i=0;i<pre.size();i++) {
            prerequisites[pre[i][1]].push_back(pre[i][0]);
        }
        
        for(int i=0;i<numCourses;i++) {
            vector<bool> isVisited(numCourses, false);
            if(checkCycle(prerequisites, i, numCourses, isVisited, isChecked)) {
                return {};
            }
        }

        vector<int> inDegrees(numCourses, 0);
        // finding Indegree
        for(int i=0;i<numCourses;i++) {
            for(int adjNode: prerequisites[i]) {
                inDegrees[adjNode]++;
            }
        }
        
        queue<int> store;
        for(int i=0;i<numCourses;i++) {
            if(inDegrees[i]==0) {
                store.push(i);
            }
        }

        vector<int> result;
        while(!store.empty()) {
            int node = store.front();
            result.push_back(node);
            store.pop();
            for(int adjNode: prerequisites[node]) {
                inDegrees[adjNode]--;
                if(inDegrees[adjNode]==0) {
                    store.push(adjNode);
                }
            }
        }
        return result;
    }
};