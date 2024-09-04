#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int firstNode,lastNode;
        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0;i<sz;i++) {
                TreeNode* curNode = q.front().first;
                long long curLevel = q.front().second;
                q.pop();
                if(i==0) firstNode = curLevel;
                if(i==sz-1) lastNode = curLevel;
                if(curNode->left) q.push({curNode->left,2*curLevel+1});
                if(curNode->right) q.push({curNode->right,2*curLevel+2});
            }
            ans = max(ans,lastNode-firstNode+1);
        }
        return ans;
    }
};