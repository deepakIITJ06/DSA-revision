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
// basically saare columns k maxm ko jakr check krenge is that element my peak
// if not then jiss side greater elemnt mila uss side jayenge
// same can be done through row wise also

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = n-1;
        // basically saare columns k maxm ko jakr check krenge is that element my peak
        // if not then jiss side greater elemnt mila uss side jayenge
        // same can be done through row wise also
        while(low<=high) {
            int mid = low+(high-low)/2;
            int maxi = 0;
            for(int i=1;i<m;i++) {
                if(matrix[i][mid]>matrix[maxi][mid]) {
                    maxi = i;
                }
            }
            if((mid-1<0 || (mid-1>=0 && matrix[maxi][mid]>matrix[maxi][mid-1])) && (mid+1>=n || (mid+1<n && matrix[maxi][mid]>matrix[maxi][mid+1]))) {
                return {maxi,mid};
            }else if((mid-1>=0 && matrix[maxi][mid]<matrix[maxi][mid-1])) {
                high = mid-1;
            }else if((mid+1<n && matrix[maxi][mid]<matrix[maxi][mid+1])) {
                low = mid+1;
            }
        }
        return {-1,-1};
    }
};