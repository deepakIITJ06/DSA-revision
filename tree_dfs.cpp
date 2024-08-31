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


struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int val) {
        val = val;
        left = right = NULL;
    }
};

vector<int> subtreeCnt;
vector<int> parent;

int dfs(Node* root,int par) {
    parent[root->val] = par;
    if(root->left==NULL && root->right==NULL) {
        return subtreeCnt[root->val] = 1;
    }
    int l = dfs(root->left,root->val);
    int r = dfs(root->right,root->val);
    return (subtreeCnt[root->val] = l+r+1);
}

void solve() {
    int n;
    cin>>n;
    Node* temp = new Node(0);
    subtreeCnt.assign(n,0);
    parent.assign(n,0);
    dfs(temp,0);
}

signed main() {
    int t = 1;
    cin>>t;
    while(t--) {
        solve();
    }
}