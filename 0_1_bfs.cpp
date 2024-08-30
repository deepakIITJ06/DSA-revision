#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

class Solution {
public:
  // 0 - 1 bfs
    vector<int> dist;
    vector<int> vis;
    void bfs(int node,vector<vector<pair<int,int>>>& graph) {
        dist[node] = 0;
        deque<int> dq;
        dq.push_front(node);
        while(!dq.empty()) {
            auto cur = dq.front();
            dq.pop_front();
            if(vis[cur]) continue;
            vis[cur] = 1;
            for(auto& child: graph[node]) {
                if(dist[child.first]>dist[cur]+child.second) {
                    dist[child.first]=dist[cur]+child.second;
                    if(child.second==0) {
                        dq.push_front(child.first);
                    }else {
                        dq.push_back(child.first);
                    }
                }
            }
        }
    }
    int minCost(int n) {
        dist.assign(n,1e9);
        vector<vector<pair<int,int>>> graph;
        vis.assign(n,0);
        bfs(0,graph);
    }
};