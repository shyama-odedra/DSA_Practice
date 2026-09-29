class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        if (root) {
            q.push({root, {0, 0}});
        }

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            TreeNode* temp = p.first;
            int row = p.second.first;
            int col = p.second.second;

            nodes[col][row].insert(temp->val);

            if (temp->left) {
                q.push({temp->left, {row + 1, col - 1}});
            }
            if (temp->right) {
                q.push({temp->right, {row + 1, col + 1}});
            }
        }

        vector<vector<int>> ans;
        ans.reserve(nodes.size());

        for (auto& [col, rowMap] : nodes) {
            ans.emplace_back();
            for (auto& [row, valSet] : rowMap) {
                ans.back().insert(ans.back().end(), valSet.begin(), valSet.end());
            }
        }
        return ans;
    }
};