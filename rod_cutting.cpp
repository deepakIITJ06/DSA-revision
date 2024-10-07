#include <bits/stdc++.h>
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

// 🔴🔴🔴🔴🔴🔴🔴 LOGIC 🔴🔴🔴🔴🔴🔴🔴
// simply take care ki agar level length ka cut le liya then u have only (n-level) jisme aap cut laga sakte hn

class Solution{
public:
    int dp[1001];
    int rec(int level,int &n,int price[]) {
        if(level>=n) {
            return 0;
        }
        if(dp[level]!=-1) {
            return dp[level];
        }
        int ans = 0;
        for(int i=1;i<=(n-level);i++) {
            ans = max(ans,price[i-1]+rec(level+i,n,price));
        }
        return dp[level]=ans;
    }
    int cutRod(int price[], int n) {
        //code here
        memset(dp,-1,sizeof(dp));
        return rec(0,n,price);
    }
};