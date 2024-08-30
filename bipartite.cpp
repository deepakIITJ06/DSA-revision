#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int n;
    vector<int> vis;
    vector<int> color;
    bool isbip(int node,vector<vector<int>>& graph){
        vis[node] = 1;
        for(auto child: graph[node]){
            if(!vis[child]){
                color[child] = !color[node];
                if(isbip(child,graph)==false){
                    return false;
                }
            }else if(color[child]==color[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        vis.assign(n,0);
        color.assign(n,0);
        for(auto el: graph){
            for(int i=0;i<el.size();i++){
                if(!vis[el[i]]){
                    if(isbip(el[i],graph)==false){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};