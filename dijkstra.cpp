#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> vis,dist;
    void dijk(int node,vector<vector<pair<int,int>>>& graph) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[node] = 0;
        pq.push({dist[node],node});
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if(vis[cur.second]) continue;
            vis[cur.second] = 1; // visited array is must here in the dijkstra algorithm
            for(auto& child: graph[cur.second]) {
                if(dist[child.first]>cur.first+child.second) {
                    dist[child.first]=cur.first+child.second;
                    pq.push({dist[child.first],child.first});
                }
            }
        }
    }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<vector<pair<int,int>>> graph(V);
        for(int i=0;i<V;i++) {
            for(auto& el: adj[i]) {
                graph[i].push_back({el[0],el[1]});
                graph[el[0]].push_back({i,el[1]});
            }
        }
        vis.assign(V,0);
        dist.assign(V,1e9);
        dijk(S,graph);
        return dist;
    }
};