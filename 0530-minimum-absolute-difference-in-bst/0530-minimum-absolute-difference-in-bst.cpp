class Solution {
    int minDiff = INT_MAX;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);

        if (prev != nullptr) {
            minDiff = min(minDiff, node->val - prev->val);
        }
        prev = node; 
        inorder(node->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};