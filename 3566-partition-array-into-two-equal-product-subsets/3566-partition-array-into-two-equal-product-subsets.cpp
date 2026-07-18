class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();

        for (int mask = 1; mask < (1 << n) - 1; ++mask) {
            long double current_product = 1;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    current_product *= nums[i];
                }
            }
            if (current_product == target) {
                long double remaining_product = 1;
                for (int i = 0; i < n; ++i) {
                    if (!((mask >> i) & 1)) {
                        remaining_product *= nums[i];
                    }
                }
                if (remaining_product == target) {
                    return true;
                }
            }
        }

        return false;
    }
};