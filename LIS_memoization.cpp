#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
int mod = 1e9+7;

class Solution {
public:
    int dp[2525];
    int rec(int level,vector<int> &nums) {
        if(level<0) return 0;
        if(dp[level]!=-1) {
            return dp[level];
        }
        int ans = 1;
        for(int prev=0;prev<level;prev++) {
            if(nums[prev]<nums[level]) {
                ans = max(ans,1+rec(prev,nums));
            }
        }
        return dp[level] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int myans = 0;
        for(int i=0;i<nums.size();i++) {
            myans = max(myans,rec(i,nums));
        }
        return myans;
    }
};