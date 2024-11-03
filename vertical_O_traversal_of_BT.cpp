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

// This co-ordinate method is so simple and easy to understand

// simply x rakhein then x k sath map me vector<int> rakhein, then similar to bottom and top view bss saare nodes pe jaye then us curX wale vector me curNode->data ko push kr dein ...simple and so easy

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        if(root==NULL) return {};
        map<int,vector<int>> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()) {
            auto el = q.front();
            q.pop();
            Node* curNode = el.first;
            int curX = el.second;
            mp[curX].push_back(curNode->data);
            if(curNode->left) q.push({curNode->left,curX-1});
            if(curNode->right) q.push({curNode->right,curX+1});
        }
        vector<int> ans;
        for(auto &el: mp) {
            for(auto &v: el.second) {
                ans.push_back(v);
            }
        }
        return ans;
    }
};

