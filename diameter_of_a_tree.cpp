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
    int maxi = 0;
    // O(N)
    int diameter(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh = diameter(root->left);
        int rh = diameter(root->right);
        maxi = max(maxi,lh+rh);
        return 1+max(lh,rh); 
    }

    // O(N^2)
    int findHeight(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        return max(leftHeight,rightHeight)+1;
    }
    void diameter2(TreeNode* root){
        if(root==NULL){
            return ;
        }
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        maxi = max(maxi,lh+rh);
        diameter2(root->left);
        diameter2(root->right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // int a = diameter(root);   ---> ✅ O(N) solution
        diameter2(root);
        return maxi;
    }
};