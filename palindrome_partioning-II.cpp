#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
int mod = 1e9+7;

// 🔴🔴🔴🔴🔴🔴🔴 LOGIC 🔴🔴🔴🔴🔴🔴🔴
// similar to palindrome partioning 1 usmein saari choices vector me store krna tha isme bss 1+ krke minm nikalna hai

class Solution{
public:
    bool isPalindrome(int i,int j,string &s) {
        while(i<j) {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int dp[505];
    int rec(int level,int &n,string &s) {
        if(level==n) {
            return 0;
        }
        if(dp[level]!=-1) {
            return dp[level];
        }
        int ans = 1e9;
        for(int i=level;i<n;i++) {
            if(isPalindrome(level,i,s)) {
                int cost = 1+rec(i+1,n,s);
                ans = min(ans,cost);
            }
        }
        return dp[level]=ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.length();
        memset(dp,-1,sizeof(dp));
        return rec(0,n,str)-1;

        // BOTTOM UP

        // int n = str.length();
        // vector<int> dp(n+1,0);
        // for(int i=n-1;i>=0;i--) {
        //     int ans = 1e9;
        //     for(int j=i;j<n;j++) {
        //         if(isPalindrome(i,j,str)) {
        //             ans = min(ans,1+dp[j+1]);
        //         }
        //     }
        //     dp[i] = ans;
        // }
        // return dp[0]-1;
    }
};