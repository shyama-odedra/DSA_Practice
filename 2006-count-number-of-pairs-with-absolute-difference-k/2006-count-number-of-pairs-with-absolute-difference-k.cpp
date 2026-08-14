class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int target = nums[i] + k;
            
            auto low = lower_bound(nums.begin() + i + 1, nums.end(), target);
            auto high = upper_bound(nums.begin() + i + 1, nums.end(), target);
            
            count += (high - low);
        }
        
        return count;
    }
};