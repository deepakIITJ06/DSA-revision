#include <iostream>
#include <vector>
using namespace std;
#define int long long

void floydWarshal(int n,vector<vector<int> >& dist) {
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

void solve() {
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int> > dist(n,vector<int> (n,1e9));
    for(int i=0;i<e;i++) {
        int x,y,d;
        cin>>x>>y>>d;
        dist[x][y] = min(dist[x][y],d);
        dist[y][x] = min(dist[y][x],d);
    }
    
}

signed main() {
    int t = 1;
    cin>>t;
    while(t--) {
        solve();
    }
}