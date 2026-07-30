class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        std::sort(nums.begin(), nums.end());

        auto backtrack = [&](auto& self, int start) -> void {
            result.push_back(current);

            for (int i = start; i < nums.size(); ++i) {
                if (i > start && nums[i] == nums[i - 1]) continue;

                current.push_back(nums[i]);
                self(self, i + 1);
                current.pop_back();
            }
        };

        backtrack(backtrack, 0);
        return result;
    }
};