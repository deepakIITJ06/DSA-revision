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
    // form - 02
    int dp[1000][1000];
    int fun(int level, int curem, vector<int> &nums, int &k) {
        if (level >= nums.size()) {
            return 0;
        }
        if (dp[level][curem] != -1) {
            return dp[level][curem];
        }
        int ans = 1;
        for (int i=level+1;i<nums.size();i++) {
            if ((nums[level]+nums[i])%k==curem) {
                ans = 1+fun(i,curem,nums,k);
                break;
            }
        }
        return dp[level][curem] = ans;
    }
    int maximumLength(vector<int> &nums, int k) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j=i+1;j<nums.size();j++) {
                ans = max(ans,fun(j,(nums[i]+nums[j])%k,nums,k));
            }
        }
        return ans+1;
    }
};