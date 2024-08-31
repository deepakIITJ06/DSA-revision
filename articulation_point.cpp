#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
int mod = 1e9+7;

// 🔴🔴🔴🔴🔴🔴🔴 LOGIC 🔴🔴🔴🔴🔴🔴🔴
// simply time of reaching store kr rahein hein --> along with ki minimum time kya ho sakta hai apart from parent
// apart from "PARENT node and VISITED node" agar koi node hai dfs me then uske minimum time se compare kr lein and visited node se compare krte time ham "bridge" ki tarah "minTime" se compare nahi kr sakte , we can only compare with time[child] --> jo ki visited hai
// then after coming back to that node --> check ki is node tak aane tak ka time se < (large) to nahin iske child tak aane ka time if "YES" --> that means ki wo ek bridge hai


class Solution {
public:
    vector<int> vis;
    vector<int> time;
    vector<int> lowest;
    int timer = 0;
    vector<int> mark;
    void dfs(int node,int parent,vector<int> adj[]) {
        vis[node] = 1;
        time[node] = lowest[node] = timer;
        timer++;
        int cntChild = 0;
        for(auto &child: adj[node]) {
            if(child==parent) continue;
            if(!vis[child]) {
                dfs(child,node,adj);
                lowest[node] = min(lowest[node],lowest[child]);
                // here keep an eye on equality
                if(lowest[child]>=time[node] && parent!=-1) {
                    mark[node] = 1;
                }
                cntChild++;
            }else {
                // you can only update the lowest from time[child] --> not from lowest[child] (for visited childs)
                lowest[node] = min(lowest[node],time[child]);
            }
        }
        // for head node --> jiska parent -1 hai
        if(cntChild>1 && parent==-1) {
            mark[node] = 1;
        }
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vis.assign(n,0);
        mark.assign(n,0);
        time.resize(n);
        lowest.resize(n);
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                dfs(i,-1,adj);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(mark[i]) {
                ans.push_back(i);
            }
        }
        if(!ans.size()) return {-1};
        return ans;
    }
};