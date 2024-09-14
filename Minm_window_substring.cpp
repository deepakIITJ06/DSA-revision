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

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        int head = 0;
        int tail = 0;
        unordered_map<char,int> mp;
        for(auto &ch: t) {
            mp[ch]++;
        }
        int cnt = 0;
        int start = -1;
        int mini = 1e9;
        while(tail<n) {
            while(head<n && cnt<m) {
                if(mp[s[head]]>0) {
                    // cout<<head<<" ";
                    cnt++;
                }
                mp[s[head]]--;
                head++;
            }
            // cout<<head<<" ";
            if(cnt==m) {
                if(head-tail < mini) {
                    start = tail;
                    mini = head-tail;
                }
                // cout<<tail<<" "<<head<<" "<<start<<endl;
            }
            if(head>=tail) {
                mp[s[tail]]++;
                if(mp[s[tail]]>0) {
                    cnt--;
                }
                tail++;
            }else {
                tail++;
                head = tail-1;
            }
        }
        // cout<<start<<endl;
        if(start==-1) return "";
        return s.substr(start,mini);
    }
};