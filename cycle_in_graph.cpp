#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool iscycle = false;
    vector<int> par;
    vector<int> col;
    // Function to detect cycle in an undirected graph.
    void cycle(int node,int parent,vector<int> adj[]) {
        par[node] = parent;
        col[node] = 2;
        for(auto& child: adj[node]) {
            if(child==par[node]) continue; // => COMMENT THIS LINE FOR DIRECTED GRAPH
            if(col[child]==1) {
                cycle(child,node,adj);
            }else if(col[child]==2) {
                iscycle = true;
            }else {
                // do nothing
            }
        }
        col[node] = 3;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        par.resize(V);
        col.assign(V,1);
        for(int i=0;i<V;i++) {
            if(col[i]==1) {
                cycle(i,-1,adj);
            }
            if(iscycle) {
                return true;
            }
        }
        return false;
    }
};