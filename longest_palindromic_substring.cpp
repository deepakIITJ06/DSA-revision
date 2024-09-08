#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
int mod = 1e9+7;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int l,r;
        int maxi = 0;
        int start,end;
        for(int i=0;i<n;i++) {
            // odd length string
            l = i;
            r = i;
            while(l>=0 && r<n && s[l]==s[r]) {
                maxi = max(maxi,r-l+1);
                if((r-l+1)>=maxi) {
                    maxi = r-l+1;
                    start = l;
                    end = r;
                }
                l--;
                r++;
            }
            // even length string
            l = i;
            r = i+1;
            while(l>=0 && r<n && s[l]==s[r]) {
                maxi = max(maxi,r-l+1);
                if((r-l+1)>=maxi) {
                    maxi = r-l+1;
                    start = l;
                    end = r;
                }
                l--;
                r++;
            }
        }
        string ans = s.substr(start,end-start+1);
        return ans;
    }
};