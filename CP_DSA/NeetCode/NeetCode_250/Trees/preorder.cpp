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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};

        vector<int> left = preorderTraversal(root -> left);
        vector<int> right = preorderTraversal(root -> right);

        vector<int> trav;
        trav.push_back(root -> val);
        for(auto x : left) trav.push_back(x);
        for(auto x : right) trav.push_back(x);

        return trav;
    }
};