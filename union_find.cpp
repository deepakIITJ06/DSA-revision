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

int binpow(int a, int b) {
    int res = 1;
    while(b>0){
        if(b&1) {
            res = (res*a)%mod;
        }
        a=(a*a)%mod;
        b >>= 1LL;
    }
    return res;
}

bool comp(ii& a,ii& b){
    return b.S>a.S;
}

// ******************************************************************************************* //

vector<int> parent(100100);
vector<int> Rank(100100);
vector<int> Size(100100);

void init() {
    for(int i=0;i<=100100;i++) {
        parent[i] = i;
        Rank[i] = 0;
        Size[i] = 1;
    }
}

int find(int x) {
    if(x==parent[x]) {
        return x;
    }
    return (parent[x] = find(parent[x]));
}

// Rank compression
void unionByRank(int x,int y) {
    int xParent = find(x);
    int yParent = find(y);

    if(xParent==yParent) return;
    if(Rank[xParent]<Rank[yParent]) {
        parent[xParent] = yParent;
    }else if(Rank[yParent]<Rank[xParent]) {
        parent[yParent] = xParent;
    }else {
        parent[xParent] = yParent;
        Rank[yParent]++;
    }
}

// size compression / path compression
void unionBySize(int x,int y) {
    int xParent = find(x);
    int yParent = find(y);

    if(xParent==yParent) return;
    if(Size[xParent]<Size[yParent]) {
        parent[xParent] = yParent;
        Size[yParent] += Size[xParent];
    }else {
        parent[yParent] = xParent;
        Size[xParent] += Size[yParent];
    }
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    solve();
}