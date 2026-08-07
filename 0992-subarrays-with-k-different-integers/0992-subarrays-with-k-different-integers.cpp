class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        auto atMostK = [&](int maxK) {
            unordered_map<int, int> count;
            int left = 0, total = 0;
            
            for (int right = 0; right < nums.size(); ++right) {
                if (count[nums[right]]++ == 0) {
                    maxK--;
                }
                while (maxK < 0) {
                    if (--count[nums[left]] == 0) {
                        maxK++;
                    }
                    left++;
                }
                total += right - left + 1;
            }
            return total;
        };

        return atMostK(k) - atMostK(k - 1);
    }
};