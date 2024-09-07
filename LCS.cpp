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
    int rec(int i,int j,string &text1,string &text2) {
        if(i==text1.length() || j==text2.length()) {
            return 0;
        }
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        int ans = 0;
        if(text1[i]==text2[j]) {
            ans = max(ans,1+rec(i+1,j+1,text1,text2));
        }else {
            ans = max(rec(i+1,j,text1,text2),rec(i,j+1,text1,text2));
        }
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,text1,text2);
    }
};