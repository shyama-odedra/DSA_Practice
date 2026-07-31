class Solution {
public:
    int countArrangement(int n) {
        vector<bool> used(n + 1, false);
        int count = 0;

        auto solve = [&](auto& self, int pos) -> void {
            if (pos > n) {
                count++;
                return;
            }

            for (int i = 1; i <= n; ++i) {
                if (!used[i] && (i % pos == 0 || pos % i == 0)) {
                    used[i] = true;
                    self(self, pos + 1);
                    used[i] = false;
                }
            }
        };

        solve(solve, 1);
        return count;
    }
};