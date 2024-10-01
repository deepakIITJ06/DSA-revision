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
// hame basically 2 halves banane hn and jisme ek half pe hm dhyan denge ki usmein kitne elements hein then ki l1<=r2 && l2<=r1 ...l1,l2,r1,r2 basically dono halves k starting points hein...jo dono array se milkar bnenge..

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2,nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0;
        int high = n1;
        while(low<=high) {
            int cnt1 = low+(high-low)/2;
            int cnt2 = (n1+n2+1)/2-cnt1;
            int l1 = (cnt1==0) ? -1e9 : nums1[cnt1-1];
            int l2 = (cnt2==0) ? -1e9 : nums2[cnt2-1];
            int r1 = (cnt1==n1) ? 1e9 : nums1[cnt1];
            int r2 = (cnt2==n2) ? 1e9 : nums2[cnt2];
            if(l1<=r2 && l2<=r1) {
                if((n1+n2)%2) {
                    return max(l1,l2);
                }else {
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
            }else if(l1>r2) {
                high = cnt1-1;
            }else {
                low = cnt1+1;
            }
        }
        return 1.0;
    }
};