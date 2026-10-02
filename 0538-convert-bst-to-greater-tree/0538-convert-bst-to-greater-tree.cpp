class Solution {
private:
    int sum = 0;
    void reverseInOrder(TreeNode* root) {
        if (!root) return;

        reverseInOrder(root->right);
        sum += root->val;
        root->val = sum;
        reverseInOrder(root->left);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        reverseInOrder(root);
        return root;
    }
};