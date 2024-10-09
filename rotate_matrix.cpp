#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
int mod = 1e9+7;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        reverse(begin(matrix),end(matrix));
        for(int i=0;i<n;i++) {
            for(int j=0;j<=i;j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};