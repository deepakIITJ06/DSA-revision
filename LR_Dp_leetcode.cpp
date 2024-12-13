class Solution {
public:
    int dp[101][101];
    int rec(int i,int j,vector<int> &cuts) {
        if(i>j) {
            return 0;
        }
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        int cost = 1e9;
        for(int cut=i;cut<=j;cut++) {
            int cst = cuts[j+1]-cuts[i-1]+rec(i,cut-1,cuts)+rec(cut+1,j,cuts);
            cost = min(cost,cst);
        }
        return dp[i][j]=cost;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(begin(cuts),end(cuts));
        memset(dp,-1,sizeof(dp));
        return rec(1,c,cuts);
    }
};