#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// using DFS 

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> vis;
	vector<int> topo;
	void dfs(int node,vector<int> adj[]) {
        vis[node] = 1;
        for(auto& child: adj[node]) {
            if(!vis[child]) {
                dfs(child,adj);
            }
        }
        topo.push_back(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
        vis.assign(V,0);
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                dfs(i,adj);
            }
        }
        reverse(begin(topo),end(topo));
        return topo;
	}
};