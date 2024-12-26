/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // recursion with memoization
    map<pair<int,int>,vector<TreeNode*>> mp;
    vector<TreeNode*> rec(int start,int end) {
        if(start>end) {
            return {NULL};
        }
        if(start==end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        if(mp.count({start,end})) {
            return mp[{start,end}];
        }
        vector<TreeNode*> ans;
        for(int i=start;i<=end;i++) {
            vector<TreeNode*> leftBST = rec(start,i-1);
            vector<TreeNode*> rightBST = rec(i+1,end);
            for(auto &l: leftBST) {
                for(auto &r: rightBST) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return mp[{start,end}]=ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return rec(1,n);
    }
};