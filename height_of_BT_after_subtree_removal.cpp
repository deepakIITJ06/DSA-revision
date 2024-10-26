#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MP make_pair
#define F first
#define S second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define rep(x,y) for(int i=x;i<y;i++)
using ii = pair<int,int>;
int mod = 1e9+7;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // node jis level pe hai , us level pr second highest and highest height kya hai wo dhundhna hai
    // Then agar highest wo node khud nahi generate kr rha then simply max_height+second/highest-1 is our ans
    int height(TreeNode* root,vector<int> &nodeHeight,vector<int> &nodeLevel,vector<vector<int>> &twoMax) {
        if(root==NULL) return 0;
        int lh = height(root->left,nodeHeight,nodeLevel,twoMax);
        int rh = height(root->right,nodeHeight,nodeLevel,twoMax);
        int level = nodeLevel[root->val];
        if(twoMax[level][0]<=1+max(lh,rh)) {
            twoMax[level][1] = twoMax[level][0];
            twoMax[level][0] = 1+max(lh,rh);
        }else if(twoMax[level][1]<=1+max(lh,rh)) {
            twoMax[level][1] = 1+max(lh,rh);
        }
        return nodeHeight[root->val]=1+max(lh,rh);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> nodeLevel(100100);
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0;i<sz;i++) {
                auto cur = q.front();
                q.pop();
                nodeLevel[cur->val] = level;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            level++;
        }
        vector<int> nodeHeight(100100,1);
        vector<vector<int>> twoMax(100100,vector<int> (2,0));
        int max_height = height(root,nodeHeight,nodeLevel,twoMax);
        // for(int i=0;i<4;i++) {
        //     cout<<twoMax[i][0]<<" "<<twoMax[i][1]<<endl;
        // }
        vector<int> ans;
        for(auto &el: queries) {
            int level = nodeLevel[el];
            int maxi = 0;
            // cout<<twoMax[level][0]<<" "<<twoMax[level][1]<<endl;
            if(twoMax[level][0]==nodeHeight[el]) {
                maxi = twoMax[level][1];
            }else {
                maxi = twoMax[level][0];
            }
            ans.push_back(maxi+level-1);
        }
        return ans;
    }
};