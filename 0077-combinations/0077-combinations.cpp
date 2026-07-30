class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;

        auto backtrack = [&](auto& self, int start) -> void {
            if (current.size() == k) {
                result.push_back(current);
                return;
            }
            for (int i = start; i <= n - (k - current.size()) + 1; ++i) {
                current.push_back(i);
                self(self, i + 1);
                current.pop_back();
            }
        };

        backtrack(backtrack, 1);
        return result;
    }
};