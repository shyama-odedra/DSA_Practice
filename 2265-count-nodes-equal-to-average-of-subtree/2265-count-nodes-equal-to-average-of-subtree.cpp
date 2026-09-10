class Solution {
    int count = 0;

    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        auto [leftSum, leftCount] = dfs(node->left);
        auto [rightSum, rightCount] = dfs(node->right);

        int sum = leftSum + rightSum + node->val;
        int totalCount = leftCount + rightCount + 1;

        if (sum / totalCount == node->val) {
            count++;
        }

        return {sum, totalCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        count = 0;
        dfs(root);
        return count;
    }
};