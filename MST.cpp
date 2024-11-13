#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MP make_pair
#define F first
#define S second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define rep(x,y) for(int i=x;i<y;i++)
using ii = pair<int,int>;
int mod = 1e9+7;

class Solution {
public:
    vector<int> sz;
    vector<int> par;
    int find(int node) {
        if(node==par[node]) return node;
        return (par[node]=find(par[node]));
    }
    void unite(int x,int y) {
        int parX = find(x);
        int parY = find(y);
        if(parX==parY) return;
        if(sz[parX]<sz[parY]) {
            par[parX] = parY;
            sz[parY] += sz[parX];
        }else {
            par[parY] = parX;
            sz[parX] += sz[parY];
        }
    }
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        sz.resize(V,1);
        par.resize(V);
        for(int i=0;i<V;i++) {
            par[i] = i;
        }
        vector<vector<int>> edgelist;
        for(int i=0;i<V;i++) {
            for(auto &el: adj[i]) {
                vector<int> temp;
                temp.push_back(el[1]);
                temp.push_back(i);
                temp.push_back(el[0]);
                edgelist.push_back(temp);
            }
        }
        sort(edgelist.begin(),edgelist.end());
        int span = 0;
        int cnt = 0;
        for(auto &edge: edgelist) {
            if(find(edge[1])!=find(edge[2])) {
                cnt++;
                span += edge[0];
                unite(edge[1],edge[2]);
            }
            if(cnt==V-1) break;
        }
        return span;
    }
};