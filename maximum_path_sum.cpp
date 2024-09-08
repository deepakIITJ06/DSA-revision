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
    int rec(TreeNode* root,int &res) {
        if(root==NULL) {
            return 0;
        }
        int lr = rec(root->left,res);
        int rr = rec(root->right,res);
        int temp = max(max(lr,rr)+root->val,root->val);
        int ans = max(temp,lr+rr+root->val);
        res = max(ans,res);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int res = -1e9;
        int temp = rec(root,res);
        return res;
    }
};