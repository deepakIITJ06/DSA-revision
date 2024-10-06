#include<bits/stdc++.h>
#include <set>
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
// hame line dekhna hai ki mid increasing line pe hai ya decresing then u will find a peak
// take care of --> bottom peak (jab next and prev dono se small hoga element then --> u can go left or right both u will find a peak there)

class Solution {
public:
    // simply line ko dekhna whether my mid is on increasing or decresing line
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int low = 1;
        int high = n-2;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) {
                return mid;
            }else if(nums[mid]>nums[mid-1]) {
                // increasing line --> so go forward
                low = mid+1;
            }else if(nums[mid]<nums[mid-1]) {
                // decreasing line --> so go backward
                high = mid-1;
            }else {
                // agar bottom peak ho--> kisi direction me chale jaye, u will get a peak
                low = mid+1;
                // high = mid-1  --> this will also work
            }
        }
        return -1;
    }
};