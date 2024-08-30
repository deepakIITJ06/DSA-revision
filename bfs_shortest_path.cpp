#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// User function Template for C++
class Solution {
public:
    void bfs(int node,vector<vector<int>>& graph,vector<int>& dist) {
        dist[node] = 0;
        queue<int> q;
        q.push(node);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(auto& child: graph[cur]) {
                if(dist[child]>dist[cur]+1) {
                    dist[child]=dist[cur]+1;
                    q.push(child);
                }
            }
        }
    }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> dist(N,1e9);
        vector<vector<int>> graph(N);
        for(auto& el: edges) {
            graph[el[0]].push_back(el[1]);
            graph[el[1]].push_back(el[0]);
        }
        bfs(src,graph,dist);
        for(int i=0;i<N;i++) {
            if(dist[i]==1e9) dist[i] = -1;
        }
        return dist;
    }
};