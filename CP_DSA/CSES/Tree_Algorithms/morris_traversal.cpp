#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

vector<int> morristraversal(TreeNode* root) {
    vector<int> res;
    TreeNode* curr = root;

    while(curr) {
        if(!curr->left) {
            res.push_back(curr->val);
            curr = curr->right; 
        } else {
            TreeNode* pred = curr->left;

            while(pred->right && pred->right != curr) {
                pred = pred->right;
            }

            if(!pred->right) {
                pred -> right = curr;
                curr = curr -> left;
            } else {
                pred->right = NULL;
                res.push_back(curr->val);
                curr  = curr -> right;
            }
        }
    }

    return res;
}

int main(void) {

}