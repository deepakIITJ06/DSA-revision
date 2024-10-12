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

class soln{
public:
    map<pair<int, int>, set<string>> memo;
    set<string> findLCS(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if (i == 0 || j == 0) {
            return {""};
        }
        if (memo.find({i, j}) != memo.end()) {
            return memo[{i, j}];
        }
        
        set<string> result;
        if (s[i - 1] == t[j - 1]) {
            set<string> temp = findLCS(i - 1, j - 1, s, t, dp);
            for (string str : temp) {
                result.insert(str + s[i - 1]);
            }
        } else {
            if (dp[i - 1][j] == dp[i][j]) {
                set<string> temp = findLCS(i - 1, j, s, t, dp);
                result.insert(temp.begin(), temp.end());
            }
            if (dp[i][j - 1] == dp[i][j]) {
                set<string> temp = findLCS(i, j - 1, s, t, dp);
                result.insert(temp.begin(), temp.end());
            }
        }
        memo[{i, j}] = result;
        return result;
    }
    vector<string> all_longest_common_subsequences(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        memo.clear();
        set<string> lcsSet = findLCS(n, m, s, t, dp);
        vector<string> ans(lcsSet.begin(), lcsSet.end());
        return ans;
    }
};