#include <bits/stdc++.h>
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
    long long toh(int n, int from, int to, int aux) {
        // Your code here
        if(n==1){
            cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<< to <<endl;
            return 1;
        }
        long long ans = toh(n-1,from,aux,to);
        cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
        ans = ans+1; 
        ans = ans + toh(n-1,aux,to ,from);
        return ans;
    }
};