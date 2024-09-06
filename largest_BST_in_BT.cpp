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


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class NodeValue {
public:
    int mini, maxi, maxSize;
    NodeValue(int mini,int maxi,int maxSize) {
        this->mini = mini;
        this->maxi = maxi;
        this->maxSize = maxSize;
    }
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    NodeValue findBst(Node* root) {
        if(root==NULL) {
            return NodeValue(1e9, -1e9, 0);
        }
        auto l = findBst(root->left);
        auto r = findBst(root->right);
        
        if(root->data > l.maxi && root->data < r.mini) {
            return NodeValue(min(root->data, l.mini), max(root->data, r.maxi), l.maxSize+r.maxSize+1);
        }
        return NodeValue(-1e9,1e9,max(l.maxSize,r.maxSize));
    }
    int largestBst(Node *root)
    {
    	//Your code here
        return findBst(root).maxSize;
    }
};