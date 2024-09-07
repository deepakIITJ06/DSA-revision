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
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftmin(n,-1);
        vector<int> rightmin(n,n);
        stack<int> st1,st2;
        for(int i=0;i<n;i++) {
            while(!st1.empty() && arr[st1.top()]>=arr[i]) {
                st1.pop();
            }
            if(!st1.empty()) leftmin[i] = st1.top();
            st1.push(i);
        }
        for(int i=n-1;i>=0;i--) {
            while(!st2.empty() && arr[st2.top()]>arr[i]) {
                st2.pop();
            }
            if(!st2.empty()) rightmin[i] = st2.top();
            st2.push(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            long long prod = ((i-leftmin[i])*(rightmin[i]-i))%mod;
            ans += (prod*arr[i])%mod;
            ans %= mod;
        }
        return ans;
    }
};