#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topo;
	void bfs(vector<int> adj[],queue<int>& q,vector<int>& indeg) {
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            topo.push_back(cur);
            for(auto& child: adj[cur]) {
                indeg[child]--;
                if(indeg[child]==0) {
                    q.push(child);
                }
            }
        }
        
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
        vector<int> indeg(V,0);
        for(int i=0;i<V;i++) {
            auto el = adj[i];
            for(auto& child: el) {
                indeg[child]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++) {
            if(indeg[i]==0) {
                q.push(i);
            }
        }
        bfs(adj,q,indeg);
        return topo;
	}
};