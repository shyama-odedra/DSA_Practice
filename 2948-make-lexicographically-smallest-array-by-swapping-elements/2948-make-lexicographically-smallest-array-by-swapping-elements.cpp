class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> sortedNums(n);
        for (int i = 0; i < n; ++i) {
            sortedNums[i] = {nums[i], i};
        }
        sort(sortedNums.begin(), sortedNums.end());

        vector<vector<pair<int, int>>> groups;
        groups.push_back({sortedNums[0]});

        for (int i = 1; i < n; ++i) {
            if (sortedNums[i].first - sortedNums[i - 1].first <= limit) {
                groups.back().push_back(sortedNums[i]);
            } else {
                groups.push_back({sortedNums[i]});
            }
        }

        vector<int> result(n);
        for (const auto& group : groups) {
            vector<int> indices;
            for (const auto& p : group) {
                indices.push_back(p.second);
            }
            sort(indices.begin(), indices.end());

            for (size_t i = 0; i < group.size(); ++i) {
                result[indices[i]] = group[i].first;
            }
        }

        return result;
    }
};