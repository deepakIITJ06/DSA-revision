#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
int mod = 1e9+7;

// 🔴🔴🔴🔴🔴🔴🔴 LOGIC 🔴🔴🔴🔴🔴🔴🔴
// remember one thing ki --> agar swapping hui h to x k aage wale part ko y k piche wale part se check kr dein. if swapping nahi hui then aage wale part ko aage wale part se hi check krein...if any of those combination true return krta hai that means ki swapping to hui hai...

class Solution {
public:
    map<string,bool> mp;
    bool rec(string &x,string &y) {
        // pruning
        if(x.length()!=y.length()) return false;
        // base case
        if(x==y) return true;
        if(x.length()<=1) return false;
        // caching
        string newstr = x+" "+y;
        if(mp.count(newstr)) return mp[newstr];
        int n = x.length();
        // transitions
        bool ans = false;
        string s1,s2,s3,s4;
        for(int i=1;i<n;i++) {
            // for swapping 
            s1 = x.substr(0,i);
            s2 = y.substr(n-i,i);
            s3 = x.substr(i,n-i);
            s4 = y.substr(0,n-i);
            if(rec(s1,s2) && rec(s3,s4)) {
                ans = true;
                break;
            }
            // for not swapped
            s1 = x.substr(0,i);
            s2 = y.substr(0,i);
            s3 = x.substr(i,n-i);
            s4 = y.substr(i,n-i);
            if(rec(s1,s2) && rec(s3,s4)) {
                ans = true;
                break;
            }
        }
        return mp[newstr]=ans;
    }
    bool isScramble(string s1, string s2) {
        return rec(s1,s2);
    }
};