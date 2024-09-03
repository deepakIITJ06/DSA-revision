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

// simply x co-ordinate rakh lein similar to top view , ismein bss dhyan dena hai hai ki agr wo x pehle se present hai to usko DELETE kr dein then new node same x k sath map me daal dein...kyunki jo node kisi x pe sabse last me aayega wahi dikhega 

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        if(root==NULL) return {};
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()) {
            auto el = q.front(); 
            q.pop();
            Node* curNode = el.first;
            int curLevel = el.second;
            if(mp.find(curLevel)==mp.end()) {
                mp[curLevel] = curNode->data;
            }else {
                mp.erase(mp.find(curLevel));
                mp[curLevel] = curNode->data;
            }
            if(curNode->left) q.push({curNode->left,curLevel-1});
            if(curNode->right) q.push({curNode->right,curLevel+1});
        }
        vector<int> ans;
        for(auto &el: mp) {
            ans.push_back(el.second);
        }
        return ans;
    }
};
