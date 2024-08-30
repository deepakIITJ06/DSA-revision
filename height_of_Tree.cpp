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

int findHeight(TreeNode* root) {
    if(root==NULL) {
        return 0;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return max(leftHeight,rightHeight)+1;
}


void solve(){
    int n;
    cin>>n;
    findHeight(root);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}