#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
int mod = 1e9+7;

// important for INTERVIEW
// 🔴🔴🔴🔴🔴🔴🔴 LOGIC 🔴🔴🔴🔴🔴🔴🔴
// aage chalte jaye aur prefix sum badhate jaye agar same number pr phir se pahuch gaye iska mtlb bich me kahi to zero hua hoga---> to prefix kaha pe pehla mila tha uske just aage se iss index tak hmara length hoga

class Solution {
public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        int maxi = 0;
        unordered_map<int,int> mp;
        int prefix = 0;
        mp[0] = -1;
        for(int i=0;i<n;i++) {
            prefix += arr[i];
            if(mp.count(prefix)) {
                maxi = max(maxi,i-mp[prefix]);
            }else {
                mp[prefix] = i;
            }
        }
        return maxi;
    }
};