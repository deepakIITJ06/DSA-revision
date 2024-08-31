#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define int long long
int mod = 1e9+7;

// 🔴🔴🔴🔴🔴🔴🔴 LOGIC 🔴🔴🔴🔴🔴🔴🔴
// simply time of reaching store kr rahein hein along with ki minimum time kya ho sakta hai apart from parent
// apart from parent agar koi node visited bhi hai dfs me then uske minimum time se compare kr lein
// then after coming back to that node --> check ki is node tak aane tak ka time se < (large) to nahin iske child tak aane ka time if "YES" --> that means ki wo ek bridge hai

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vis;
    vector<int> time;
    vector<int> lowestTime;
    int timer = 0;
    void dfs(int node,int parent,vector<vector<int>> &graph) {
        vis[node] = 1;
        time[node] = lowestTime[node] = timer;
        timer++;
        for(auto &child: graph[node]) {
            if(child==parent) continue;
            if(!vis[child]) {
                dfs(child,node,graph);
                // when you came back to the initial node
                // update the minimum time
                lowestTime[node] = min(lowestTime[node],lowestTime[child]);
                if(time[node]<lowestTime[child]) {
                    ans.push_back({node,child});
                }
            }else {
                // if visited then simply update the minimum time
                lowestTime[node] = min(lowestTime[node],lowestTime[child]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vis.assign(n,0);
        time.resize(n);
        lowestTime.resize(n);
        vector<vector<int>> graph(n);
        for(auto &el: connections) {
            graph[el[0]].push_back(el[1]);
            graph[el[1]].push_back(el[0]);
        }
        dfs(0,-1,graph);
        return ans;
    }
};