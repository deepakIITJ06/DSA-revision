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
// simply sabse pehle sabse jyada frequency ko khatm karna hai...then after storing frequency in map ...saare frequency ko priority queue me daal dein. Then uske baad ek-ek element ko decrease krke pq se pop krein and vector me store kr lein so that again u can put them in pq --> time always loop me badhega agar vector me kuch gya ho..iska mtlb saare task khatm to nahi hue----> and at the end ans me loop se bahar aakr time ko add krte rhein

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto &el: tasks) {
            mp[el]++;
        }
        priority_queue<int> pq;
        for(auto &el: mp) {
            pq.push(el.second);
        }
        int ans = 0;
        while(!pq.empty()) {
            int time = 0;
            vector<int> temp;
            for(int i=0;i<=n;i++) {
                if(!pq.empty()) {
                    if(pq.top()-1) temp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                }else {
                    if(temp.size()) {
                        time++;
                    }
                }
            }
            for(auto &el: temp) {
                if(el) {
                    pq.push(el);
                }
            }
            ans += time;
        }
        return ans;
    }
};