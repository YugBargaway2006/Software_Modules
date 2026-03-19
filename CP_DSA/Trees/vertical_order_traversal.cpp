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
    vector<vector<int>> level;

    void verticalTraversalHelper(TreeNode* root, int x, int depth, vector<vector<pair<int, int>>>& pos, vector<vector<pair<int, int>>>& neg) {
        if(root == NULL) return;

        if(x >= 0) {
            if(x < pos.size()) {
                pos[x].push_back({depth, root->val});
            } else {
                pos.push_back({{depth,root->val}});
            }
            verticalTraversalHelper(root->left, x-1, depth+1, pos, neg);
            verticalTraversalHelper(root->right, x+1, depth+1, pos, neg);
        } else {
            cout << x << " " << root->val << endl;
            x = abs(x);
            if(x < neg.size()) {
                neg[x].push_back({depth,root->val});
            } else {
                neg.push_back({{depth,root->val}});
            }
            verticalTraversalHelper(root->left, -x-1, depth+1, pos, neg);
            verticalTraversalHelper(root->right, -x+1, depth+1, pos, neg);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<pair<int, int>>> pos, neg;
        neg.push_back({});

        verticalTraversalHelper(root, 0, 0, pos, neg);

        for(int i = neg.size()-1; i > 0; i--) {
            sort(neg[i].begin(), neg[i].end());
            level.push_back({});
            for(auto u : neg[i]) {
                level[level.size()-1].push_back(u.second);
            }
        }
        for(auto& v : pos) {
            sort(v.begin(), v.end());
            level.push_back({});
            for(auto u : v) {
                level[level.size()-1].push_back(u.second);
            }
        }

        return level;
    }
};