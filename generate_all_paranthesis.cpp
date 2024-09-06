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
    vector<string> ans;
    void solve(int open,int close,string out) {
        if(open==0 && close==0) {
            ans.push_back(out);
            return;
        }
        if(open>0) {
            string out1 = out;
            out1 += '(';
            solve(open-1,close,out1);
        }
        if(open<close) {
            string out2 = out;
            out2 += ')';
            solve(open,close-1,out2);
        }
    }
    vector<string> generateParenthesis(int n) {
        string out = "";
        solve(n,n,out);
        return ans;
    }
};