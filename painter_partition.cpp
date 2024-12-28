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
// simple --> Binary search on Ans
// Binary search on ans ---> aise hi somewhat likha jayega...

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int low = 1;
    int high = accumulate(begin(boards),end(boards),0); // --> don't use this, use loop for calculation sum
    int mid,painter,area,ans;
    while(low<=high) {
        mid = low+(high-low)/2;
        area = 0;
        painter = 0;
        for(auto &el: boards) {
            area += el;
            if(area==mid) {
                painter++;
                area = 0;
            }else if(area>mid) {
                if(el>mid) {
                    painter = 1e9;
                    break;
                }
                painter++;
                area = 0;
                area += el;
            }
        }
        if(area) painter++;
        if(painter<=k) {
            ans = mid;
            high = mid-1;
        }else {
            low = mid+1;
        }
    }
    return ans;
}