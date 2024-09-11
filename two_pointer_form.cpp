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
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0;
        unordered_map<char,int> mp;
        int head = -1;
        int tail = 0;
        while(tail<n) {
            while(head+1 < n && mp[s[head+1]]==0) {
                head++;
                mp[s[head]]++;
            }
            maxi = max(maxi,head-tail+1);
            if(head>=tail) {
                mp[s[tail]]--;
                tail++;
            }else {
                tail++;
                head = tail-1;
            }
        }
        return maxi;
    }
};