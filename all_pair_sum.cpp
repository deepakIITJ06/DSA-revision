#include <iostream>
#include <vector>
using namespace std;
#define int long long

// METHOD - 01
int AllPairSum(vector<int> arr) {
    int ans = 0;
    int sum = 0;
    for(auto& el: arr) {
        ans += sum*el;
        sum += el;
    }
    return ans;
}

// METHOD - 02 (Easier one)
int AllPairSum2(vector<int> arr) {
    // this method uses mathematical logic --> (a+b+c)^2 = (a^2+b^2+c^2) - 2(ab+bc+ca)
    int sum = 0;
    int sqrSum = 0;
    for(int i=0;i<arr.size();i++) {
        sum += arr[i];
        sqrSum += arr[i]*arr[i];
    }
    int ans = (sum*sum - sqrSum)/2;
    return ans;
}


void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<AllPairSum(arr)<<endl;
    cout<<AllPairSum2(arr)<<endl;
}

signed main() {
    int t = 1;
    cin>>t;
    while(t--) {
        solve();
    }
}