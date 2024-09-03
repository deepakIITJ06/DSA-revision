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

// simply x and depth rakhein (depth for vertical order trversal) then --> jaise top view chahiye to ek x co-ordinate pr jo node sabse pehle aayega wahi top se dikhega then ek map me store kr le x,val ...aur while traversing agar wo x co-ordinate pehle se hai so don't need to change othervise wo co-ordinate and value map me daal dein.

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
