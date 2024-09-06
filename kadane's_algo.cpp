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
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int last = nums[0];
        int maxi = -1e9;
        for(int i=0;i<n;i++) {
            if(i==0) {
                last = nums[i];
            }else {
                last = max(last+nums[i],nums[i]);
            }
            maxi = max(maxi,last);
        }
        return maxi;
    }
};