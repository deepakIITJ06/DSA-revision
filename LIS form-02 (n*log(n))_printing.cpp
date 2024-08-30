#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    // LIS in n*log(n)
    vector<int> lis;
    vector<int> insertedAt(n); // To store where this element arr[i] was placed
    for(int i=0;i<n;i++) {
        if(lis.empty() || lis.back()<arr[i]) {
            lis.push_back(arr[i]);
            insertedAt[i] = lis.size()-1;
        }else {
            auto it = lower_bound(begin(lis),end(lis),arr[i]);
            *it = arr[i];
            insertedAt[i] = it-lis.begin();
        }
    }
    // now --> ki lis me is index pe kaun sa element present that at the end
    int lastPresentAt = lis.size()-1;
    // cout<<lastPresentAt+1<<endl;
    vector<int> finalLis;
    for(int i=n-1;i>=0;i--) {
        if(insertedAt[i]==lastPresentAt) {
            finalLis.push_back(arr[i]);
            lastPresentAt--;
        }
    }
    reverse(begin(finalLis),end(finalLis));
    for(auto& el: finalLis) {
        cout<<el<<" ";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    solve();
}