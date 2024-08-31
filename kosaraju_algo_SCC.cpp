#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define int long long
int mod = 1e9+7;

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	vector<int> vis;
	vector<int> finish;
	void dfs(int node,vector<vector<int>> &graph) {
        vis[node] = 1;
        for(auto& child: graph[node]) {
            if(!vis[child]) {
                dfs(child,graph);
            }
        }
        finish.push_back(node);
	}

    // 🔴🔴🔴🔴🔴🔴🔴 LOGIC 🔴🔴🔴🔴🔴🔴🔴
    // sort all the edges a/c to finishing time (using DFS)
    // reverse all the edges
    // apply DFS again

    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // sort all the edges as per the finishing time
        vis.assign(V,0);
        finish.resize(V);
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                dfs(i,adj);
            }
        }
        // reverse the graph
        vector<vector<int>> reversedGraph(V);
        for(int i=0;i<V;i++) {
            for(auto &el: adj[i]) {
                reversedGraph[el].push_back(i);
            }
        }
        int scc = 0;
        // again apply DFS
        vis.assign(V,0);
        while(finish.size()) {
            if(!vis[finish.back()]) {
                scc++;
                dfs(finish.back(),reversedGraph);
            }
            finish.pop_back();
        }
        return scc;
    }
};