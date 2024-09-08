#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
int mod = 1e9+7;

// 🔴🔴🔴🔴🔴🔴🔴 LOGIC 🔴🔴🔴🔴🔴🔴🔴
// pure recursion....kyunki hame saare partioning k baad ka strings print karwane hain...to each index pe jakr dekhenge ki yaha pe se partioning possible h ki nahi...sirf left wale ko palindrome banate banate...chale jayenge...if end tak pahuch gaye means--> ki saari partions aise hain jisme saare strings palindrome hein.

class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(int i,int j,string &s) {
        string t = s.substr(i,j-i+1);
        string p = t;
        reverse(begin(p),end(p));
        if(t==p) return true;
        return false;
    }
    void rec(int level,int &n,string &s,vector<string> temp) {
        if(level==n) {
            ans.push_back(temp);
            return;
        }
        for(int i=level;i<n;i++) {
            if(isPalindrome(level,i,s)) {
                temp.push_back(s.substr(level,i-level+1));
                rec(i+1,n,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        int n = s.length();
        rec(0,n,s,temp);
        return ans;
    }
};