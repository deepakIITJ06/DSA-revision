#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
int mod = 1e9+7;

// 🔴🔴🔴🔴🔴🔴🔴 LOGIC 🔴🔴🔴🔴🔴🔴🔴
// WILL WORK FOR VERTICAL ORDER, TOP & BOTTOM  VIEW of binary tree

// simply x co-ordinate rakh lein similar to top view , ismein bss dhyan dena hai hai ki agr wo x pehle se present hai to usko DELETE kr dein then new node same x k sath map me daal dein...kyunki jo node kisi x pe sabse last me aayega wahi dikhega bottom se

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        if(root==NULL) return {};
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()) {
            auto el = q.front();
            q.pop();
            if(mp.find(el.second)==mp.end()) {
                mp[el.second] = el.first->data;
            }
            if(el.first->left) q.push({el.first->left,el.second-1});
            if(el.first->right) q.push({el.first->right,el.second+1});
        }
        vector<int> ans;
        for(auto &el: mp) {
            ans.push_back(el.second);
        }
        return ans;
    }

};
