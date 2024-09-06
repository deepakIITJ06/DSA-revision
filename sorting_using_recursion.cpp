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
    // recusrion
    void insert(vector<int> &nums,int val) {
        if(nums.size()==0 || nums.back()<=val) {
            nums.push_back(val);
            return;
        }
        int last = nums.back();
        nums.pop_back();
        insert(nums,val);
        nums.push_back(last);
    }
    void sort(vector<int> &nums) {
        if(nums.size()==0 || nums.size()==1) {
            return;
        }
        int num = nums.back();
        nums.pop_back();
        sort(nums);
        insert(nums,num);
    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums);
        return nums;
    }
};