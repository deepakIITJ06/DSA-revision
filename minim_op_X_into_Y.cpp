#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
int mod = 1e9+7;

// 🔴🔴🔴🔴🔴🔴🔴 LOGIC 🔴🔴🔴🔴🔴🔴🔴
// simple graph ki tarah soche --> at each number you have 4 choices jisse aap y tak pahuch jao

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(y>=x) {
            return y-x;
        }
        unordered_map<int,int> dist;
        unordered_map<int,bool> vis;
        queue<pair<int,int>> q;
        dist[x] = 0;
        q.push({x,0});
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            if(cur.first-1>=1 && !vis[cur.first-1]) {
                vis[cur.first-1] = true;
                dist[cur.first-1] = cur.second+1;
                q.push({cur.first-1,cur.second+1});
            }
            if(cur.first+1<=x+15 && !vis[cur.first+1]) {
                vis[cur.first+1] = true;
                dist[cur.first+1] = cur.second+1;
                q.push({cur.first+1,cur.second+1});
            }
            if(cur.first%5==0 && !vis[cur.first/5]) {
                vis[cur.first/5] = true;
                dist[cur.first/5] = cur.second+1;
                q.push({cur.first/5,cur.second+1});
            }
            if(cur.first%11==0 && !vis[cur.first/11]) {
                vis[cur.first/11] = true;
                dist[cur.first/11] = cur.second+1;
                q.push({cur.first/11,cur.second+1});
            }
        }
        return dist[y];
    }
};