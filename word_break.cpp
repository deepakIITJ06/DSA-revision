#include<bits/stdc++.h>
#include <set>
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
// simply like palindrome partioning - i

class Solution {
public:
    // simply like palindrome partioning
    set<string> st; // can use unordered
    int dp[303];
    bool rec(int level,int &n,string &s) {
        if(level>=n) {
            return true;
        }
        if(dp[level]!=-1) {
            return dp[level];
        }
        bool ans = false;
        for(int i=level;i<n;i++) {
            if(st.find(s.substr(level,i-level+1))!=st.end()) {
                ans |= rec(i+1,n,s);
            }
        }
        return dp[level]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &el: wordDict) {
            st.insert(el);
        }
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        return rec(0,n,s);
    }
};