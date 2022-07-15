// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1/#

/**
 * LOGIC: First thing to understand is what is Minimum spanning Tree
 * - Second thing is the Prims Algorithm
 * 
 * Prims Algo says that to find a min spanning tree
 * - Pick the min edge and go through it, now at new node, again see what all edges are present
 * - Now among both the nodes, check which is minimum edge wt. and push it (Make sure not to push visited node's edge)
 * - At last all node will be covered. Just by taking minimum edges each time.
 * 
 * NOTE: To keep the bucket of edges, use min Heap! as it will only take O(logN) for all operations
 * 
 * COMPLEXITY: O(NlogN)
 * 
 */ 
class Solution {
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPq;
        vector<bool> visited(V, false);
        minPq.push({0, 0});
        int sum=0;
        while(!minPq.empty()) {
            pair<int,int> front = minPq.top();
            if(visited[front.second]) {
                minPq.pop(); continue;
            }
            sum+=front.first;
            visited[front.second]=1;
            minPq.pop();
            for(vector<int> nodes: adj[front.second]) {
                if(visited[nodes[0]]) continue;
                // not visited
                minPq.push({nodes[1], nodes[0]});
            }
        }
        return sum;
    }
};