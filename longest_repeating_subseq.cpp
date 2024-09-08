#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
int mod = 1e9+7;

class Solution {
public:
    int dp[1001][1001];
    int rec(int i,int j,string &s,string &t) {
        if(i>=s.length() || j>=t.length()) {
            return 0;
        }
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        int ans = 0;
        if(s[i]==t[j] && i!=j) {
            ans = 1+rec(i+1,j+1,s,t);
        }else {
            ans = max(rec(i+1,j,s,t),rec(i,j+1,s,t));
        }
        return dp[i][j] = ans;
    }
	int LongestRepeatingSubsequence(string s){
	    // Code here
        memset(dp,-1,sizeof(dp));
        return rec(0,0,s,s);
	}
};