#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
int mod = 1e9+7;

// 🔴🔴🔴🔴🔴🔴🔴 LOGIC 🔴🔴🔴🔴🔴🔴🔴
// simply ham ye dekh rahein hein ki is index ke baad who will die---> here level aur people[level] same nahi hein after deletion , so do not confuse with that one 
// for better visualization try one deleting the element from the array

// Recursive solution

class Solution {
public:
    int ans = -1;
    void solve(int &n, int &k,int level,vector<int> &people) {
        if(people.size()==1) {
            ans = people[0];
            return;
        }
        level = (level+k-1)%(people.size());
        people.erase(people.begin()+level);
        solve(n,k,level,people);
    }
    int findTheWinner(int n, int k) {
        if(n==1) {
            return n;
        }
        vector<int> people;
        for(int i=0;i<n;i++) {
            people.push_back(i);
        }
        solve(n,k,0,people);
        return ans+1;
    }
};

// O (N) iterative

class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        for(int i=1;i<=n;i++) {
            ans = (ans+k)%i;
        }
        return ans+1;
    }
};