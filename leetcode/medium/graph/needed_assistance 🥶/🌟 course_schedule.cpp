// https://leetcode.com/problems/course-schedule/

/**
 * GOOD QUESTION
 * LOGIC: While forming question, it's clearly a graph and a cycle it's asking for
 * - Just have to realize the above line and rest question is easy!
 */ 
class Solution {
public:
    bool helper(vector<int> adj[], vector<bool>& done, vector<bool>& isCompleted, int numCourses, int ind) {
        if(adj[ind].size()==0 || isCompleted[ind]) return true;
        done[ind]=true;
        for(int i: adj[ind]) {
            if(done[i] && !isCompleted[i])  {return false;}
            if(!helper(adj, done,isCompleted, numCourses, i)) return false;
        }
        isCompleted[ind]=true;
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        for(int i=0;i<prerequisites.size();i++) {
            if(prerequisites[i][1]==prerequisites[i][0]) return false;
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<bool> visited(numCourses, false);
        vector<bool> completed(numCourses, false);
        
        for(int i=0;i<numCourses;i++)
            if(!helper(adj, visited, completed, numCourses, i)) return false;
        
        return true;
    }
};
