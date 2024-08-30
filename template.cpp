#include<bits/stdc++.h>
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
int fc[100100];

int gcd(int a, int b){
    if(a==0 || b==0) return a^b;
    return __gcd(a,b);
}

bool is_prime(int x){
    if(x<2) return 0;
    for(int i=2; i*i<=x; i++){
        if(x%i==0) return 0;
    }
    return 1;
}

int binpow(int a, int b){
    int res = 1;
    while(b>0){
        if(b&1)
            res = (res*a)%mod;
        a=(a*a)%mod;
        b >>= 1LL;
    }
    return res;
}

void fact(){
    fc[0] = 1;
    fc[1] = 1;
    for(int i=2;i<100100;i++){
        fc[i] = (i*fc[i-1])%mod;
    }
}

int ncr(int n,int r){
    if(r==0) return 1;
    int ans = (fc[n]*binpow(fc[n-r],mod-2))%mod;
    ans = (ans*binpow(fc[r],mod-2))%mod;
    return ans;
}

int bin(int fib[],int val,int l,int r){
    int ans = -1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(fib[mid]==val){
            ans = mid;
            break;
        }else if(fib[mid]>val){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}

bool comp(ii& a,ii& b){
    return b.S>a.S;
}

// ******************************************************************************************* //

void solve(){
    int n,m,k,H;
    cin>>n>>m>>k>>H;
    vector<int> height(n);
    for(int i=0;i<n;i++) cin>>height[i];
    long long ans = 0;
    for(auto el: height){
        int req = abs(H-el);
        for(int i=1;i<=m;i++){
            int flag = 0;
            for(int j=i+1;j<=m;j++){
                if((j-i)*k==req){
                    ans++;
                    flag = 1;
                    break;
                }
            }
            if(flag==1) break;
        }
    }
    cout<<ans<<endl;
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