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

// similar greedy logic to jump game -1 

// 🔴🔴🔴🔴🔴🔴🔴 LOGIC 🔴🔴🔴🔴🔴🔴🔴
// simply ham dekh rhe hein ki max kaha tak us index se pahuch sakte hein...if u reach at position jaha se u can;t move further ...then false. it will happen when u will reach at a position jaha pr maxlevel se bada index ho jaye

// jump game - 1 

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         int maxlevel = 0;
//         for(int i=0;i<n;i++) {
//             if(i>maxlevel) {
//                 return false;
//             }
//             maxlevel = max(maxlevel,i+nums[i]);
//         }
//         return true;
//     }
// };

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int jumps = 0;
        int coverage = 0;
        int lastInd = 0;
        for(int i=0;i<n;i++) {
            coverage = max(coverage,i+nums[i]);
            if(i==lastInd) {
                jumps++;
                lastInd = coverage;
                if(coverage>=n-1) {
                    break;
                }
            }
        }
        return jumps;
    }
};