//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define int long long

// } Driver Code Ends
class Solution {
    public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int node,vector<int>& vis,vector<int> adj[],vector<int>& ans) {
        queue<int> q;
        q.push(node);
        while(!q.empty()) {
            int cur = q.front();
            vis[cur] = 1;
            q.pop();
            ans.push_back(cur);
            for(auto& child: adj[cur]) {
                if(!vis[child]) {
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vector<int> ans;
        bfs(0,vis,adj,ans);

        // 👇🏻👇🏻👇🏻 IF GRAPH is DIS-CONNECTED

        // for(int i=0;i<V;i++) {
        //     if(!vis[i]) {
        //         bfs(i,vis,adj,ans);
        //     }
        // }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends