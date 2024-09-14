#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MP make_pair
#define F first
#define S second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define rep(x,y) for(int i=x;i<y;i++)
using ii = pair<int,int>;
int mod = 1e9+7;

// 🔴🔴🔴🔴🔴🔴🔴 LOGIC 🔴🔴🔴🔴🔴🔴🔴
// Agar kisi bhi question me exactly k ka puche then atmost K - atmost K-1 nikaal dein...it will give you the right answer

class Solution {
public:
    int totalofK(vector<int> &nums,int k) {
        int n = nums.size();
        int ans = 0;
        int head = 0;
        int tail = 0;
        unordered_map<int,int> mp;
        while(head<n) {
            mp[nums[head]]++;
            while(tail<n && mp.size()>k) {
                mp[nums[tail]]--;
                if(mp[nums[tail]]==0) {
                    mp.erase(nums[tail]);
                }
                tail++;
            }
            ans += head-tail+1;
            head++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return totalofK(nums,k)-totalofK(nums,k-1);
    }
};