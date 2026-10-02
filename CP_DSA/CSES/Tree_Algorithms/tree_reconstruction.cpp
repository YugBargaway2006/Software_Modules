#include <bits/stdc++.h>
using namespace std;


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
    // map<int, int> pre;
    map<int, int> in;

    TreeNode* buildTreeHelper(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2) {
        if(l1 > r1) {
            return NULL;
        }
        TreeNode* node = new TreeNode();
        node->val = preorder[l1];
        int k = in[preorder[l1]];
        int s = k - l2;
        node->left = buildTreeHelper(preorder, l1+1, l1+s, inorder, l2, k-1);
        node->right = buildTreeHelper(preorder, l1+s+1, r1, inorder, k+1, r2);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++) {
            // pre[preorder[i]] = i;
            in[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, n-1, inorder, 0, n-1);

    }
};