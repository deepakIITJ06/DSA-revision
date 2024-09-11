#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
int mod = 1e9+7;

// 🔴🔴🔴🔴🔴🔴🔴 LOGIC 🔴🔴🔴🔴🔴🔴🔴
// brute force --> ki ham 1st and last store krte rhein...then ki iss difference k liye longest string kya hai----but this will take O(N^3)
// optimize
// ham maps ka vector bana lenge aur wo maps basically us index pe ending saare differences k liye kitna maximum length ho sakta hai wo store kr lenge...
// agar ham store krne gaye uske pehle jisse difference le rhein hein usme wo difference k liye element present hai iska mtlb ki ham us sequence ko increment kr sakte hein...simply ye check krke usmein agr present hua to 1 add kr dein else to 2 element k liye 2 store kr dein

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        vector<unordered_map<int,int>> dp(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                int d = nums[i]-nums[j];
                if(dp[j].count(d)) {
                    dp[i][d] = dp[j][d]+1;
                }else {
                    dp[i][d] = 2;
                }
                maxi = max(maxi,dp[i][d]);
            }
        }
        return maxi;
    }
};