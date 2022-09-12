// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1/#

/**
 * LOGIC: Things to understand
 * 1) Minimum spanning tree - V vertices,V-1 edges, sum of min edges
 * 2) Keep picking minimum edges, but cycle may form
 * 3) To avoid cycle make use of Disjoint sets
 * 4) Rank and compression is optimized way of disjoint set O(4Alpha) ~ O(4)
 * 
 * 
 * COMPLEXITY: O(NlogN) - cause of sorting
 * 
 */ 
class Solution {
	public:
	
	int parentOf(vector<int>& parent, int node) {
	    if(parent[node]==-1) return node;
	    return parent[node] = parentOf(parent, parent[node]); //optimizing!
	}
	
	void nodeUnion(vector<int>& parent, vector<int>& rank, int first, int second) {
	    int parentOfFirst = parentOf(parent, first);
	    int parentOfSecond = parentOf(parent, second);
	    if(parentOfFirst == parentOfSecond) return;

	    if(rank[parentOfFirst]<rank[parentOfSecond]) {
	        parent[parentOfFirst] = parentOfSecond;
	    } else if(rank[parentOfFirst]>rank[parentOfSecond]) {
	        parent[parentOfSecond] = parentOfFirst;
	    } else {
	        parent[parentOfFirst] = parentOfSecond;
	        rank[parentOfSecond]++;
	    }
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> maxHeap;
        vector<int> isChoosen(V+1, 0);
        for(int ind=0;ind<V;ind++) {
            for(vector<int> i: adj[ind]) {
                maxHeap.push({i[1], {ind, i[0]}});
            }
        }
        
        vector<int> parent(V, -1);
        vector<int> rank(V, 0);
        
        int edgesRequired = V-1;
        int sum=0;
        while(edgesRequired) {
            pair<int, pair<int, int>> top = maxHeap.top();
            maxHeap.pop();
            if(parentOf(parent, top.second.first)==parentOf(parent, top.second.second)) continue;
            nodeUnion(parent, rank, top.second.first, top.second.second);
            sum+=top.first;
            edgesRequired--;
        }
        return sum;
    }
};