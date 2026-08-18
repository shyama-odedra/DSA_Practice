class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for (int i = 0; i <= n - k; ++i) {
            unordered_set<int> unique_in_sub;
            for (int j = i; j < i + k; ++j) {
                unique_in_sub.insert(nums[j]);
            }
            for (int val : unique_in_sub) {
                freq[val]++;
            }
        }

        int ans = -1;
        for (auto& [val, count] : freq) {
            if (count == 1) {
                ans = max(ans, val);
            }
        }

        return ans;
    }
};