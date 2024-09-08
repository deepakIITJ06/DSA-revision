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
    int dp[15][10010];
    int rec(int level,int target,vector<int>& coins) {
        if(target==0) {
            return 0;
        }
        if(level==coins.size()) {
            return 1e9;
        }
        if(dp[level][target]!=-1) {
            return dp[level][target];
        }
        int ans = 1e9;
        if(coins[level]<=target) {
            ans = min(1+rec(level,target-coins[level],coins),rec(level+1,target,coins));
        }else {
            ans = min(ans,rec(level+1,target,coins));
        }
        return dp[level][target]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,amount,coins);
        if(ans==1e9) return -1;
        return ans;
    }
};