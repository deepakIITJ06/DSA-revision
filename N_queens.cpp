#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;

class Solution{
public:
    vector<vector<int>> ans;
    vector<int> temp;
    bool check(int row,int col){
        for(int prow=0;prow<row;prow++){
            int pc = temp[prow];
            if(pc==col){
                return false;
            }
            if(abs(pc-col)==abs(prow-row)){
                return false;
            }
        }
        return true;
    }
    void rec(int level,int &n) {
        if(level==n) {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++) {
            if(check(level,i)) {
                temp.push_back(i);
                rec(level+1,n);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        rec(0,n);
        for(auto &v: ans) {
            for(auto &el: v) {
                el++;
            }
        }
        return ans;
    }
};