#include <iostream>
#include <vector>
using namespace std;
// using recursion 

class Solution {
public:
  // using recursion / PRACTICE (REVISION)
    vector<vector<int>> ans;
    void rec(int level,vector<int>& nums,vector<int>& temp) {
        if(level==nums.size()) {
            ans.push_back(temp);
            return;
        }
        vector<int> out1 = temp;
        vector<int> out2 = temp;
        out1.push_back(nums[level]);
        rec(level+1,nums,out1);
        rec(level+1,nums,out2);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        rec(0,nums,temp);
        return ans;
    }
};

// using bit manipulation

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<(1<<n);i++) {
        vector<int> temp;
        for(int j=0;j<nums.size();j++) {
            if((i>>j)&1) { // here you can also do --> i & (1<<j)
            temp.push_back(nums[j]);
            }
        }
        ans.push_back(temp);
        }
        return ans;
    }
};