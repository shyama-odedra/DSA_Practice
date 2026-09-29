class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        if (root) q.push({root, {0, 0}});

        while (!q.empty()) {
            auto [node, pos] = q.front();
            auto [row, col] = pos;
            q.pop();

            nodes.push_back({col, row, node->val});

            if (node->left) q.push({node->left, {row + 1, col - 1}});
            if (node->right) q.push({node->right, {row + 1, col + 1}});
        }

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;
        int last_col = INT_MIN;

        for (auto& [col, row, val] : nodes) {
            if (ans.empty() || col != last_col) {
                ans.push_back({});
                last_col = col;
            }
            ans.back().push_back(val);
        }

        return ans;
    }
};