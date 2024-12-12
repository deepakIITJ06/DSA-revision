class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n+1,1),mp(n+1);
        int lastIndex = 0, maxLength = 0;
        for(int i=0;i<n;i++) {
            mp[i] = i;
            for(int j=0;j<i;j++) {
                if(arr[j]<arr[i] && dp[i]<dp[j]+1) {
                    dp[i] = dp[j]+1;
                    mp[i] = j;
                }
            }
            if(dp[i]>maxLength) {
                maxLength = dp[i];
                lastIndex = i;
            }
        }
        vector<int> ans;
        while(mp[lastIndex]!=lastIndex) {
            ans.push_back(arr[lastIndex]);
            lastIndex = mp[lastIndex];
        }
        ans.push_back(arr[lastIndex]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};