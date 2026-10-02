class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        int dl = diameterOfBinaryTree(root->left);
        int dr = diameterOfBinaryTree(root->right);

        return max({l + r, dl, dr});
    }
};